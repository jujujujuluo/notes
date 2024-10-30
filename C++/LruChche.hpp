#pragma
#include <iostream>
#include <unordered_map>
#include <sstream>
class Node {
public:
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
  int key;
  int value;
  Node *prev;
  Node *next;

  std::string toString() {
    std::stringstream ss;
    ss << "{ " << key << ": " << value << "}";
    return ss.str();
  }
};

class LRUCache {
public:
  explicit LRUCache(int capacity) : cap_(capacity) {
    head_ = new Node(-1, -1);
    tail_ = new Node(-1, -1);
    head_->next = tail_;
    tail_->prev = head_;
  }

  ~LRUCache() {
    release(head_);
  }

  int get(int key) {
    std::cout << "try to get " << key << " = ";
    auto it = index_.find(key);
    if (it == index_.end()) {
      return -1;
    }

    auto *node = it->second;
    attach(head_, detach(node));
    return node->value;
  }

  void put(int key, int value) {
    std::cout << "try to put " << key << " : " << value << std::endl;
    auto iter = index_.find(key);
    if (iter != index_.end()) {
      iter->second->value = value;
      attach(head_, detach(iter->second));
      return;
    }

    auto *node = new Node(key, value);
    index_[key] = attach(head_, node);

    if (index_.size() > cap_) {
      auto toDel = detach(tail_->prev);
      index_.erase(toDel->key);
      delete toDel;
    }
  }

  int size() const noexcept {
    return index_.size();
  };

  void echo() {
    Node* iter = head_->next;
    while (iter != tail_) {
      std::cout << iter->toString() << "; ";
      iter = iter->next;
    }
    std::cout << std::endl;
  }

private:
  void release(Node *head) {
    while (head) {
      Node *curr = head;
      head = head->next;
      delete curr;
    }
  }

  auto detach(Node *node) -> Node * {
    node->next->prev = node->prev;
    node->prev->next = node->next;
    return node;
  }

  auto attach(Node *head, Node *node) -> Node * {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;

    return node;    
  }
private:
  int cap_;
  Node *head_; //The longest unused
  Node *tail_; //Recently used
  std::unordered_map<int, Node*> index_;
};

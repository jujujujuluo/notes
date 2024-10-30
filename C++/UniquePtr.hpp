
#ifndef UniquePtr_H
#define UniquePtr_H
#include bitstypesFILE.h
#include cstdio
#include iostream
#include memory
#include map
#include optional
#include type_traits
#include utility
#include vector
template class T
struct defaultDeleter {
  void operator()(T p) const {
    delete p;
  }
};
template class T 
struct defaultDeleterT[] {
  void operator()(T p) const {
    delete [] p;
  }
};


templateclass T, class Deleter = defaultDeleterT
struct UniquePtr {
private 
  T m_p;
public
  UniquePtr () noexcept { m_p = nullptr; }
  explicit UniquePtr(T p) noexcept  m_p(p)  { puts(__PRETTY_FUNCTION__); }
  ~UniquePtr() noexcept { 
    if (m_p) {
      Deleter{}(m_p);
    }
    puts(__PRETTY_FUNCTION__);
  }
  UniquePtr(const UniquePtr &that) = delete;
  UniquePtr &operator = (const UniquePtr &that) = delete;

  UniquePtr(UniquePtr &&that) {
    m_p = stdexchange(that.m_p, nullptr);
    puts(__PRETTY_FUNCTION__);
  }
  UniquePtr &operator = (const UniquePtr &&that) {
    puts(__PRETTY_FUNCTION__);
    if (this != &that) {
      if (m_p) Deleter{}(m_p);
      m_p = stdexchange(that.m_p, nullptr); 
    }
  }
  
  T get() const {
    return m_p;
  }

  T realease() noexcept {
    return stdexchange(m_p, nullptr);
  }

  void reset(T p = nullptr) noexcept {
    if (m_p) Deleter{}(m_p);
    m_p = nullptr;
  }

  T &operator() const {
    return m_p;
  }
  T operator-() const {
    return m_p;
  }
};
templateclass T, class Deleter
struct UniquePtrT[], Deleter  UniquePtrT, Deleter {};

templateclass T, class ...Args
UniquePtrT makeUnique(Args&&...args) {
  return UniquePtrT(new T(stdforwardArgs(args)...));
}

templateclass T
UniquePtrT makeUniqueForOverwrite() {
  return UniquePtrT(new T);
}

#endif
## git

### 配置
``` shell
git config --global user.name "SYaoJun"
git config --global user.email "libevent@yeah.net"
```

### 命令
1. 查看版本
```shell
git --version
```
2. 克隆远程仓库到本地
```shell
git clone [地址]
```
- 可以使用ssh地址和https地址，建议使用ssh，因为ssh每次修改后需要输入用户名和密码

3. 初始化仓库
```shell
git init
```

在目录下使用后，会生成一个`.git`文件夹，需要`ls -a`才能查看到
4. 添加源文件
```shell
#表示添加当前目录下的所有文件
git add .
#添加test文件
git add src/test
```
5. 提交
```shell
git commit -m "cooment"
```
- commit 表示对提交的解释

6. 该命令用于显示工作目录和暂存区的状态
```shell
git status
```

7. 该命令用于将本地分支的更新,推送到远程主机
```shell
git push [alias] [branch]
```

8. 该命令用于从另一个存储库或本地分支获取并集成(整合)
```shell
git pull [Repository Link]
```

9. 回退到某个版本
```shell
git reset --hard xxx
```
- mixed(默认) 放入暂存区
- soft 放入工作区
- hard 清空多余文件

### 实战

- 合并冲突
  - 要把其他分支的一个新功能合并到master分支。但是两个分支都进行了修改，并且修改了共同的文件，共同的位置。
  - git merge
    - 合并之后会增加一个合并节点
  - git rebase
    - 优点：不会增加额外的合并节点
    - 缺点：看不到其他分支的流动方式。隐藏了特性的来源分支。
- 将多个提交合并成一个提交
- PR/MR

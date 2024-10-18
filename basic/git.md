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



### 实战

- 合并冲突
- 将多个提交合并成一个提交
- PR/MR

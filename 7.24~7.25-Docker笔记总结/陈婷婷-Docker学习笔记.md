Docker简介：Docker是一个用于构建运行传送应用程序的平台  build run share
https://www.docker.com/  docker下载链接
https://blog.csdn.net/Nicolecocol/article/details/136788200   note.js 下载链接
Docker的基本组成
镜像（image）：docker镜像就好比是一个模板，可以通过这个模板来创建容器服务，通过这个镜像可以创建多个容器（最终服务运行或者项目运行就是在容器中运行的）。类似于菜谱
容器（container）：docker利用容器技术，独立运行一个或者一组应用，通过镜像来创建的，启动、停止、删除、基本命令，目前就可以把这个容器理解为就是一个简易的Linux系统。类似于按照菜谱做出的菜
仓库（repository）：仓库就是存放镜像的地方，仓库分为公有仓库和私有仓库，Docker Hub（默认是国外的）、阿里云…都有容器服务器（配置镜像加速）。菜谱集
Dockerfile：构建镜像的文件 ，运行程序
- Docker是一个Client-Server结构的系统，Docker的守护进程运行在本机上（运行在后台，和mysql一样），通过Socket从客户端访问。
- DockerServer接收到Docker-Client的指令，就会执行这个命令。
Docker的常用命令
官方帮助文档：https://docs.docker.com/engine/reference/run/
镜像管理
docker image ls / docker images查看镜像 
docker search [image]  检索镜像 
docker search nginx 
docker pull [image] 拉取镜像
docker push [image] 上传镜像 
docker push geekhour/hello-docker:latest
docker save [image] -o FILE / 保存镜像 
docker save [image] > FILE 
eg.  docker save geekhour/hello-docker:latest > hello-docker.tar
docker load -i FILE 导⼊镜像
docker load -i hello-docker.tar 
docker history [image]  查看镜像历史
docker rmi [image] / docker image rm [image]删除镜像 
docker image prune 删除不再使⽤的镜像
docker import [URL/FILE]将⽂件系统导⼊为镜像
docker commit [container] [image] 从容器创建镜像
容器管理
docker create [image] 创建容器（仅创建，不运⾏
docker run [image] 创建并运⾏容器 
docker start [container] 启动容器 
docker stop [container] 停⽌容器 
docker restart [container] 重启容器 
docker ps /docker container ls 列出正在运⾏的容器 
docker ps -a /docker container ls -a 列出所有容器 
docker exec -it [container] bash / docker attach [container] 以交互模式进⼊容器 
docker export [container] -o FILE / docker export [container] > FILE 导出容器 
docker import FILE 导⼊容器快照 
docker logs [container] 查看容器⽇志 
docker rm [container] / docker container rm [container] 删除容器 
docker port [container] 查看容器端⼝映射 
docker top [container] 显示容器内进程 
docker cp [FILE] [container]:[PATH] 复制本地⽂件 到容器内的指定路径 
docker diff [container] 显示容器内的变化
docker stats [container] 显示容器资源使⽤情况
容器运⾏
语法格式：docker run [options] image [command] [arg...]
docker run --name [name] [image] 创建 运⾏并命名容器
docker run -d [image] 创建⼀个容器并后台运⾏ 
docker run -p [hostPort]:[containerPort] [image] 创建⼀个容器并指定端⼝映射 
语法格式： 
docker run -P [image] 创建⼀个容器并指定端⼝映射（随机分配） 
docker run -e [key=value] [image] 创建⼀个容器并指定环境变量 
docker run -w [PATH] [image] 创建⼀个容器并指定⼯作⽬录 
docker run -name [name] [image] 创建⼀个容器并指定容器名称 
docker run [image] [command] 创建⼀个容器并在容器中执⾏命令（交互模式） 
docker run -d -p [hostPort]:[containerPort] -e [key=value] -w [PATH] --name [name] [image] 创建⼀个容器，并指定容器名称、后台运⾏、端⼝映射、 环境变量和⼯作⽬录
docker run -it nginx:latest /bin/bash 使⽤镜像nginx:latest来启动⼀个容器， 
并在容器内执⾏交互式bash shell 
eg. 
docker run -it -p 3316:3306 -v /data:/data -d mysql:latest 创建⼀个mysql容器，后台模式启动，主机3316端⼝， 映射到容器3306端⼝，主机/data⽬录映射到容器/data⽬录，
⽹络管理
docker network ls 列出可⽤⽹络 
docker network inspect [network]查看⽹络详细信息  
docker network create [network]创建⼀个新的⽹络 
docker network rm [network] 删除⼀个⽹络 
docker network connect [network] [container] 将容器连接到⽹络 
docker network disconnect [network] [container] 将容器从⽹络断开
数据卷管理
docker volume create [volume] 创建⼀个数据卷 
docker volume ls 查看数据卷 
docker volume inspect [volume] 查看数据卷详细信息 
docker volume rm [volume] 删除数据卷 
docker volume prune 删除所有未使⽤的数据卷
插件管理
docker plugin ls 列出插件 
docker plugin install [plugin] 安装插件 
docker plugin enable [plugin] 启⽤插件 
docker plugin disable [plugin] 禁⽤插件 
docker plugin rm [plugin] 卸载插件
⽇常操作
docker info 查看docker 系统信息
docker version 查看Docker版本
docker --help 查看Docker帮助⽂档 
docker [command] --help 查看Docker命令帮助 
docker login/logout 登录/退出DockerHub 
常⽤Dockerfile指令 
FROM [base_image] 指定基础镜像，必须为Dockerfile的第⼀条指令； 
ADD  ⽤于将⽂件复制到镜像中，源可以是URL或者本地⽂件，也可 
以是⼀个压缩⽂件（⾃动解压）
COPY [--chown=<user>:<group>] [源路径] [⽬标路径]  ⽤于将⽂件拷⻉到镜像中，源只能是本地⽂件 
WORKDIR [PATH]   ⽤于指定⼯作⽬录，可以使⽤多个WORKDIR指令，如果使⽤ 
相对路径，则是相对于上⼀条WORKDIR指令所指定的⽬录 
ENV <key> <value> /  ENV <key1>=<value1> <key2>=<value2> ...    ⽤于设置环境变量 
CMD <命令> /  CMD ["可执⾏⽂件", "参数1", "参数2" ...]   ⽤于指定默认的容器主进程，每个Dockerfile中只能有⼀条CMD 指令，如果有多条，则只有最后⼀条会⽣效 
VOLUME <路径> /  VOLUME ["路径1", "路径2"...]   ⽤于定义匿名卷（持久化⽬录） 
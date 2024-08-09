# Docker学习笔记

### 概述

------

**简介**：Docker是一个用于构建、运行、传送应用程序的平台，是一种容器化的解决方案和平台

让第三方软件库和依赖包、应用程序、环境变量、配置文件、启动命令等打包在一起，以便在任何环境下都可以正确运行



**为什么要使用**：只要在开发环境中运行成功，在其他环境中（eg:测试环境）中也能运行成功

**思维导图**

![图](C:\Users\zhuo\Desktop\图.jpg)





### 体系结构图

------

![3](C:\Users\zhuo\Desktop\3.jpg)

- Docker使用Client-Server架构模式



- Docker Client和Docker Daemon之间通过Socket或RESTful API进行通信



- Docker Daemon是服务端的守护进程，负责管理Docker的各种资源，是一个后台进程，用来接收并处理来自Docker客户端的请求，然后将结果返回给客户端。（我们在终端中输入的各种Docker命令，是通过Docker客户端发送给Docker Daemon的，处理后再将结果返回给客户端，就能在终端中看到执行结果了）



- Docker Client负责向Docker Daemon发送请求，Docker Daemon收到请求后进行处理，然后将结果返回给Docker Client




### Docker与虚拟机的区别

------

**虚拟机：**

**优点**：在一定程度上实现了资源的整合，可以将一台计算机的计算能力、存储能力、网络资源分配给多个逻辑服务器，实现多台服务器的功能

**缺点**：需要占用大量的资源（CPU内存、硬盘、网络等），启动速度非常慢

![1](C:\Users\zhuo\Desktop\1.jpg)



**Docker:**

**优点**：不需要在容器中运行一个完整的操作系统，使用宿主机的操作系统，启动速度很快，可以在一台物理服务器上运行更多的容器，从而更加充分地利用服务器的资源，可减少资源的闲置和浪费

![2](C:\Users\zhuo\Desktop\2.jpg)





### 容器化和Dockerfile

------

**容器化**：将应用程序打包成容器，然后在容器中运行应用程序的过程

**Dockerfile:**是一个文本文件，里面包含一条条指令，用来告诉Docker如何来构建镜像（镜像中包括应用程序执行的所有命令，各种依赖，配置环境和运行应用程序所需要的所有内容）

**三个步骤：**

- 创建一个Dockerfile（使Docker构建应用程序镜像所需要的步骤和配置）
- 使用Dockerfile构建镜像
- 使用镜像创建和运行容器





### **基本**原理和概念

------

**镜像**：是一个只读的模板，可以用来创建容器



**容器**：是Docker的运行实例，提供了一个独立的可移植的环境，可以在这个环境中运行应用程序



**仓库**：用来存储Docker镜像的地方（Dockerhub:一个公共的Docker仓库，用来集中存储和管理Docker镜像，可下载或上传自己的镜像，可实现镜像的共享和复用）



### 实践

------

**步骤**

- 创建Dockerfile,创建镜像，启动容器

  ​

**创建Dockerfile**

- 在桌面新建文件夹，命名为HelloDocker


- 使用VScode打开此文件夹，并在此文件夹中创建一个index.js的文件


- 在此文件中输入代码（console.log("")）,使其能输出括号里的内容到控制台，在VScode中打开终端，输入（node index.js）就能看到输出的内容

​        NodeJS是一个运行时环境，他可以让我们在浏览器之外的地方运行JavaScript的代码（如果想在浏览器之外的               环境中运行JavaScript代码，则需安装NodeJS）

- 在根目录下创建一个Dockerfile的文件



**创建镜像**

- 指定一个基础的镜像，镜像是按参次结构来构建的，在这个镜像的基础上来添加应用程序

```c
FROM node:14-alpine    //14表示NodeJS的版本
                       //alpine指镜像是基于alpine这个Linux发行版来构建的
```



- 从最基础的Linux镜像开始，然后在这个镜像基础上安装NodeJS和应用程序（或直接使用NodeJS的镜像，因为这个镜像是基于Linux构建的）


- 将应用程序复制的镜像中（可以使用COPY命令来复制文件）将index.js这个文件复制到镜像的根目录下

```c
COPY source dest        //source表示源路径，相对于Dockerfile文件的路径
                         //dest表示目标路径，相对于镜像的路径

COPY index.js /index.js  //将index.js这个文件复制到镜像的根目录下可执行此命令
```



- 在镜像中运行应用程序,可以用CMD命令来运行应用程序

```c
CMD ["node","/.index.js"]          //方括号里的第一个参数表示可执行程序的名字
                                   //第二个参数表示这个可执行程序接收到的参数
    
CMD node /index.js                 //或使用此格式也行    
```

- 构建镜像

```c
docker build -t hello-docker .     //hello-docker为镜像的名字
```

- 运行

```c
docker run hello-docker   //hello-docker为镜像的名字
```









### Docker Compose

------

- 用于定义和运行多容器Docker应用程序的工具


- 使用YAML文件来配置应用程序的服务


- 一条命令即可创建并启动所有服务


- 通过一个单独的docker-compose.yaml的配置文件将一组互相关联的容器组合在一起来形成一个项目，然后使用一条命令就可以启动，停止或重建这些服务



### Docker命令

------

![hee](C:\Users\zhuo\Desktop\sheet.jpg)
---
title: Docker学习笔记
authors: pete
keywords:
  - Docker
---
# Docker学习笔记

## Docker 学习笔记
> Docker 的主要作用是确保项目的环境一致性，它将开发过程中项目所依赖的各种资源打包进容器，从而保证项目可以在任何环境中成功运行。

### Docker 的重要概念
- 镜像
   - 一个只读模板，可以用来创建容器。
   - 比喻: 类似于菜谱，用于创建具体的菜肴（容器）。
- 容器
   - Docker 的运行实例。
   - 比喻: 具体做出来的菜肴。
- 仓库
  - 用来存储 Docker 镜像的地方。
  - 比喻: 菜谱集，包含了各种不同的菜谱（镜像）。
- 关系
  - 镜像和容器之间的关系类似于 Java 中的类和实例的关系。
## Docker Hub
   > Docker Hub 提供了一个平台来查找和分享其他用户共享的镜像资源。
## 容器化
  > 将应用程序及其依赖打包成容器，并在容器中运行应用程序的过程。
## Dockerfile
- 创建: 通常在项目根目录下创建名为 Dockerfile 的文件。
- 内容: 写明构建应用程序镜像的步骤和配置。
## 实践步骤
- 编写 Dockerfile
   - 层级结构: 镜像由一系列层级构成，从最基础的运行环境开始。
   - 示例: 基于 Node.js 镜像构建:
   - ```c
     FROM node:14-alpine
     # 复制源代码到容器内
     COPY . /app
     WORKDIR /app
     # 安装依赖
     RUN npm install
     # 运行应用
     CMD ["node", "index.js"]

## 构建镜像
- docker build -t <镜像名> .

## 查看镜像
- docker images 
## 运行镜像
- docker run <镜像名>
## 下载远程镜像
- docker pull <镜像地址>

## 数据持久化
- Docker 容器中的数据默认不会持久化。
  - 解决方法: 使用 volumes 逻辑卷来持久化数据。
## Docker Compose
- 通过 docker-compose.yaml文件，将前端，后端，数据库等串联在一起，通过一个命令就能同时启动和关闭这个这些服务
## 总结
- 这份笔记包含了 Docker 的基础知识和基本操作，包括 Dockerfile 的编写、镜像的构建和运行，希望对您的学习有所帮助！
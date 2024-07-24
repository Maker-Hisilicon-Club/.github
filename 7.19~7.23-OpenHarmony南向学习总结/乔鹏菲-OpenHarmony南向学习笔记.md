# OpenHarmony 南向开发学习笔记
## 10课：
    1. 在根目录下新建文件，包括include和src，include是头文件，src是源代码  
    2. 写好代码后，还要配置build.gn
## 11课：
    1.配置build.gn按照给出的格式去写，还要配置bundle.json，
## 12课
    1. 开机动画：视频+图片 组成如果要改变改变视频和图片即可
    2. 编译大概要一万五千多个文件
## 13课
    1. 编译
## 16课
## 17课
    1. 编译命令：.py和.sh，coach的作用就是加快编译速度
    2. 
    3. 最总编译完汇集到hb.build
## 18课
    1. 主要就是python，大部分是文件路径
    2. gn对象和ninja对象是帮助编译的脚本 ，gn就是generate_ninja的缩写 
    3. 八个函数主导编译 ，最重要的是target-generate和target-compilation，因为target-generate会调用gn来生成编译脚本，而target-compilation根据生成的脚本去编译
    4. python和gn和ninja构成了整个编译体系
## 19课
    1.cmake是makefile的生成器
    2.Linux内核   
    3.python主要就是复制文件起一些辅助作用 
## 20课
    1.mkdir  + 文件名就是建立一个新文件
    2.鸿蒙所有源码都是c和c++，除了编译会用到python 
    3.一个文件源码：头文件.h和.c，还有主函数.c，编译的时候先编译头文件，再编译主函数，这是由ninja脚本来定义的，而ninja是由gn来定义的，gn就是build.gn ，每一个项目都要有.gn文件来管理所有文件 
    4.编译所需要的工具就是buildconfig中的gcc
## 22课
    1.分布式硬件：鸿蒙的后发优势
## 23课
    1.鸿蒙不再是套壳安卓
## 24课
    1.full-sdk,SDK编译出来一个副SDK，分布式硬件使用的API是系统级的API，  system-API，fullsdk是依赖于硬件的是编译后得到的
## 25课
    1.编译必须在Linux版本下，修改自动签名模板文件，要修改应用默认的权限等级，还要有前端
## 26课
    1.分布式硬件的权限
        分布式设备的认证组网权限
        设备间的数据交换权限
## 27课
    1. 分布式数据存储
    2. 代码结构：
        主界面
## 28课
    1.跨多个独立系统进行交互的方法
## 29课
    1.模块化的设计：根据不同的硬件产品会产生不同的刷机包
    2.南向开发：对原系统进行裁剪，适配自己的智能设备
    3.feature（特性）：构建不同的子系统
## 30课
    1.南向开发：做系统开发，更加底层，主要是C语言和C++，更加底层，
    2.北向开发：做应用层的开发
## 31课
    1.ninja和gn文件控制编译
# 南向开发和北向开发的区别
    南向开发：做系统开发，更加底层，主要是C语言和C++，更加底层,多和硬件打交道
    北向开发：做应用层的开发，比如前端

# 环境配置教程：
    1.打开控制面板，选择程序，在选择启用或关闭Windows功能，划到最下面，把适用于Linux和Windows子系统和虚拟机平台打上对勾，点击确定，之后重启电脑
    2.下载ubuntu（官网推荐下载20.04版）
    3.安装ubuntu
    4.还要下载Linux版本的device-tool，要和Windows上的版本保持一致，参考https://device.harmonyos.com/cn/develop/ide#download
    5.把下载好的Linux版本的device-tool，复制到ubuntu所在文件夹，可以通过pwd查看所在文件夹
    6.安装device-tool，可[参考网址](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-ide-env-ubuntu.md)
    7.配置远程连接,参考https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-ide-env-remote.md
    8.获取openharmony源码，参考https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/quick-start/quickstart-ide-import-project.md
    注：安装device-tool时候可能遇到python安装出错，参考https://blog.csdn.net/m0_69742286/article/details/133749645?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ECtr-2-133749645-blog-129569269.235%5Ev43%5Epc_blog_bottom_relevance_base2&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EBlogCommendFromBaidu%7ECtr-2-133749645-blog-129569269.235%5Ev43%5Epc_blog_bottom_relevance_base2&utm_relevant_index=3
    注：vim编辑器的使用:https://www.runoob.com/linux/linux-vim.html

## 开机动画的设置：
    动画加图片：
    动画所在位置：
```foundation/graphic/graphic_2d/frameworks/bootanimation/data/bootvideo.mp4```
    图片所在位置：
```device/rk3568/kernel/logo.bmp```

# openharmony的特点：
    1.不再是套壳安卓，完全是一个新的系统
    2.一个系统可以在多种设备上运行
    3.代码分模块，容易找到对应的模块，容易修改
# 编译：
    依靠build.gn和ninja还有gcc工具，gn对象和ninja对象是帮助编译的脚本 ，gn就是generate_ninja的缩写，python和gn和ninja构成了整个编译体系，主要就是python，大部分是文件路径，
    鸿蒙所有源码都是c和c++，除了编译会用到python 
    一个文件源码：头文件.h和.c，还有主函数.c，编译的时候先编译头文件，再编译主函数，这是由ninja脚本来定义的，而ninja是由gn来定义的，gn就是build.gn ，每一个项目都要有.gn文件来管理所有文件 
    两条命令
build命令
```./build.sh --product-name rk3568 --ccache  //（.sh换成.py也可）```
hb命令
```hb set   // 选择编译的ohos版本，硬件产品型号```
```hb build // 开始编译```

# 分布式硬件相关知识：
    分布式硬件（Distributed Hardware）是指在不同的物理位置上部署和操作的硬件组件，这些组件通过网络连接协同工作，共同完成特定的任务。在分布式硬件系统中，每个硬件节点都可以独立执行任务的一部分，同时与其它节点通信以交换数据或同步状态。
    1.分布式硬件的权限
        分布式设备的认证组网权限
        设备间的数据交换权限
    2.full-sdk,SDK编译出来一个副SDK，分布式硬件使用的API是系统级的API，  system-API，fullsdk是依赖于硬件的是编译后得到的
    3.编译必须在Linux版本下，修改自动签名模板文件，要修改应用默认的权限等级


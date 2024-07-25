# 何广远鸿蒙南向开发

## 2.Ubuntu环境搭建

### 2.1为什么要搭建Ubuntu环境

因为再windows系统中无法满足我们正常的开发需求，所以我们采取Windows+Ubuntu来开发。我们再windows端进行一些可视化的操作，再Ubuntu那边进行编译烧录和运行。

### 2.2Ubuntu环境搭建

#### 2.2.1安装Ubuntu

在文档中下载对应版本的Ubuntu和VirtualBox然后按教程配置即可。

#### 2.2.2Ubuntu环境配置

1. 执行如下命令，确认输出结果为bash。如果输出结果不是bash，请根据子步骤2，将Ubuntu shell修改为bash。 

   ```Linux
   ls -l /bin/sh
   ```

   ![zh-cn_image_0000001226764302](https://gitee.com/openharmony/docs/raw/master/zh-cn/device-dev/quick-start/figures/zh-cn_image_0000001226764302.png)

2. 打开终端工具，执行如下命令，输入密码，然后选择**No**，将Ubuntu shell由dash修改为bash。 

   ```Linux
   sudo dpkg-reconfigure dash
   ```

   ![ubuntu-dash-to-bash](https://gitee.com/openharmony/docs/raw/master/zh-cn/device-dev/quick-start/figures/ubuntu-dash-to-bash.png) 

3. 下载[DevEco Device Tool](https://gitee.com/link?target=https%3A%2F%2Fdevice.harmonyos.com%2Fcn%2Fide%23download)最新Linux版本软件包 。

4.  解压DevEco Device Tool软件包并对解压后的文件夹进行赋权。 

   1.  进入DevEco Device Tool软件包目录，执行如下命令解压软件包，其中devicetool-linux-tool-{Version}.zip为软件包名称，请根据实际进行修改。 

      ```Linux
      unzip devicetool-linux-tool-{Version}.zip
      ```

   2.  进入解压后的文件夹，执行如下命令，赋予安装文件可执行权限，其中devicetool-linux-tool-{Version}.sh请根据实际进行修改 。

      ```Linux
      chmod u+x devicetool-linux-tool-{Version}.sh
      ```

5.  执行如下命令，安装DevEco Device Tool，其中devicetool-linux-tool-{Version}.sh请根据实际进行修改。 

   ```Linux
   sudo ./devicetool-linux-tool-{Version}.sh
   ```

6.  在用户协议和隐私声明签署界面，请详细阅读用户协议和隐私声明，需签署同意用户协议和隐私声明才能进行下一步的安装，可通过键盘的上下按键进行选择。 

   ![zh-cn_image_0000001340557741](https://gitee.com/openharmony/docs/raw/master/zh-cn/device-dev/quick-start/figures/zh-cn_image_0000001340557741.png) 

7.  安装完成后，当界面输出“DevEco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。 

   ![zh-cn_image_0000001338201457](https://gitee.com/openharmony/docs/raw/master/zh-cn/device-dev/quick-start/figures/zh-cn_image_0000001338201457.png) 

## 3-4.配置远程访问环境，工程创建和源码下载

参考相关文档： [设备开发导读 (openharmony.cn)](https://docs.openharmony.cn/pages/v4.1/zh-cn/device-dev/device-dev-guide.md) 

## 5-14.后台程序

1. OpenHarmony源码下载和编译代码

   ```Linux
   repo init -u http://gitee.com/openharmony/manifest -b openharmony-4.1-release --no-repo-verify
   repo sync -c -j4
   repo forall -c'git lfs pull'
   build/prebuilts_download.sh
   ./build.sh --product-name rk3568 --ccache  #./build.sh --product-name rk3568 --target-cpu arm64 --ccache
   ```

2. OpenHarmony源码目录结构

    ![img](file:///C:\Users\ASUS\AppData\Local\Temp\QQ_1721805969038.png) 

3.第一个后台程序helloworld

我们可以建一个文件夹，例如：sample来存储我们之后要建的子系统。接着在子系统文件夹里添加我们的部件，以及其他的必须文件。具体结构如下：

 ![img](file:///C:\Users\ASUS\AppData\Local\Temp\QQ_1721811122989.png)

4. 开发步骤

   1.  创建目录，编写业务代码 

   2. 添加头文件

   3. 新建编译组织文件（BUILD.gn） [模块配置规则](https://docs.openharmony.cn/pages/v4.1/zh-cn/device-dev/subsystems/subsys-build-module.md) 

   4. 新建部件配置规则文件（bundle.json） [部件配置规则](https://docs.openharmony.cn/pages/v4.1/zh-cn/device-dev/subsystems/subsys-build-component.md) 

   5. 修改子系统配置文件(subsystem_config.json) [子系统配置规则](https://docs.openharmony.cn/pages/v4.1/zh-cn/device-dev/subsystems/subsys-build-subsystem.md) 

   6. 修改产品配置文件

      1.  3.2-Beta2之前版本 

          在productdefine/common/products/rk3568.json中添加对应的hello部件，直接添加到原有部件后即可。 

         ```
         "usb:usb_manager_native":{},
         "applications:prebuilt_hap":{},
         "sample:hello":{},
         "wpa_supplicant-2.9:wpa_supplicant-2.9":{},
         
         ```

      2.  3.2-Beta2及之后版本 

          在vendor/hihope/rk3568/config.json中添加对应的hello部件，直接添加到原有部件后即可。 

         ```
         {
           "subsystem": "sample",
           "components": [
             {
               "component": "hello",
               "features": []
             }
           ]
         },     
         
         ```

         

## 15-20.OH源码

1. OpenHarmony源码抓取

   编译开发板需要好几个小时，我们可以通过修改参数来加快编译速度。

   

2. OpenHarmony系统编译的三个入口

   ```Linux
   ./build.sh 
   ./build.py
   hb build
   ```

3. OpenHarmony系统编译的完整流程

   我们可以通过递归查找源码根目录。

   OpenHarmony开发过程中使用了编译构建工具Ninja ，类似于makefile。

   OpenHarmony开发过程中使用了GN工具，该工具可以自动创建编译脚本，简化Ninja的语法。

   OpenHarmony整个源码编译体系是通过Python+Ninja+GN构成的。

4. GN与Ninja的应用

   使用GN工具可以生成Ninja脚本，python(自动化作用)+GN（在每一个文件夹底下，建BUILD.GN，自动生成Ninja）+Ninja（告诉编译器如何编译）。

5. GN构建的样例分析

   先创建源码目录，源码文件夹下：
   source(代表要编译的源码)depens(依赖于哪些头文件)。头文件文件夹下：source(.c文件和头文件)，public(头文件名称)。在源码的根目录下面创建一个.gn文件里面放BUILDconfig = “//build/BUILDCONFIG.gn”
   BUILDCONFIG.gn里面先确定编译工具链（toolchain），再在build下建一个toolchain文件夹，gen产生ninja文件放在out文件夹。

## 21-28.画板项目

1. 什么是分布式硬件开发？

   分布式的意思就是多人、跨区域、资源共享、远程访问等特点的集合，它具有提高开发效率等优势。

2. Full-SDK（软件开发包）简介及编译过程

   Full-SDK = BaseSDK + System API

3. 

## 29-32.子系统

1. 基于GN构建的模块系统：产品、领域/子系统集、子系统、部件、组件、特性
2. 系统基本能力子系统--foundation
   增强软件服务子系统--domains
   编译构建子系统--build
   基础软件服务子系统和硬件服务子系统--base
   内核子系统--kernel
   自己创建一个子系统流程：mysample
   所有子系统都需要在build文件夹下的subsystem-config.json文件里进行登记（包括path和name）
   建两个部件hello(里面include放头文件，src放源码，build)和partA 
   建BUILD.gn和bundle.json文件
   复制模板即可
   每个要用到的部件都需要在相应的厂商和开发板型号里的config.json文件里说明一下


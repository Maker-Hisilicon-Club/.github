
图片加载不出来的话，点下面链接
https://zi9swb9smhl.feishu.cn/wiki/RSNdwYCNviDvCzku2hzckEN0neY?from=from_copylink



配置Ubuntu环境

1.下载

VirtualBox   https://www.virtualbox.org/下载最新版

Ubuntu   https://mirrors.huaweicloud.com/home ubuntu->



->20.04版本->



2.配置

1.



名称 取英文

文件夹：建议D盘新建

版本(E)   选择 下载的镜像

选择跳过自动下载

参考https://developer.huawei.com/consumer/cn/training/course/video/C101639987816176315

配置虚拟机内环境

https://developer.huawei.com/consumer/cn/training/course/video/C101639988048536240

之后打开虚拟机终端

输入：sudo dpkg-reconfigure dash，跳出页面选择NO

在虚拟机内浏览器搜索https://device.harmonyos.com/cn/ide#download ，下载Linux版本最新版DevEco Device Tool

1. 
   1. 进入DevEco Device Tool软件包目录，执行如下命令解压软件包，其中devicetool-linux-tool-{Version}.zip为软件包名称，请根据实际进行修改。
   2. unzip devicetool-linux-tool-{Version}.zip
   3. 进入解压后的文件夹，执行如下命令，赋予安装文件可执行权限，其中devicetool-linux-tool-{Version}.sh请根据实际进行修改。
   4. chmod u+x devicetool-linux-tool-{Version}.sh
2. 执行如下命令，安装DevEco Device Tool，其中devicetool-linux-tool-{Version}.sh请根据实际进行修改。
3. sudo ./devicetool-linux-tool-{Version}.sh
4. 在用户协议和隐私声明签署界面，请详细阅读用户协议和隐私声明，需签署同意用户协议和隐私声明才能进行下一步的安装，可通过键盘的上下按键进行选择。



安装完成后，当界面输出“DevEco Device Tool successfully installed.”时，表示DevEco Device Tool安装成功。

配置远程访问环境

安装SSH服务并获取远程访问的IP地址

1. 在Ubuntu系统中，打开终端工具，执行sudo apt-get install openssh-server安装SSH服务。



1.  说明： 如果执行该命令失败，提示openssh-server和openssh-client依赖版本不同，请根据CLI界面提示信息，安装openssh-client相应版本后（例如：sudo apt-get install openssh-client=1:8.2p1-4），再重新执行该命令安装openssh-server。

1. 执行sudo systemctl start ssh，启动SSH服务。
2. sudo systemctl start ssh
3. 执行ifconfig，获取当前用户的IP地址，用于Windows系统远程访问Ubuntu环境。



如果蓝框所圈的是类似于下面的数请往下执行



强制退出虚拟机，然后执行将网卡2启动，选择仅主机模式，再启动，终端输入执行ifconfig



红框为所需IP地址



打开Windows系统下的Visual Studio Code，点击



在插件市场的搜索输入框中输入“remote-ssh”。



点击Remote-SSH的Install，安装Remote-SSH。安装成功后，在INSTALLED下可以看到已安装Remote-SSH。



点击



在SSH TARGETS下，单击+。



在弹出的SSH连接命令输入框中输入“ssh username@ip_address”，其中ip_address为要连接的远程计算机的IP地址，username为登录远程计算机的帐号。



在弹出的输入框中，选择SSH configuration文件，选择默认的第一选项即可。



在SSH TARGETS中，找到远程计算机，点击



打开远程计算机。



在弹出的输入框中，选择Linux，然后在选择Continue，然后输入登录远程计算机的密码，连接远程计算机。



1.  说明： 在Windows系统远程访问Ubuntu过程中，需要频繁的输入密码进行连接，为解决该问题，您可以使用SSH公钥来进行设置，设置方法请参考注册远程访问Ubuntu环境的公钥。

下载源码

进入Home页，点击New Project创建新工程。



在新工程的配置向导页，配置工程相关信息，包括：

- OpenHarmony Source Code：选择需要下载的OpenHarmony源码，请选择OpenHarmony Stable Version下的源码版本，支持OpenHarmony-v3.0.3-LTS、OpenHarmony-v3.1-Release、OpenHarmony-v3.2-Beta3、OpenHarmony-v3.2-Beta4、OpenHarmony-v3.2-Beta5、OpenHarmony-v3.2-Release版本。
- Project Name：设置工程名称。
- Project Path：选择工程文件存储路径。
- SOC：选择支持的芯片。
- Board：选择支持的开发板。
- Product：选择产品。



工程配置完成后，点击Confirm，DevEco Device Tool会自动启动OpenHarmony源码的下载

2.Linux内终端下载





第一个程序编译

在app下新增业务my_first_app，其中hello_world.c为业务代码，BUILD.gn为编译脚本

    #include <stdio.h>
    #include "ohos_init.h"
    #include "ohos_types.h"
    void HelloWorld(void)
    {    printf("[DEMO] Hello world.\n");
    }
    SYS_RUN(HelloWorld);

编写用于将业务构建成静态库的BUILD.gn文件。

新建./applications/sample/wifi-iot/app/my_first_app下的BUILD.gn文件，并完成如下配置。

    static_library("myapp") {    sources = [        "hello_world.c"    ]    include_dirs = [        "//utils/native/lite/include"    ]}

- static_library中指定业务模块的编译结果，为静态库文件libmyapp.a

最后在build文件里面添加"my_first_app:myapp",

烧录

1. 在DevEco Device Tool中，选择REMOTE DEVELOPMENT > Local PC，查看远程计算机（Ubuntu开发环境）与本地计算机（Windows开发环境）的连接状态。
   1. 如果Local PC右边连接按钮为
   2. 
   3. ，则远程计算机与本地计算机为已连接状态，不需要执行其他操作。
   4. 如果Local PC右边连接按钮为
   5. 
   6. ，则点击绿色按钮进行连接。连接时DevEco Device Tool会重启服务，因此请不要在下载源码或源码编译过程中进行连接，否则会中断任务。



1. 在菜单栏中点击Project Settings按钮，进入Hi3861V100工程配置界面。



在“Tool Chain”页签，检查Uploader烧录器工具是否已安装。

- 如工具为“uninstalled”状态，可单击Download Uninstalled Tools，自动安装所需工具，或单击工具后方的Download安装指定工具。



1.   烧录2的upload_port要选好串口



最后烧录编译



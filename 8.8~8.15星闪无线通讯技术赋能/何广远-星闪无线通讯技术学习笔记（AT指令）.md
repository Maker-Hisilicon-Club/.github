# 何广远-星闪无线通讯技术学习笔记（AT指令）

## AT指令了解

### 1.什么是AT

- 简单来说，AT命令用于控制客户端与其他终端设备之间信息交互。

  

  ![1723194503631](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\1723194503631.png)

### 2.AT指令类型

- 可分为以下四种：

  

  ![1723194680457](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\1723194680457.png)

- 其中需要注意以下几点：
  - 不是每一条指令都具备上表中的 4 种类型的命令。 
  - 如果存在当前软件版本不支持的 AT 指令，会返回 ERROR。 
  - 双引号表示字符串数据 "string"，例如： AT+SCANSSID="XXX"。 
  - 串口通信默认：波特率为 115200、8 个数据位、 1 个停止位、无校验，无流量控 制。 
  - <>为必选参数； [ ]内为可选值，参数可选。
  - 命令中的参数以“ , ”作为分隔符，除双引号括起来的字符串参数外，不支持参数 本身 带“ ,”。
  -  AT 指令中的参数不能有多余的空格。 AT 指令必须大写，且必须以回车换行符作为结尾（CR LF ）

### 3.通用AT指令

![1723210321486](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\1723210321486.png)

### 4.SLE AT指令详述

- 介绍：SLE即为 Super Low Energy 的缩写，意为超低功耗。

1. **AT+SLEENABLE**
   - 参数：无。
   - 功能：启用SLE功能。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
2. **AT+SLESETADVPAR**
   - 参数：announce_handle（公告句柄）,     announce_mode（公告模式）, announce_interval_min（最小公告间隔）, announce_interval_max（最大公告间隔）, own_addr_type（本端地址类型）, own_addr_addr（本端地址）, peer_addr_type（对端地址类型）, peer_addr_addr（对端地址）。
   - 功能：设置SLE广播参数。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
3. **AT+SLESETADVDATA**
   - 参数：adv_handle（广播句柄）, announce_data_len（公告数据长度）, seek_rsp_data_len（扫描响应数据长度）, announce_data（公告数据）, seek_rsp_data（扫描响应数据）。
   - 功能：设置SLE广播数据。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
4. **AT+SLESTARTADV**
   - 参数：adv_enable（是否启动广播）。
   - 功能：启动SLE广播。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
5. **AT+SLESTOPADV**
   - 参数：adv_handle（广播句柄）。
   - 功能：停止SLE广播。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
6. **AT+SLESTARTSCAN**
   - 参数：无。
   - 功能：启动SLE扫描。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
7. **AT+SLESTOPSCAN**
   - 参数：无。
   - 功能：停止SLE扫描。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
8. **AT+SLESETNAME**
   - 参数：name（设备名称）。
   - 功能：设置SLE设备的名称。
   - 返回值：成功返回"OK"，失败返回"ERROR"。
9. **AT+SLEGETNAME**
   - 参数：无。
   - 功能：获取SLE设备的名称。
   - 返回值：成功返回设备名称，失败返回"ERROR"。
10. **AT+SLESETADDR**
    - 参数：addr_type（地址类型）, addr（设备地址）。
    - 功能：设置SLE设备的地址。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
11. **AT+SLEGETADDR**
    - 参数：无。
    - 功能：获取SLE设备的地址。
    - 返回值：成功返回设备地址，失败返回"ERROR"。
12. **AT+SLECONN**
    - 参数：sle_addr_type（SLE地址类型）, sle_addr（SLE地址）。
    - 功能：建立SLE连接。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
13. **AT+SLEDISCONN**
    - 参数：sle_addr_type（SLE地址类型）, sle_addr（SLE地址）。
    - 功能：断开SLE连接。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
14. **AT+SLESETPHY**
    - 参数：conn_id（连接ID）, tx_phy（发送PHY）, rx_phy（接收PHY）。
    - 功能：设置SLE连接的物理层参数。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
15. **AT+SLEDEFAULTCONN**
    - 参数：enable_filter_policy（是否启用过滤策略）, initiate_phys（发起物理参数）, gt_negotiate（是否进行GT协商）, scan_interval（扫描间隔）, scan_window（扫描窗口）, max_interval（最大连接间隔）, min_interval（最小连接间隔）, timeout（超时时间）。
    - 功能：设置SLE的默认连接参数。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
16. **AT+SLEPAIR**
    - 参数：sle_addr_type（地址类型）, sle_addr（地址）。
    - 功能：进行SLE加密配对。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
17. **AT+SLEUNPAIR**
    - 参数：sle_addr_type（地址类型）, sle_addr（地址）。
    - 功能：移除SLE加密配对。
    - 返回值：成功返回"OK"，失败返回"ERROR"。
18. **AT+SLEGETPAIREDNUM**
    - 参数：无。
    - 功能：获取配对设备的数量。
    - 返回值：成功返回配对设备数量，失败返回"ERROR"。
19. **AT+SLEGETPAIRDEV**
    - 参数：无。
    - 功能：获取配对设备的列表。
    - 返回值：成功返回配对设备信息，失败返回"ERROR"。
20. **AT+SLEGETPAIRSTA**
    - 参数：sle_addr_type（地址类型）, sle_addr（地址）。
    - 功能：获取设备的配对状态。
    - 返回值：成功返回配对状态，失败返回"ERROR"。

21.**AT+SLEGETBONDDEV**

- 参数：无。	
- 功能：获取绑定设备的列表。
- 返回值：成功返回绑定设备信息，失败返回"ERROR"。

22.**AT+SLECONNPARUPD**

- 参数：conn_id（连接ID）, interval_min（  链 路 调 度 最 小 间 隔 ， 取 值 范 围 [0x0002, 0x32000]，单位 125μs ）, interval_max（ ： 链 路 调 度 最 大 间 隔 ， 取 值 范 围 [0x0002, 0x32000]，单位 125μs ）, max_latency（最大延迟）, supervision_timeout（超时时间）。
- 功能： 星闪逻辑链路更新参数 。
- 返回值：成功返回"OK"，失败返回"ERROR"。

23.**AT+SLEREADPEERRSSI**

- 参数：conn_id（连接ID）。
- 功能：读取对端设备的RSSI值。
- 返回值：成功返回"OK"，失败返回"ERROR"。

24.**AT+SSAPSADDSRV**

- 参数：uuid（通识唯一识别码）。
- 功能：注册SSAPS服务。
- 返回值：成功返回"OK"，失败返回"ERROR"。

25.**AT+SSAPSDELALLSRV**

- 参数：无。
- 功能：删除所有SSAPS服务。
- 返回值：成功返回"OK"，失败返回"ERROR"。

26.**AT+SSAPSADDSERV**

- 参数：uuid（通识唯一识别码）, is_primary（是否为主要服务）。
- 功能：添加SSAPS服务。
- 返回值：成功返回"OK"，失败返回"ERROR"。

27.**AT+SSAPSSYNCADDSERV**

- 参数：同AT+SSAPSADDSERV。
- 功能：同步添加SSAPS服务。
- 返回值：成功返回"OK"，失败返回"ERROR"。

28.**AT+SSAPSADDPROPERTY**

- 参数：service_handle（服务句柄通识唯一识别码）, uuid（通识唯一识别码）,permissions（特征权限）, operate_indecation（操作指示）, value_len（值长度）, value（值）。
- 功能：添加SSAPS属性。
- 返回值：成功返回"OK"，失败返回"ERROR"。

29.**AT+SSAPSSYNCADDPROPERTY**

- 参数：同AT+SSAPSADDPROPERTY。
- 功能：同步添加SSAPS属性。
- 返回值：成功返回"OK"，失败返回"ERROR"。

30.**AT+SSAPSADDDESCR**

- 参数：service_handle（服务句柄）,property_handle（属性句柄）, uuid（描述符UUID）,permissions（权限）, operate_indecation（操作指示）, type（类型）,  value_len（值长度）, value（值）。
- 功能：添加SSAPS属性描述符。
- 返回值：成功返回"OK"，失败返回"ERROR"。

31.**AT+SSAPSSYNCADDDESCR**

- 参数：同AT+SSAPSADDDESCR。
- 功能：同步添加SSAPS属性描述符。
- 返回值：成功返回"OK"，失败返回"ERROR"。

32.**AT+SSAPSSTARTSERV**

- 参数：service_handle（服务句柄）。
- 功能：启动SSAPS服务。
- 返回值：成功返回"OK"，失败返回"ERROR"。

33.**AT+SSAPSSNDNTFY**

- 参数：conn_id（连接ID）, handle（属性句柄）, type（类型）(0-5,0表示特征值；1表示属性说明描述符；2表示客户端配置描述符；3表示服务端配置描述符；4表示格式描述符；5表示服务管理描述管理符，取值0x05-0x1F), value_len（值长度）, value（值）。
- 功能：服务端向客户端发送通知。
- 返回值：成功返回"OK"，失败返回"ERROR"。

34.**AT+SSAPSNTFYBYUUID**

- 参数：conn_id（连接ID）, uuid（属性UUID）, start_hdl（开始句柄）, end_hdl（结束句柄）, type（类型）(0-5,0表示特征值；1表示属性说明描述符；2表示客户端配置描述符；3表示服务端配置描述符；4表示格式描述符；5表示服务管理描述管理符，取值0x05-0x1F), value_len（值长度）, value（值）。
- 功能：服务端通过UUID向客户端发送通知。
- 返回值：成功返回"OK"，失败返回"ERROR"。

35.**AT+SSAPSSNDRESP**

- 参数：conn_id（连接ID）, request_id（请求ID）, status（状态）, value_len（值长度）, value（值）。
- 功能：服务端向客户端发送响应。
- 返回值：成功返回"OK"，失败返回"ERROR"。

36.**AT+SSAPSREGCBK**

- 参数：无。
- 功能：服务端注册回调函数。
- 返回值：成功返回"OK"，失败返回"ERROR"。

37.**AT+SSAPCREGCBK**

- 参数：无。
- 功能：客户端注册回调函数。
- 返回值：成功返回"OK"，失败返回"ERROR"。

38.**AT+SSAPCFNDSTRU**

- 参数：client_id（客户端ID）, conn_id（连接ID）, type（客户端类型，取值为0/1/3）, handle(连接句柄）, start_hdl(开始句柄)，end_hdl（结束句柄）。
- 功能：客户端发现服务结构。
- 返回值：成功返回"OK"，失败返回"ERROR"。

39.**AT+SSAPCWRITECMD**

- 参数：client_id（客户端ID）, conn_id（连接ID）, type（客户端类型，取值为0/1/3）, handle(连接句柄）, len（写入数据长度）, write_data（写入数据）。
- 功能：客户端向服务端写入数据。
- 返回值：成功返回"OK"，失败返回"ERROR"。

40.**AT+SSAPCWRITEREQ**

- 参数：同AT+SSAPCWRITECMD。
- 功能：客户端向服务端发送写请求。
- 返回值：成功返回"OK"，失败返回"ERROR"。

41.**AT+SSAPCEXCHINFO**

- 参数：client_id（客户端ID）, conn_id（连接ID）,  mtu_size（MTU(最大传输单元)大小）, version（版本号）。
- 功能：客户端发起信息交换。
- 返回值：成功返回"OK"，失败返回"ERROR"。

42.**AT+SSAPCREADBYUUID**

- 参数：client_id（客户端ID）, conn_id（连接ID）, type（客户端类型，取值为0/1/3）, handle(连接句柄）, start_hdl(开始句柄)，end_hdl（结束句柄）。
- 功能：客户端通过UUID发送读请求。
- 返回值：成功返回"OK"，失败返回"ERROR"。

43.**AT+SSAPCREADREQ**

- 参数：client_id（客户端ID，预留参数）, conn_id（连接ID）,  handle(连接句柄）, type（类型，取值0/1/3）。
- 功能：客户端读取服务端属性数据。
- 返回值：成功返回"OK"，失败返回"ERROR"。
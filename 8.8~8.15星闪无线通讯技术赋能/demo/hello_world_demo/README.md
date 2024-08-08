# OLED显示hello world实验<a name="ZH-CN_TOPIC_0000001130176841"></a>


## 一、I2C API

| API名称                                                      | 说明                            |
| ------------------------------------------------------------ | ------------------------------- |
| I2cInit (WifiIotI2cIdx id, unsigned int baudrate)            | 用指定的波特速率初始化I2C设备   |
| I2cDeinit (WifiIotI2cIdx id)                                 | 取消初始化I2C设备               |
| I2cWrite (WifiIotI2cIdx id, unsigned short deviceAddr, const WifiIotI2cData *i2cData) | 将数据写入I2C设备               |
| I2cRead (WifiIotI2cIdx id, unsigned short deviceAddr, const WifiIotI2cData *i2cData) | 从I2C设备中读取数据             |
| I2cWriteread (WifiIotI2cIdx id, unsigned short deviceAddr, const WifiIotI2cData *i2cData) | 向I2C设备发送数据并接收数据响应 |
| I2cRegisterResetBusFunc (WifiIotI2cIdx id, WifiIotI2cFunc pfn) | 注册I2C设备回调                 |
| I2cSetBaudrate (WifiIotI2cIdx id, unsigned int baudrate)     | 设置I2C设备的波特率             |

## 二、ssd1306 API

| API名称                                                      | 说明                       |
| ------------------------------------------------------------ | -------------------------- |
| void ssd1306_Init(void)                                      | 初始化                     |
| void ssd1306_Fill(SSD1306_COLOR color)                       | 以指定的颜色填充屏幕       |
| void ssd1306_SetCursor(uint8_t x, uint8_t y)                 | 定位光标                   |
| void ssd1306_UpdateScreen(void)                              | 更新屏幕内容               |
| char ssd1306_DrawChar(char ch, FontDef Font, SSD1306_COLOR color) | 在屏幕缓冲区绘制1个字符    |
| char ssd1306_DrawString(char* str, FontDef Font, SSD1306_COLOR color) | 将完整字符串写入屏幕缓冲区 |
| void ssd1306_DrawPixel(uint8_t x, uint8_t y, SSD1306_COLOR color) | 在屏幕缓冲区中绘制一个像素 |
| void ssd1306_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color) | 用Bresenhem算法画直线      |
| void ssd1306_DrawPolyline(const SSD1306_VERTEX *par_vertex, uint16_t par_size, SSD1306_COLOR color) | 绘制多段线                 |
| void ssd1306_DrawRectangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, SSD1306_COLOR color) | 绘制矩形                   |
| void ssd1306_DrawArc(uint8_t x, uint8_t y, uint8_t radius, uint16_t start_angle, uint16_t sweep, SSD1306_COLOR color) | 绘图角度                   |
| void ssd1306_DrawCircle(uint8_t par_x, uint8_t par_y, uint8_t par_r, SSD1306_COLOR color) | 用Bresenhem算法画圆        |
| void ssd1306_DrawBitmap(const uint8_t* bitmap, uint32_t size) | 绘图位图                   |
| void ssd1306_DrawRegion(uint8_t x, uint8_t y, uint8_t w, uint8_t h, const uint8_t* data, uint32_t size, uint32_t stride) | 绘制区域                   |

## 三、如何编译

1. 将hello_world_demo目录复制到本地openharmony源码的applications\sample\wifi-iot\app目录下

2. 修改openharmony的`applications\sample\wifi-iot\app\BUILD.gn`文件：
   * 将其中的 features 改为：
   ```
    features = [
        "hello_world_demo:helloWorld",
    ]
   ```

3. 修改`device\soc\hisilicon\ws63v100\sdkv100\libs_url\ws63\cmake\ohos.cmake`文件添加 `"helloWorld"`，如下：
    ```
    elseif(${TARGET_COMMAND} MATCHES "ws63-liteos-app")
    set(COMPONENT_LIST "begetutil"   "hilog_lite_static" "samgr_adapter" "bootstrap" "fsmanager_static" "hal_update_static" "hilog_static" "inithook"   "samgr_source"
            "broadcast" "hal_file_static"   "init_log"  "native_file" "udidcomm"
            "cjson_static" "hal_sys_param" "hichainsdk" "hota" "init_utils"  "param_client_lite"
            "hiview_lite_static" "hal_sysparam" "hievent_lite_static" "huks_3.0_sdk"   "samgr" "blackbox_lite" "hal_iothardware" "wifiservice"
            "hidumper_mini" "helloWorld")
    endif()
    ```

4. 修改`device\soc\hisilicon\ws63v100\sdkv100\build\config\target_config\ws63\config.py`文件在`'ws63-liteos-app'`中`'ram_component': []'`添加 `"helloWorld"`，如下：
   ```
       'ws63-liteos-app': {
        'base_target_name': 'target_ws63_app_rom_template',
        'os': 'liteos',
        'defines': [
            ......
        ],
        'ram_component': [
            .......
            'xo_trim_port',
            "mqtt",
            "helloWorld"
        ],
        'ccflags': [
            "-DBOARD_ASIC", '-DPRE_ASIC',
        ],
        'application': 'application',
        'bin_name': 'ws63-liteos-app',
        'smaller': True,
        'hso_enable_bt': True,
        'hso_enable': True,
        'codesize_statistic': True,
        'nv_update':True,
        'generate_efuse_bin': True,
        'copy_files_to_interim': True
    },
   ```
5. 在openharmony源码目录下执行：`hb build -f`


## 四、编译错误解决
```
本项目代码使用了鸿蒙IoT硬件子系统的I2C API接口，需要连接到hi3863的I2C相关接口；默认情况下，Hi3863的I2C编译配置没有打开，需要在`~/device/soc/hisilicon/ws63v100/sdkv100`目录下，运行`"python3 build.py -c ws63-liteos-app menuconfig"`脚本, Menuconfig 程序启动后，可通过 Menuconfig 对编译和系统功能进行配置：
切换到Drivers ---> Drivers --->I2C I2C Configuration ,选中I2C SUPPORT MASTER和Using I2C V150，退出并保存
```

## 五、运行结果

烧录文件后，按下reset按键，会发现oled显示helloworld

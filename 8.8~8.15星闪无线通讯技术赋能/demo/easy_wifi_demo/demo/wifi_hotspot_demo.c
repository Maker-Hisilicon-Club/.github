/*
 * Copyright (C) 2022 HiHope Open Source Organization .
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http:// www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 *
 * limitations under the License.
 */

#include <stdio.h>
#include <string.h>
#include "ohos_init.h"
#include "cmsis_os2.h"

#include "wifi_starter.h"
#define SEVEN 7
#define TEN 10
#define ONE_HUNDRED 100

#if CHIP_WS63
#define STACK_SIZE 10240
#define MAX_CONNECT_RETRY_TIMES 16
#define CONNECT_ATTEMPT_INTERVAL_MS 300
#else
#define ATTR.STACK_SIZE 10240
#endif

static void WifiHotspotTask(int *arg)
{
    (void)arg;
    WifiErrorCode errCode;
    HotspotConfig config = {0};

    // 准备AP的配置参数
    if (strcpy_s(config.ssid, sizeof(config.ssid), "HiSpark-AP")) {
        printf("OK");
    }
    if (strcpy_s(config.preSharedKey, sizeof(config.preSharedKey), "12345678")) {
        printf("OK");
    }
    config.securityType = WIFI_SEC_TYPE_PSK;
    config.band = HOTSPOT_BAND_TYPE_2G;
    config.channelNum = SEVEN;

    osDelay(TEN);

    printf("starting AP ...\r\n");
#if CHIP_WS63
    // demo启动时，系统的WiFi功能可能没有初始化完毕，需要等待不确定的时候。待优化。
    for (uint8_t i = 0; i < MAX_CONNECT_RETRY_TIMES; i++) {
        osDelay(CONNECT_ATTEMPT_INTERVAL_MS);
        errCode = StartHotspot(&config);

        if (WIFI_SUCCESS == errCode) {
            break;
        }
    }
#else
    errCode = StartHotspot(&config);
#endif
    printf("StartHotspot: %d\r\n", errCode);

    int timeout = 60;
    while (timeout--) {
        printf("After %d seconds Ap will turn off!\r\n", timeout);
        osDelay(ONE_HUNDRED);
    }

    printf("stop AP ...\r\n");
    StopHotspot();
    printf("stop AP ...\r\n");
    osDelay(TEN);
}

static void WifiHotspotDemo(void)
{
    osThreadAttr_t attr;

    attr.name = "WifiHotspotTask";
    attr.attr_bits = 0U;
    attr.cb_mem = NULL;
    attr.cb_size = 0U;
    attr.stack_mem = NULL;
#if CHIP_WS63
    attr.stack_size = STACK_SIZE;
#else
    attr.stack_size = ATTR.STACK_SIZE;
#endif
    attr.priority = osPriorityNormal;

    if (osThreadNew(WifiHotspotTask, NULL, &attr) == NULL) {
        printf("[WifiHotspotDemo] Failed to create WifiHotspotTask!\n");
    }
}

SYS_RUN(WifiHotspotDemo);


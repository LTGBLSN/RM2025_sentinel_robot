//
// Created by 21481 on 2025/8/30.
//

#ifndef BUBING_RM2025_AUTO_AIM_H
#define BUBING_RM2025_AUTO_AIM_H

#include <stdbool.h>
#include "main.h"


extern uint8_t nav_uart_rx_data;                   // 串口单字节接收变量
extern struct NavReceivePacket nav_rx_packet;      // 最终解析出来的速度数据

#pragma pack(1)
struct NavReceivePacket {
    uint8_t header;   // 0x9A
    float vx;         // 线速度 x
    float vy;         // 线速度 y
    float wz;         // 角速度 z
    uint8_t footer;   // 0x1B
};
#pragma pack()


// 状态定义
#define RX_STATE_WAIT_HEADER 0
#define RX_STATE_RECEIVING   1


void nav_communication_data_parse(uint8_t rx_data);

#endif //BUBING_RM2025_AUTO_AIM_H

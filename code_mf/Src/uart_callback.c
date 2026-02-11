//
// Created by 21481 on 2025/3/18.
//
#include "main.h"
#include "cmsis_os.h"
#include "can.h"
#include "dma.h"
#include "usart.h"
#include "gpio.h"

#include <stdio.h>
#include "board_LED.h"
#include "uart_printf.h"
#include "uart_sent.h"
#include "bsp_rc.h"
#include "remote_control.h"
#include "get_rc.h"
#include "bsp_can.h"
#include "CAN_receive.h"
#include "jy61p.h"
#include "auto_aim.h"


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
    if (huart == &huart1)
    {

        nav_communication_data_parse(nav_uart_rx_data);


        HAL_UART_Receive_DMA(&huart1, &nav_uart_rx_data, 1);//继续进行中断接收



    }
}







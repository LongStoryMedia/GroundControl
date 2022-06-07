/**
 ******************************************************************************
 * @file    Font12.c
 * @author  MCD Application Team
 * @version V1.0.0
 * @date    18-February-2014
 * @brief   This file provides text Font12 for STM32xx-EVAL's LCD driver.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2014 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *      without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "fonts.h"

//
//  Font data for Courier New 12pt
//

const CH_CN Font12CN_Table[] =
    {
        /*--  ����:  a  --*/
        /*--  ΢���ź�12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x21   --*/
        {{"a"}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x67, 0x00, 0x07, 0x80, 0x0F, 0x80, 0x7F, 0x80, 0xE3, 0x80, 0xE7, 0x80, 0xE7, 0x80, 0x7F, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},

        /*--  ����:  b  --*/
        /*--  ΢���ź�12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x21   --*/
        {{"b"}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x70, 0x00, 0x7F, 0x00, 0x7B, 0x80, 0x71, 0xC0, 0x71, 0xC0, 0x71, 0xC0, 0x71, 0xC0, 0x71, 0xC0, 0x7B, 0x80, 0x7F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},

        /*--  ����:  c  --*/
        /*--  ΢���ź�12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x21   --*/
        {{"c"}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x00, 0x73, 0x00, 0xF0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xE0, 0x00, 0xF0, 0x00, 0x73, 0x00, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},

        /*--  ����:  A  --*/
        /*--  ΢���ź�12;  �������¶�Ӧ�ĵ���Ϊ����x��=16x21   --*/
        {{"A"}, {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x1F, 0x00, 0x3B, 0x80, 0x3B, 0x80, 0x71, 0x80, 0x7F, 0xC0, 0x71, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}},
};

cFONT Font12CN = {
    Font12CN_Table,
    sizeof(Font12CN_Table) / sizeof(CH_CN), /*size of table*/
    11,                                     /* ASCII Width */
    16,                                     /* Width */
    21,                                     /* Height */
};

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
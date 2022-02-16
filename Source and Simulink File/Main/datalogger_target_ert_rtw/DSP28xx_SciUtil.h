/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DSP28xx_SciUtil.h
 *
 * Code generated for Simulink model 'datalogger_target'.
 *
 * Model version                  : 1.25
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Wed Feb 16 12:58:16 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DSP28xx_SciUtil_h_
#define RTW_HEADER_DSP28xx_SciUtil_h_
#include "f28004x_device.h"
#include <string.h>
#define NOERROR                        0                         /* no error*/
#define TIMEOUT                        1                         /* waiting timeout*/
#define DATAERR                        2                         /* data error (checksum error)*/
#define PRTYERR                        3                         /* parity error*/
#define FRAMERR                        4                         /* frame error*/
#define OVRNERR                        5                         /* overrun error*/
#define BRKDTERR                       6                         /* brake-detect error*/
#define RCVMAXRETRY                    10
#define RCVMAXCNTS                     1000
#define RCVMAXCNTL                     50000
#define SHORTLOOP                      0
#define LONGLOOP                       1

void scia_xmit(char* pmsg, int msglen, int typeLen);
int scia_rcv(unsigned int *rcvBuff, int buffLen, int loopMode, int typeLen);
int byteswap_L8cmp(unsigned int* outdata, char* recdata, int inportWidth, int
                   typeLen);

#endif                                 /* RTW_HEADER_DSP28xx_SciUtil_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

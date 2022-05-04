/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: DSP28xx_SciUtil.c
 *
 * Code generated for Simulink model 'genpath_firmware'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr  7 11:34:15 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "DSP28xx_SciUtil.h"

/* Transmit character(s) from the SCIa*/
int scia_xmit(char* pmsg, int msglen, int typeLen)
/*Blocking mode*/
{
  int i,j;
  if (typeLen==1) {
    for (i = 0; i < msglen; i++) {
      while (SciaRegs.SCIFFTX.bit.TXFFST == 16) {
      }                                /* The buffer is full;*/

      SciaRegs.SCITXBUF.bit.TXDT = pmsg[i];
    }
  } else {
    for (i = 0; i < (msglen/2); i++) {
      for (j = 0; j<=1; j++) {
        while (SciaRegs.SCIFFTX.bit.TXFFST == 16) {
        }                              /* The buffer is full;*/

        SciaRegs.SCITXBUF.bit.TXDT = pmsg[i]>>(8*j);
      }
    }
  }

  return 0;
}

/*
 * Receive character(s) from the SCIa
 * Received character(s) will be write to rcvBuff.
 * Return 0 if characters are received with no error.
 * Return 1 if waiting timeout.
 * Return 2 if data error.(receiving timout or checksum error)
 * Return 3 if a parity error occured.
 * Return 4 if a frame error occured.
 */
int scia_rcv(unsigned int *rcvBuff, int buffLen, int typeLen)
{
  int i;
  int errorVal = NOERROR;
  unsigned int byte_cnt = 0;
  Uint32 elapsedTimeCnt, startTimeCnt, currentTimeCnt;
  unsigned int BlockingModeTimeoutCnt = 1.75E+6;
  for (i = 0; i<buffLen; i++) {
    startTimeCnt = ReadCpuTimer2Counter();
    elapsedTimeCnt = 0;
    while (SciaRegs.SCIFFRX.bit.RXFFST == 0) {
      /* wait until data received */
      currentTimeCnt = (ReadCpuTimer2Counter());
      if (currentTimeCnt <= startTimeCnt) {
        elapsedTimeCnt = (Uint32)(startTimeCnt - currentTimeCnt);
      } else {
        elapsedTimeCnt = (Uint32)(0xFFFFFFFF + startTimeCnt - currentTimeCnt);
      }

      if (elapsedTimeCnt >= BlockingModeTimeoutCnt) {
        return TIMEOUT;
      }
    }

    if (typeLen > 1) {
      if (byte_cnt == 0) {
        rcvBuff[i/2] = (SciaRegs.SCIRXBUF.all & 0x00FF);
        byte_cnt = 1;
      } else {
        rcvBuff[i/2] |= SciaRegs.SCIRXBUF.all << 8;
        byte_cnt = 0;
      }
    } else {
      rcvBuff[i] = SciaRegs.SCIRXBUF.all;
    }

    //check flags
    if (SciaRegs.SCIFFRX.bit.RXFFOVF == 1)/* detect FIFO overflow*/
    {
      SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;

      /*SciaRegs.SCIFFRX.bit.RXFIFORESET = 0;    Reset the FIFO pointer to zero.
       * SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;   Re-enable receive FIFO operation.
       */
    }

    if (SciaRegs.SCIRXST.bit.FE)
      errorVal = FRAMERR;
    if (SciaRegs.SCIRXST.bit.PE)
      errorVal = PRTYERR;
    if (SciaRegs.SCIRXST.bit.OE)
      errorVal = OVRNERR;
    if (SciaRegs.SCIRXST.bit.BRKDT)
      errorVal = BRKDTERR;
    if (SciaRegs.SCIRXST.bit.RXERROR == 1) {
      SciaRegs.SCICTL1.bit.SWRESET = 1;
      SciaRegs.SCICTL1.bit.SWRESET = 0;
      SciaRegs.SCICTL1.bit.SWRESET = 1;
    }
  }

  return errorVal;
}

/*
 * Receive character(s) from the SCIa
 * Received character(s) will be write to rcvBuff.
 * Receive data until tail is receives.
 * Once first byte of tail matches with received byte start tailCount
 * If in between tail byte is not matching with received byte then reset tailCount
 * When tailCount becomes equal to tailSize then update rcvBufferLen with received number of bytes, check forFlags and exit.
 *
 *
 * Return 0 if characters are received with no error.
 * Return 1 if waiting timeout.
 * Return 2 if data error.(receiving timout or checksum error)
 * Return 3 if a parity error occured.
 * Return 4 if a frame error occured.
 */
int scia_rcv_varsize(unsigned int *rcvBuff, int buffLen, int typeLen, char
                     *expTail, int tailsize, int *rcvBufferLen)
{
  int i = 0;
  int errorVal = NOERROR;
  unsigned int byte_cnt = 0;
  int tailCount = 0;
  int totalLen = buffLen + tailsize;
  *rcvBufferLen = 0;
  while (i < totalLen) {
    if (SciaRegs.SCIFFRX.bit.RXFFST > 0) {/*Check if receive FIFO has data*/
      if (typeLen > 1) {
        if (byte_cnt == 0) {
          rcvBuff[i/2] = (SciaRegs.SCIRXBUF.all & 0x00FF);
          byte_cnt = 1;
        } else {
          rcvBuff[i/2] |= SciaRegs.SCIRXBUF.all << 8;
          byte_cnt = 0;
        }

        if (tailsize != 0) {
          // Do not check tail if tail is not provided
          if (rcvBuff[i/2] == expTail[tailCount]) {
            tailCount++;
            if (tailCount == tailsize) {
              *rcvBufferLen = i - tailsize + 1;
              break;
            }
          } else {
            tailCount = 0;
          }
        }
      } else {
        rcvBuff[i] = SciaRegs.SCIRXBUF.all;
        if (tailsize != 0) {
          // Do not check tail if tail is not provided
          if (rcvBuff[i] == expTail[tailCount]) {
            tailCount++;
            if (tailCount == tailsize) {
              *rcvBufferLen = i - tailsize + 1;
              break;
            }
          }
        } else {
          tailCount = 0;
        }
      }
    } else {
      if (i == 0) {
        return DATANOTAVAILABLE;
      } else {
        *rcvBufferLen = i;
        errorVal = PARTIALDATA;
        break;
      }
    }

    i = i+1;

    //Check flags
    if (SciaRegs.SCIFFRX.bit.RXFFOVF == 1)/* detect FIFO overflow*/
    {
      SciaRegs.SCIFFRX.bit.RXFFOVRCLR = 1;

      /*SciaRegs.SCIFFRX.bit.RXFIFORESET = 0;    Reset the FIFO pointer to zero.
       * SciaRegs.SCIFFRX.bit.RXFIFORESET = 1;   Re-enable receive FIFO operation.
       */
    }

    if (SciaRegs.SCIRXST.bit.FE)
      errorVal = FRAMERR;
    if (SciaRegs.SCIRXST.bit.PE)
      errorVal = PRTYERR;
    if (SciaRegs.SCIRXST.bit.OE)
      errorVal = OVRNERR;
    if (SciaRegs.SCIRXST.bit.BRKDT)
      errorVal = BRKDTERR;
    if (SciaRegs.SCIRXST.bit.RXERROR == 1) {
      SciaRegs.SCICTL1.bit.SWRESET = 1;
      SciaRegs.SCICTL1.bit.SWRESET = 0;
      SciaRegs.SCICTL1.bit.SWRESET = 1;
    }
  }

  if (0 == tailsize) {
    if (errorVal != PARTIALDATA) {
      //In case of tail not provided, error flag will NOERROR if data received is of max length
      *rcvBufferLen = totalLen;
    }
  } else {
    // error out as data not available if tail is provided and not found till maximum length
    if (*rcvBufferLen == 0) {
      return DATANOTAVAILABLE;
    }
  }

  return errorVal;
}

int byteswap_L8cmp(unsigned int* outdata, char* recdata, int inportWidth, int
                   typeLen)
{
  int i, j;
  int numWrd = (inportWidth * typeLen)/2;
                                 /* number of words (16 bit length) to receive*/

  /* Little Endian, 8bit swap */
  for (i = 0; i < numWrd; i++) {
    outdata[i] = 0;
    for (j = 0; j<2; j++) {
      outdata[i] += recdata[i*2+j] <<(8*j);
    }
  }

  return 0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

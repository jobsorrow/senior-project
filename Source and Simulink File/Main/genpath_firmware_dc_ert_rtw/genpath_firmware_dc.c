/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: genpath_firmware_dc.c
 *
 * Code generated for Simulink model 'genpath_firmware_dc'.
 *
 * Model version                  : 3.4
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Thu Apr 21 10:46:13 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. ROM efficiency
 *    3. RAM efficiency
 * Validation result: Not run
 */

#include "genpath_firmware_dc.h"
#include "rtwtypes.h"
#include "genpath_firmware_dc_private.h"
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_genpath_firmware_dc_T genpath_firmware_dc_B;

/* Block states (default storage) */
DW_genpath_firmware_dc_T genpath_firmware_dc_DW;

/* Real-time model */
static RT_MODEL_genpath_firmware_dc_T genpath_firmware_dc_M_;
RT_MODEL_genpath_firmware_dc_T *const genpath_firmware_dc_M =
  &genpath_firmware_dc_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcAInitFlag = 0;

#endif

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt' */
void isr_int1pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/ADC Interrupt Callback */
    {
      /* RateTransition: '<Root>/Rate Transition SCI-ADC' */
      genpath_firmware_dc_B.RateTransitionSCIADC =
        genpath_firmware_dc_DW.RateTransitionSCIADC_Buffer0;

      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/ADC Interrupt Callback' */
      {
        real32_T rtb_Gain2;
        real32_T rtb_PreventDivisionByZero;
        real32_T rtb_uV_bN;
        real32_T u0;
        int16_T s8_iter;
        uint16_T rtb_Merge[6];
        uint16_T rtb_ImpAsg_InsertedFor_Data_at_[4];
        uint16_T rtb_TmpSignalConversionAtAvoidH[4];
        uint16_T rtb_PreventPWMCounterOverrun[2];
        uint16_T qY;
        uint16_T rtb_Merge_p;

        /* S-Function (c2802xadc): '<S13>/V_A' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          genpath_firmware_dc_B.V_A = (AdcbResultRegs.ADCRESULT0);
        }

        /* S-Function (c2802xadc): '<S13>/V_B' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          genpath_firmware_dc_B.V_B = (AdccResultRegs.ADCRESULT1);
        }

        /* S-Function (c2802xadc): '<S11>/I_A' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          genpath_firmware_dc_B.I_A = (AdccResultRegs.ADCRESULT3);
        }

        /* Bias: '<S11>/Bias' */
        qY = genpath_firmware_dc_B.I_A + /*MW:OvSatOk*/
          genpath_firmware_dc_P.Bias_Bias_p;
        if (qY < genpath_firmware_dc_B.I_A) {
          qY = MAX_uint16_T;
        }

        /* S-Function (c2802xadc): '<S3>/DC Bus Voltage ADC' */
        {
          /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
          /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
          genpath_firmware_dc_B.DCBusVoltageADC = (AdcaResultRegs.ADCRESULT6);
        }

        /* SignalConversion generated from: '<S7>/Avoid Header and Terminator Collision' incorporates:
         *  Bias: '<S11>/Bias'
         */
        rtb_TmpSignalConversionAtAvoidH[0] = genpath_firmware_dc_B.V_A;
        rtb_TmpSignalConversionAtAvoidH[1] = genpath_firmware_dc_B.V_B;
        rtb_TmpSignalConversionAtAvoidH[2] = qY;
        rtb_TmpSignalConversionAtAvoidH[3] =
          genpath_firmware_dc_B.DCBusVoltageADC;

        /* Outputs for Iterator SubSystem: '<S7>/Avoid Header and Terminator Collision' incorporates:
         *  ForEach: '<S30>/For Each'
         */
        /* ForEachSliceSelector generated from: '<S30>/Data Packet' */
        rtb_Merge_p = rtb_TmpSignalConversionAtAvoidH[0];

        /* If: '<S30>/If1' */
        if (rtb_Merge_p == 61166U) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
        } else if (rtb_Merge_p == MAX_uint16_T) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem1);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
        }

        /* ForEachSliceAssignment generated from: '<S30>/Data' */
        rtb_ImpAsg_InsertedFor_Data_at_[0] = rtb_Merge_p;

        /* ForEachSliceSelector generated from: '<S30>/Data Packet' */
        rtb_Merge_p = rtb_TmpSignalConversionAtAvoidH[1];

        /* If: '<S30>/If1' */
        if (rtb_Merge_p == 61166U) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
        } else if (rtb_Merge_p == MAX_uint16_T) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem1);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
        }

        /* ForEachSliceAssignment generated from: '<S30>/Data' */
        rtb_ImpAsg_InsertedFor_Data_at_[1] = rtb_Merge_p;

        /* ForEachSliceSelector generated from: '<S30>/Data Packet' */
        rtb_Merge_p = rtb_TmpSignalConversionAtAvoidH[2];

        /* If: '<S30>/If1' */
        if (rtb_Merge_p == 61166U) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
        } else if (rtb_Merge_p == MAX_uint16_T) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem1);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
        }

        /* ForEachSliceAssignment generated from: '<S30>/Data' */
        rtb_ImpAsg_InsertedFor_Data_at_[2] = rtb_Merge_p;

        /* ForEachSliceSelector generated from: '<S30>/Data Packet' */
        rtb_Merge_p = rtb_TmpSignalConversionAtAvoidH[3];

        /* If: '<S30>/If1' */
        if (rtb_Merge_p == 61166U) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem' incorporates:
           *  ActionPort: '<S34>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem' */
        } else if (rtb_Merge_p == MAX_uint16_T) {
          /* Outputs for IfAction SubSystem: '<S30>/If Action Subsystem1' incorporates:
           *  ActionPort: '<S35>/Action Port'
           */
          genpath_f_IfActionSubsystem(&rtb_Merge_p,
            &genpath_firmware_dc_P.CoreSubsys.IfActionSubsystem1);

          /* End of Outputs for SubSystem: '<S30>/If Action Subsystem1' */
        }

        /* ForEachSliceAssignment generated from: '<S30>/Data' */
        rtb_ImpAsg_InsertedFor_Data_at_[3] = rtb_Merge_p;

        /* End of Outputs for SubSystem: '<S7>/Avoid Header and Terminator Collision' */

        /* If: '<S7>/If' incorporates:
         *  UnitDelay: '<S31>/Output'
         */
        if (genpath_firmware_dc_DW.Output_DSTATE == 0U) {
          /* Outputs for IfAction SubSystem: '<S7>/Start' incorporates:
           *  ActionPort: '<S33>/Action Port'
           */
          /* SignalConversion generated from: '<S33>/Data_out' incorporates:
           *  Constant: '<S33>/End'
           *  Constant: '<S33>/Start'
           *  SignalConversion generated from: '<S33>/Data'
           */
          rtb_Merge[0] = genpath_firmware_dc_P.End_Value;
          rtb_Merge[1] = genpath_firmware_dc_P.Start_Value;
          rtb_Merge[2] = rtb_ImpAsg_InsertedFor_Data_at_[0];
          rtb_Merge[3] = rtb_ImpAsg_InsertedFor_Data_at_[1];
          rtb_Merge[4] = rtb_ImpAsg_InsertedFor_Data_at_[2];
          rtb_Merge[5] = rtb_ImpAsg_InsertedFor_Data_at_[3];

          /* Bias: '<S33>/Bias' */
          rtb_Merge_p = genpath_firmware_dc_ConstB.Width +
            genpath_firmware_dc_P.Bias_Bias_c;

          /* End of Outputs for SubSystem: '<S7>/Start' */
        } else {
          /* Outputs for IfAction SubSystem: '<S7>/Data' incorporates:
           *  ActionPort: '<S32>/Action Port'
           */
          /* SignalConversion generated from: '<S32>/Data_out' incorporates:
           *  Constant: '<S32>/Start'
           *  Constant: '<S32>/Start1'
           *  SignalConversion generated from: '<S32>/Data'
           */
          rtb_Merge[0] = rtb_ImpAsg_InsertedFor_Data_at_[0];
          rtb_Merge[1] = rtb_ImpAsg_InsertedFor_Data_at_[1];
          rtb_Merge[2] = rtb_ImpAsg_InsertedFor_Data_at_[2];
          rtb_Merge[3] = rtb_ImpAsg_InsertedFor_Data_at_[3];
          rtb_Merge[4] = genpath_firmware_dc_P.Start_Value_i;
          rtb_Merge[5] = genpath_firmware_dc_P.Start1_Value;

          /* SignalConversion generated from: '<S32>/Data_width' */
          rtb_Merge_p = genpath_firmware_dc_ConstB.Width;

          /* End of Outputs for SubSystem: '<S7>/Data' */
        }

        /* End of If: '<S7>/If' */

        /* Outputs for Iterator SubSystem: '<S1>/Serial Transmit' incorporates:
         *  WhileIterator: '<S8>/While Data Available'
         */
        /* MultiPortSwitch: '<S8>/Index Vector' */
        s8_iter = 0;
        uint16_T rtb_Add;
        do {
          genpath_firmware_dc_B.DataTypeConversion = rtb_Merge[s8_iter];

          {
            if (checkSCITransmitInprogress != 1) {
              checkSCITransmitInprogress = 1;
              int errFlgHeader = NOERROR;
              int errFlgData = NOERROR;
              int errFlgTail = NOERROR;
              errFlgData = scia_xmit((char*)
                &genpath_firmware_dc_B.DataTypeConversion, 2, 2);
              checkSCITransmitInprogress = 0;
            }
          }

          rtb_Add = (rtb_Merge_p - s8_iter) - 1U;
          s8_iter++;
        } while (rtb_Add != 0U);

        /* End of Outputs for SubSystem: '<S1>/Serial Transmit' */

        /* Sum: '<S17>/Add1' incorporates:
         *  Constant: '<S17>/Filter_Constant'
         *  Constant: '<S17>/One'
         *  Gain: '<S3>/DC Bus Voltage ADC Gain'
         *  Product: '<S17>/Product'
         *  Product: '<S17>/Product1'
         *  UnitDelay: '<S17>/Unit Delay'
         */
        genpath_firmware_dc_DW.UnitDelay_DSTATE = (real32_T)
          genpath_firmware_dc_P.DCBusVoltageADCGain_Gain * 4.76837158E-7F *
          (real32_T)genpath_firmware_dc_B.DCBusVoltageADC *
          genpath_firmware_dc_P.Filter_Constant_Value +
          genpath_firmware_dc_P.One_Value *
          genpath_firmware_dc_DW.UnitDelay_DSTATE;

        /* Sum: '<S20>/Add1' incorporates:
         *  Bias: '<S11>/Bias'
         *  Bias: '<S3>/Bias'
         *  Constant: '<S20>/Filter_Constant'
         *  Constant: '<S20>/One'
         *  Gain: '<S3>/Gain3'
         *  Gain: '<S3>/Phase Current ADC Gain'
         *  Product: '<S20>/Product'
         *  Product: '<S20>/Product1'
         *  UnitDelay: '<S20>/Unit Delay'
         */
        genpath_firmware_dc_DW.UnitDelay_DSTATE_g = ((real32_T)
          genpath_firmware_dc_P.PhaseCurrentADCGain_Gain * 1.49011612E-8F *
          (real32_T)qY + genpath_firmware_dc_P.Bias_Bias) *
          genpath_firmware_dc_P.Gain3_Gain *
          genpath_firmware_dc_P.Filter_Constant_Value_d +
          genpath_firmware_dc_P.One_Value_e *
          genpath_firmware_dc_DW.UnitDelay_DSTATE_g;

        /* Gain: '<S6>/Gain2' */
        rtb_Gain2 = genpath_firmware_dc_P.HW_LS *
          genpath_firmware_dc_DW.UnitDelay_DSTATE_g;

        /* Sum: '<S29>/Add1' incorporates:
         *  Constant: '<S29>/Filter_Constant'
         *  Constant: '<S29>/One'
         *  Gain: '<S25>/Gain'
         *  Product: '<S29>/Product'
         *  Product: '<S29>/Product1'
         *  Sum: '<S25>/Subtract'
         *  UnitDelay: '<S25>/Unit Delay'
         *  UnitDelay: '<S29>/Unit Delay'
         */
        genpath_firmware_dc_DW.UnitDelay_DSTATE_m = (rtb_Gain2 -
          genpath_firmware_dc_DW.UnitDelay_DSTATE_gk) *
          genpath_firmware_dc_P.Gain_Gain *
          genpath_firmware_dc_P.Filter_Constant_Value_c +
          genpath_firmware_dc_P.One_Value_f *
          genpath_firmware_dc_DW.UnitDelay_DSTATE_m;

        /* Sum: '<S6>/Sum' incorporates:
         *  Gain: '<S6>/Gain1'
         */
        rtb_uV_bN = genpath_firmware_dc_P.Gain1_Gain *
          genpath_firmware_dc_DW.UnitDelay_DSTATE_g +
          genpath_firmware_dc_DW.UnitDelay_DSTATE_m;

        /* Saturate: '<S24>/Prevent Division By Zero' */
        if (genpath_firmware_dc_DW.UnitDelay_DSTATE >
            genpath_firmware_dc_P.PreventDivisionByZero_UpperSat) {
          rtb_PreventDivisionByZero =
            genpath_firmware_dc_P.PreventDivisionByZero_UpperSat;
        } else if (genpath_firmware_dc_DW.UnitDelay_DSTATE <
                   genpath_firmware_dc_P.PreventDivisionByZero_LowerSat) {
          rtb_PreventDivisionByZero =
            genpath_firmware_dc_P.PreventDivisionByZero_LowerSat;
        } else {
          rtb_PreventDivisionByZero = genpath_firmware_dc_DW.UnitDelay_DSTATE;
        }

        /* End of Saturate: '<S24>/Prevent Division By Zero' */

        /* Product: '<S24>/Normalize Phase Voltage' incorporates:
         *  Gain: '<S24>/Gain'
         *  Sum: '<S24>/Add'
         */
        u0 = (genpath_firmware_dc_DW.UnitDelay_DSTATE + rtb_uV_bN) *
          genpath_firmware_dc_P.Gain_Gain_o / rtb_PreventDivisionByZero;

        /* Saturate: '<S24>/Prevent Overmodulation' */
        if (u0 > genpath_firmware_dc_P.PreventOvermodulation_UpperSat) {
          u0 = genpath_firmware_dc_P.PreventOvermodulation_UpperSat;
        } else if (u0 < genpath_firmware_dc_P.PreventOvermodulation_LowerSat) {
          u0 = genpath_firmware_dc_P.PreventOvermodulation_LowerSat;
        }

        /* Gain: '<S24>/Time Base Period' */
        u0 *= genpath_firmware_dc_P.TimeBasePeriod_Gain;

        /* Saturate: '<S24>/Prevent PWM Counter Overrun' */
        if (u0 > genpath_firmware_dc_P.PreventPWMCounterOverrun_UpperS) {
          u0 = genpath_firmware_dc_P.PreventPWMCounterOverrun_UpperS;
        } else if (u0 < genpath_firmware_dc_P.PreventPWMCounterOverrun_LowerS) {
          u0 = genpath_firmware_dc_P.PreventPWMCounterOverrun_LowerS;
        }

        u0 = floorf(u0);
        if (rtIsNaNF(u0)) {
          u0 = 0.0F;
        } else {
          u0 = fmodf(u0, 65536.0F);
        }

        rtb_PreventPWMCounterOverrun[0] = u0 < 0.0F ? (uint16_T)-(int16_T)
          (uint16_T)-u0 : (uint16_T)u0;

        /* Product: '<S24>/Normalize Phase Voltage' incorporates:
         *  Gain: '<S24>/Gain'
         *  Sum: '<S24>/Add1'
         */
        u0 = (genpath_firmware_dc_DW.UnitDelay_DSTATE - rtb_uV_bN) *
          genpath_firmware_dc_P.Gain_Gain_o / rtb_PreventDivisionByZero;

        /* Saturate: '<S24>/Prevent Overmodulation' */
        if (u0 > genpath_firmware_dc_P.PreventOvermodulation_UpperSat) {
          u0 = genpath_firmware_dc_P.PreventOvermodulation_UpperSat;
        } else if (u0 < genpath_firmware_dc_P.PreventOvermodulation_LowerSat) {
          u0 = genpath_firmware_dc_P.PreventOvermodulation_LowerSat;
        }

        /* Gain: '<S24>/Time Base Period' */
        u0 *= genpath_firmware_dc_P.TimeBasePeriod_Gain;

        /* Saturate: '<S24>/Prevent PWM Counter Overrun' */
        if (u0 > genpath_firmware_dc_P.PreventPWMCounterOverrun_UpperS) {
          u0 = genpath_firmware_dc_P.PreventPWMCounterOverrun_UpperS;
        } else if (u0 < genpath_firmware_dc_P.PreventPWMCounterOverrun_LowerS) {
          u0 = genpath_firmware_dc_P.PreventPWMCounterOverrun_LowerS;
        }

        u0 = floorf(u0);
        if (rtIsNaNF(u0)) {
          u0 = 0.0F;
        } else {
          u0 = fmodf(u0, 65536.0F);
        }

        rtb_PreventPWMCounterOverrun[1] = u0 < 0.0F ? (uint16_T)-(int16_T)
          (uint16_T)-u0 : (uint16_T)u0;

        /* S-Function (c2802xpwm): '<S9>/SW_A' */

        /*-- Update CMPA value for ePWM1 --*/
        {
          EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_PreventPWMCounterOverrun[0]);
        }

        /* S-Function (c2802xpwm): '<S9>/SW_B' */

        /*-- Update CMPA value for ePWM4 --*/
        {
          EPwm4Regs.CMPA.bit.CMPA = (uint16_T)(rtb_PreventPWMCounterOverrun[1]);
        }

        /* DataTypeConversion: '<S4>/Data Type Conversion' incorporates:
         *  RateTransition: '<Root>/Rate Transition SCI-ADC'
         */
        genpath_firmware_dc_B.DataTypeConversion =
          genpath_firmware_dc_B.RateTransitionSCIADC;

        /* S-Function (c280xgpio_do): '<S5>/Inverter Enable Pin' */
        {
          if (genpath_firmware_dc_B.DataTypeConversion)
            GpioDataRegs.GPBSET.bit.GPIO33 = 1;
          else
            GpioDataRegs.GPBCLEAR.bit.GPIO33 = 1;
        }

        /* Sum: '<S37>/FixPt Sum1' incorporates:
         *  Constant: '<S37>/FixPt Constant'
         *  UnitDelay: '<S31>/Output'
         */
        genpath_firmware_dc_DW.Output_DSTATE +=
          genpath_firmware_dc_P.FixPtConstant_Value;

        /* Switch: '<S38>/FixPt Switch' */
        if (genpath_firmware_dc_DW.Output_DSTATE >
            genpath_firmware_dc_P.CounterLimited_uplimit) {
          /* Sum: '<S37>/FixPt Sum1' incorporates:
           *  Constant: '<S38>/Constant'
           *  UnitDelay: '<S31>/Output'
           */
          genpath_firmware_dc_DW.Output_DSTATE =
            genpath_firmware_dc_P.Constant_Value_m;
        }

        /* End of Switch: '<S38>/FixPt Switch' */

        /* Update for UnitDelay: '<S25>/Unit Delay' */
        genpath_firmware_dc_DW.UnitDelay_DSTATE_gk = rtb_Gain2;
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
    }
  }
}

/* Hardware Interrupt Block: '<Root>/C28x Hardware Interrupt' */
void isr_int9pie1_task_fcn(void)
{
  if (1 == runModel) {
    /* Call the system: <Root>/SCI Receive Interrupt Callback */
    {
      /* S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/SCI Receive Interrupt Callback' */

      /* S-Function (c28xsci_rx): '<S2>/SCIA Receive' */
      {
        int i;
        int errFlg = NOERROR;
        unsigned int recbuff[1];
        for (i = 0; i < 1; i++)
          recbuff[i] = 0;

        /* Getting Data Head */
        {
          unsigned int recHead;
          int cnt = 0;
          int i = 0;
          char *expHead = "S";
          while (i < 1) {
            scia_rcv(&recHead, 1, 1);
            if (recHead == expHead[i]) {
              i++;
            } else {
              i = 0;
            }

            if (cnt++ > 16U) {
              errFlg = TIMEOUT;
              goto RXERRA;
            }
          }
        }

        /* End of Getting Data Head */

        /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
        errFlg = scia_rcv(recbuff, 1, 1);
        if (errFlg != NOERROR)
          goto RXERRA;

        /* Getting Data Tail */
        {
          int i;
          char *expTail = "E";
          unsigned int recTail[1];
          scia_rcv(recTail, 1, 1);
          for (i = 0; i< 1; i++) {
            if (expTail[i] != recTail[i]) {
              errFlg = DATAERR;
              goto RXERRA;
            }
          }
        }

        /* End of Getting Data Tail */
        memcpy( &genpath_firmware_dc_B.SCIAReceive, recbuff, 1);
       RXERRA:
        asm(" NOP");
      }

      /* End of Outputs for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */

      /* RateTransition: '<Root>/Rate Transition SCI-ADC' incorporates:
       *  S-Function (c28xsci_rx): '<S2>/SCIA Receive'
       */
      genpath_firmware_dc_DW.RateTransitionSCIADC_Buffer0 =
        genpath_firmware_dc_B.SCIAReceive;
    }
  }
}

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void genpath_firmware_dc_SetEventsForThisBaseStep(boolean_T *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(genpath_firmware_dc_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (genpath_firmware_dc_M->Timing.TaskCounters.TID[1])++;
  if ((genpath_firmware_dc_M->Timing.TaskCounters.TID[1]) > 19999) {/* Sample time: [1.0s, 0.0s] */
    genpath_firmware_dc_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for action system:
 *    '<S30>/If Action Subsystem'
 *    '<S30>/If Action Subsystem1'
 */
void genpath_f_IfActionSubsystem(uint16_T *rty_Out1,
  P_IfActionSubsystem_genpath_f_T *localP)
{
  /* SignalConversion generated from: '<S34>/Out1' incorporates:
   *  Constant: '<S34>/Constant'
   */
  *rty_Out1 = localP->Constant_Value;
}

/* Model step function for TID0 */
void genpath_firmware_dc_step0(void)   /* Sample time: [5.0E-5s, 0.0s] */
{
  {                                    /* Sample time: [5.0E-5s, 0.0s] */
    rate_monotonic_scheduler();
  }
}

/* Model step function for TID1 */
void genpath_firmware_dc_step1(void)   /* Sample time: [1.0s, 0.0s] */
{
  /* S-Function (c280xgpio_do): '<Root>/Heartbeat LED' incorporates:
   *  Constant: '<Root>/Constant'
   */
  {
    GpioDataRegs.GPATOGGLE.bit.GPIO23 = (genpath_firmware_dc_P.Constant_Value !=
      0);
  }
}

/* Model initialize function */
void genpath_firmware_dc_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for S-Function (c280xgpio_do): '<Root>/Heartbeat LED' incorporates:
   *  Constant: '<Root>/Constant'
   */
  EALLOW;
  GpioCtrlRegs.GPAMUX2.all &= 0xFFFF3FFF;
  GpioCtrlRegs.GPADIR.all |= 0x800000;
  EDIS;

  /* InitializeConditions for RateTransition: '<Root>/Rate Transition SCI-ADC' */
  genpath_firmware_dc_DW.RateTransitionSCIADC_Buffer0 =
    genpath_firmware_dc_P.RateTransitionSCIADC_InitialCon;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/ADC Interrupt Callback'
   */
  /* System initialize for function-call system: '<Root>/ADC Interrupt Callback' */

  /* Start for S-Function (c2802xadc): '<S13>/V_A' */
  if (MW_adcBInitFlag == 0) {
    InitAdcB();
    MW_adcBInitFlag = 1;
  }

  config_ADCB_SOC0 ();

  /* Start for S-Function (c2802xadc): '<S13>/V_B' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC1 ();

  /* Start for S-Function (c2802xadc): '<S11>/I_A' */
  if (MW_adcCInitFlag == 0) {
    InitAdcC();
    MW_adcCInitFlag = 1;
  }

  config_ADCC_SOC3 ();

  /* Start for S-Function (c2802xadc): '<S3>/DC Bus Voltage ADC' */
  if (MW_adcAInitFlag == 0) {
    InitAdcA();
    MW_adcAInitFlag = 1;
  }

  config_ADCA_SOC6 ();

  /* Start for S-Function (c2802xpwm): '<S9>/SW_A' */

  /*** Initialize ePWM1 modules ***/
  {
    /*  // Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm1Regs.TBCTL2.bit.SYNCOSELX           = 0;          // Sync Output Select - additional options

       EPwm1Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm1Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFF) | 0x32;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xF000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000;            // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm1Regs.CMPA.bit.CMPA = 0;       // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm1Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3;          // Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2;          // Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFF) | 0xB;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(5.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(5.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1;          // Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm1Regs.ETSEL.bit.INTEN                = 0;          // EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7F) | 0x1A01;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30) | 0x30;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0;          // Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0;          // Digital Compare B Low COMP Input Select

     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x0;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm1Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0) | 0x0;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S9>/SW_B' */

  /*** Initialize ePWM4 modules ***/
  {
    /*  // Time Base Control Register
       EPwm4Regs.TBCTL.bit.CTRMODE              = 2;          // Counter Mode
       EPwm4Regs.TBCTL.bit.SYNCOSEL             = 3;          // Sync Output Select
       EPwm4Regs.TBCTL2.bit.SYNCOSELX           = 0;          // Sync Output Select - additional options

       EPwm4Regs.TBCTL.bit.PRDLD                = 0;          // Shadow select

       EPwm4Regs.TBCTL2.bit.PRDLDSYNC           = 0;          // Shadow select

       EPwm4Regs.TBCTL.bit.PHSEN                = 0;          // Phase Load Enable
       EPwm4Regs.TBCTL.bit.PHSDIR               = 0;          // Phase Direction Bit
       EPwm4Regs.TBCTL.bit.HSPCLKDIV            = 0;          // High Speed TBCLK Pre-scaler
       EPwm4Regs.TBCTL.bit.CLKDIV               = 0;          // Time Base Clock Pre-scaler
       EPwm4Regs.TBCTL.bit.SWFSYNC              = 0;          // Software Force Sync Pulse
     */
    EPwm4Regs.TBCTL.all = (EPwm4Regs.TBCTL.all & ~0x3FFF) | 0x32;
    EPwm4Regs.TBCTL2.all = (EPwm4Regs.TBCTL2.all & ~0xF000) | 0x0;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm4Regs.TBPRD = 5000;            // Time Base Period Register

    /* // Time-Base Phase Register
       EPwm4Regs.TBPHS.bit.TBPHS               = 0;          // Phase offset register
     */
    EPwm4Regs.TBPHS.all = (EPwm4Regs.TBPHS.all & ~0xFFFF0000) | 0x0;

    // Time Base Counter Register
    EPwm4Regs.TBCTR = 0x0000;          /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	// Counter Compare Control Register

       EPwm4Regs.CMPCTL.bit.LOADASYNC           = 0U;          // Active Compare A Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADBSYNC           = 0U;          // Active Compare B Load SYNC Option
       EPwm4Regs.CMPCTL.bit.LOADAMODE           = 0U;          // Active Compare A Load
       EPwm4Regs.CMPCTL.bit.LOADBMODE           = 0U;          // Active Compare B Load
       EPwm4Regs.CMPCTL.bit.SHDWAMODE           = 0;          // Compare A Register Block Operating Mode
       EPwm4Regs.CMPCTL.bit.SHDWBMODE           = 0;          // Compare B Register Block Operating Mode
     */
    EPwm4Regs.CMPCTL.all = (EPwm4Regs.CMPCTL.all & ~0x3C5F) | 0x0;

    /* EPwm4Regs.CMPCTL2.bit.SHDWCMODE           = 0;          // Compare C Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.SHDWDMODE           = 0;          // Compare D Register Block Operating Mode
       EPwm4Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          // Active Compare C Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          // Active Compare D Load SYNC Option
       EPwm4Regs.CMPCTL2.bit.LOADCMODE           = 0U;          // Active Compare C Load
       EPwm4Regs.CMPCTL2.bit.LOADDMODE           = 0U;          // Active Compare D Load
     */
    EPwm4Regs.CMPCTL2.all = (EPwm4Regs.CMPCTL2.all & ~0x3C5F) | 0x0;
    EPwm4Regs.CMPA.bit.CMPA = 0;       // Counter Compare A Register
    EPwm4Regs.CMPB.bit.CMPB = 32000;   // Counter Compare B Register
    EPwm4Regs.CMPC = 32000;            // Counter Compare C Register
    EPwm4Regs.CMPD = 32000;            // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm4Regs.AQCTLA.all = 150;// Action Qualifier Control Register For Output A
    EPwm4Regs.AQCTLB.all = 2310;
                               // Action Qualifier Control Register For Output B

    /*	// Action Qualifier Software Force Register
       EPwm4Regs.AQSFRC.bit.RLDCSF              = 0;          // Reload from Shadow Options
     */
    EPwm4Regs.AQSFRC.all = (EPwm4Regs.AQSFRC.all & ~0xC0) | 0x0;

    /*	// Action Qualifier Continuous S/W Force Register
       EPwm4Regs.AQCSFRC.bit.CSFA               = 0;          // Continuous Software Force on output A
       EPwm4Regs.AQCSFRC.bit.CSFB               = 0;          // Continuous Software Force on output B
     */
    EPwm4Regs.AQCSFRC.all = (EPwm4Regs.AQCSFRC.all & ~0xF) | 0x0;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	// Dead-Band Generator Control Register
       EPwm4Regs.DBCTL.bit.OUT_MODE             = 3;          // Dead Band Output Mode Control
       EPwm4Regs.DBCTL.bit.IN_MODE              = 0;          // Dead Band Input Select Mode Control
       EPwm4Regs.DBCTL.bit.POLSEL               = 2;          // Polarity Select Control
       EPwm4Regs.DBCTL.bit.HALFCYCLE            = 0;          // Half Cycle Clocking Enable
       EPwm4Regs.DBCTL.bit.SHDWDBREDMODE        = 0;          // DBRED shadow mode
       EPwm4Regs.DBCTL.bit.SHDWDBFEDMODE        = 0;          // DBFED shadow mode
       EPwm4Regs.DBCTL.bit.LOADREDMODE          = 4U;        // DBRED load
       EPwm4Regs.DBCTL.bit.LOADFEDMODE          = 4U;        // DBFED load
     */
    EPwm4Regs.DBCTL.all = (EPwm4Regs.DBCTL.all & ~0x8FFF) | 0xB;
    EPwm4Regs.DBRED.bit.DBRED = (uint16_T)(5.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm4Regs.DBFED.bit.DBFED = (uint16_T)(5.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	// Event Trigger Selection and Pre-Scale Register
       EPwm4Regs.ETSEL.bit.SOCAEN               = 1;          // Start of Conversion A Enable
       EPwm4Regs.ETSEL.bit.SOCASELCMP           = 0;
       EPwm4Regs.ETSEL.bit.SOCASEL              = 2;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM4SOC Period Select
       EPwm4Regs.ETSOCPS.bit.SOCAPRD2           = 1;
       EPwm4Regs.ETSEL.bit.SOCBEN               = 0;          // Start of Conversion B Enable
       EPwm4Regs.ETSEL.bit.SOCBSELCMP           = 0;
       EPwm4Regs.ETSEL.bit.SOCBSEL              = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.SOCPSSEL              = 1;          // EPWM4SOCB Period Select
       EPwm4Regs.ETSOCPS.bit.SOCBPRD2           = 1;
       EPwm4Regs.ETSEL.bit.INTEN                = 0;          // EPWM4INTn Enable
       EPwm4Regs.ETSEL.bit.INTSELCMP            = 0;
       EPwm4Regs.ETSEL.bit.INTSEL               = 1;          // Start of Conversion A Select
       EPwm4Regs.ETPS.bit.INTPSSEL              = 1;          // EPWM4INTn Period Select
       EPwm4Regs.ETINTPS.bit.INTPRD2            = 1;
     */
    EPwm4Regs.ETSEL.all = (EPwm4Regs.ETSEL.all & ~0xFF7F) | 0x1A01;
    EPwm4Regs.ETPS.all = (EPwm4Regs.ETPS.all & ~0x30) | 0x30;
    EPwm4Regs.ETSOCPS.all = (EPwm4Regs.ETSOCPS.all & ~0xF0F) | 0x101;
    EPwm4Regs.ETINTPS.all = (EPwm4Regs.ETINTPS.all & ~0xF) | 0x1;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	// PWM Chopper Control Register
       EPwm4Regs.PCCTL.bit.CHPEN                = 0;          // PWM chopping enable
       EPwm4Regs.PCCTL.bit.CHPFREQ              = 0;          // Chopping clock frequency
       EPwm4Regs.PCCTL.bit.OSHTWTH              = 0;          // One-shot pulse width
       EPwm4Regs.PCCTL.bit.CHPDUTY              = 0;          // Chopping clock Duty cycle
     */
    EPwm4Regs.PCCTL.all = (EPwm4Regs.PCCTL.all & ~0x7FF) | 0x0;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm4Regs.TZSEL.all = 0;           // Trip Zone Select Register

    /*	// Trip Zone Control Register
       EPwm4Regs.TZCTL.bit.TZA                  = 3;          // TZ1 to TZ6 Trip Action On EPWM4A
       EPwm4Regs.TZCTL.bit.TZB                  = 3;          // TZ1 to TZ6 Trip Action On EPWM4B
       EPwm4Regs.TZCTL.bit.DCAEVT1              = 3;          // EPWM4A action on DCAEVT1
       EPwm4Regs.TZCTL.bit.DCAEVT2              = 3;          // EPWM4A action on DCAEVT2
       EPwm4Regs.TZCTL.bit.DCBEVT1              = 3;          // EPWM4B action on DCBEVT1
       EPwm4Regs.TZCTL.bit.DCBEVT2              = 3;          // EPWM4B action on DCBEVT2
     */
    EPwm4Regs.TZCTL.all = (EPwm4Regs.TZCTL.all & ~0xFFF) | 0xFFF;

    /*	// Trip Zone Enable Interrupt Register
       EPwm4Regs.TZEINT.bit.OST                 = 0;          // Trip Zones One Shot Int Enable
       EPwm4Regs.TZEINT.bit.CBC                 = 0;          // Trip Zones Cycle By Cycle Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT1             = 0;          // Digital Compare A Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCAEVT2             = 0;          // Digital Compare A Event 2 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT1             = 0;          // Digital Compare B Event 1 Int Enable
       EPwm4Regs.TZEINT.bit.DCBEVT2             = 0;          // Digital Compare B Event 2 Int Enable
     */
    EPwm4Regs.TZEINT.all = (EPwm4Regs.TZEINT.all & ~0x7E) | 0x0;

    /*	// Digital Compare A Control Register
       EPwm4Regs.DCACTL.bit.EVT1SYNCE           = 0;          // DCAEVT1 SYNC Enable
       EPwm4Regs.DCACTL.bit.EVT1SOCE            = 1;          // DCAEVT1 SOC Enable
       EPwm4Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0;          // DCAEVT1 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT1SRCSEL          = 0;          // DCAEVT1 Source Signal
       EPwm4Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0;          // DCAEVT2 Force Sync Signal
       EPwm4Regs.DCACTL.bit.EVT2SRCSEL          = 0;          // DCAEVT2 Source Signal
     */
    EPwm4Regs.DCACTL.all = (EPwm4Regs.DCACTL.all & ~0x30F) | 0x4;

    /*	// Digital Compare B Control Register
       EPwm4Regs.DCBCTL.bit.EVT1SYNCE           = 0;          // DCBEVT1 SYNC Enable
       EPwm4Regs.DCBCTL.bit.EVT1SOCE            = 0;          // DCBEVT1 SOC Enable
       EPwm4Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0;          // DCBEVT1 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT1SRCSEL          = 0;          // DCBEVT1 Source Signal
       EPwm4Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0;          // DCBEVT2 Force Sync Signal
       EPwm4Regs.DCBCTL.bit.EVT2SRCSEL          = 0;          // DCBEVT2 Source Signal
     */
    EPwm4Regs.DCBCTL.all = (EPwm4Regs.DCBCTL.all & ~0x30F) | 0x0;

    /*	// Digital Compare Trip Select Register
       EPwm4Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0;          // Digital Compare A High COMP Input Select

       EPwm4Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 0;          // Digital Compare A Low COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0;          // Digital Compare B High COMP Input Select
       EPwm4Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 0;          // Digital Compare B Low COMP Input Select

     */
    EPwm4Regs.DCTRIPSEL.all = (EPwm4Regs.DCTRIPSEL.all & ~ 0xFFFF) | 0x0;

    /*	// Trip Zone Digital Comparator Select Register
       EPwm4Regs.TZDCSEL.bit.DCAEVT1            = 0;          // Digital Compare Output A Event 1
       EPwm4Regs.TZDCSEL.bit.DCAEVT2            = 0;          // Digital Compare Output A Event 2
       EPwm4Regs.TZDCSEL.bit.DCBEVT1            = 0;          // Digital Compare Output B Event 1
       EPwm4Regs.TZDCSEL.bit.DCBEVT2            = 0;          // Digital Compare Output B Event 2
     */
    EPwm4Regs.TZDCSEL.all = (EPwm4Regs.TZDCSEL.all & ~0xFFF) | 0x0;

    /*	// Digital Compare Filter Control Register
       EPwm4Regs.DCFCTL.bit.BLANKE              = 0;          // Blanking Enable/Disable
       EPwm4Regs.DCFCTL.bit.PULSESEL            = 1;          // Pulse Select for Blanking & Capture Alignment
       EPwm4Regs.DCFCTL.bit.BLANKINV            = 0;          // Blanking Window Inversion
       EPwm4Regs.DCFCTL.bit.SRCSEL              = 0;          // Filter Block Signal Source Select
     */
    EPwm4Regs.DCFCTL.all = (EPwm4Regs.DCFCTL.all & ~0x3F) | 0x10;
    EPwm4Regs.DCFOFFSET = 0;           // Digital Compare Filter Offset Register
    EPwm4Regs.DCFWINDOW = 0;           // Digital Compare Filter Window Register

    /*	// Digital Compare Capture Control Register
       EPwm4Regs.DCCAPCTL.bit.CAPE              = 0;          // Counter Capture Enable
     */
    EPwm4Regs.DCCAPCTL.all = (EPwm4Regs.DCCAPCTL.all & ~0x1) | 0x0;

    /*	// HRPWM Configuration Register
       EPwm4Regs.HRCNFG.bit.SWAPAB              = 0;          // Swap EPWMA and EPWMB Outputs Bit
       EPwm4Regs.HRCNFG.bit.SELOUTB             = 0;          // EPWMB Output Selection Bit
     */
    EPwm4Regs.HRCNFG.all = (EPwm4Regs.HRCNFG.all & ~0xA0) | 0x0;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm4Regs.EPWMXLINK.bit.TBPRDLINK = 0;
    EPwm4Regs.EPWMXLINK.bit.CMPALINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPBLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPCLINK = 3;
    EPwm4Regs.EPWMXLINK.bit.CMPDLINK = 3;

    /* SYNCPER - Peripheral synchronization output event
       EPwm4Regs.HRPCTL.bit.PWMSYNCSEL            = 0;          // EPWMSYNCPER selection
       EPwm4Regs.HRPCTL.bit.PWMSYNCSELX           = 0;          //  EPWMSYNCPER selection
     */
    EPwm4Regs.HRPCTL.all = (EPwm4Regs.HRPCTL.all & ~0x72) | 0x0;
    EDIS;
    EALLOW;

    /* Enable TBCLK within the EPWM*/
    CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;
    EDIS;
  }

  /* Start for S-Function (c280xgpio_do): '<S5>/Inverter Enable Pin' */
  EALLOW;
  GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFF3;
  GpioCtrlRegs.GPBDIR.all |= 0x2;
  EDIS;

  /* InitializeConditions for Sum: '<S37>/FixPt Sum1' incorporates:
   *  UnitDelay: '<S31>/Output'
   */
  genpath_firmware_dc_DW.Output_DSTATE =
    genpath_firmware_dc_P.Output_InitialCondition;

  /* InitializeConditions for Sum: '<S17>/Add1' incorporates:
   *  UnitDelay: '<S17>/Unit Delay'
   */
  genpath_firmware_dc_DW.UnitDelay_DSTATE =
    genpath_firmware_dc_P.UnitDelay_InitialCondition;

  /* InitializeConditions for Sum: '<S20>/Add1' incorporates:
   *  UnitDelay: '<S20>/Unit Delay'
   */
  genpath_firmware_dc_DW.UnitDelay_DSTATE_g =
    genpath_firmware_dc_P.UnitDelay_InitialCondition_c;

  /* InitializeConditions for UnitDelay: '<S25>/Unit Delay' */
  genpath_firmware_dc_DW.UnitDelay_DSTATE_gk =
    genpath_firmware_dc_P.UnitDelay_InitialCondition_j;

  /* InitializeConditions for Sum: '<S29>/Add1' incorporates:
   *  UnitDelay: '<S29>/Unit Delay'
   */
  genpath_firmware_dc_DW.UnitDelay_DSTATE_m =
    genpath_firmware_dc_P.UnitDelay_InitialCondition_i;
  ;

  /* SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' incorporates:
   *  SubSystem: '<Root>/SCI Receive Interrupt Callback'
   */

  /* System initialize for function-call system: '<Root>/SCI Receive Interrupt Callback' */

  /* Start for S-Function (c28xsci_rx): '<S2>/SCIA Receive' */

  /* Initialize genpath_firmware_dc_B.SCIAReceive */
  {
    genpath_firmware_dc_B.SCIAReceive = (uint8_T)0.0;
  }

  /*Configure Timer2 when blocking mode enbled And Timeout is not inf*/
  {
    CpuTimer2Regs.PRD.all = 0xFFFFFFFF;/* max Period*/
    CpuTimer2Regs.TIM.all = 0xFFFFFFFF;/* set Ctr*/
    CpuTimer2Regs.TPR.all = 0x00;      /* no prescaler    */
    StartCpuTimer2();
  }

  /* SystemInitialize for S-Function (c28xsci_rx): '<S2>/SCIA Receive' incorporates:
   *  Outport: '<S2>/Commanded Signal'
   */
  genpath_firmware_dc_B.SCIAReceive = genpath_firmware_dc_P.CommandedSignal_Y0;
  ;

  /* End of SystemInitialize for S-Function (c28xisr_c2000): '<Root>/C28x Hardware Interrupt' */
}

/* Model terminate function */
void genpath_firmware_dc_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

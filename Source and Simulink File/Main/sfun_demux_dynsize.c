/*  File    : sfun_demux_dynsize.c
 *  Abstract:
 *
 *      Example of a Level-2 S-function which accepts an input of width N
 *      and produces an output of width N/2:
 *
 *                   .-------.
 *            u ---->| s-fcn |---(width u/2) ---> y
 *                   `-------'
 *
 *      This S-function has a 2-to-1 sum algorithm with a "memory" 
 *      block-type delay. The primary purpose of this S-function is to
 *      demonstrate how to work with dynamically-sized vectors.
 *
 *      If u is unconnected, the input width is set to 2 and the output
 *      width is set to 1.
 *
 *  Copyright 1990-2013 The MathWorks, Inc.
 */

#define S_FUNCTION_NAME sfun_demux_dynsize
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"

/* Function: mdlInitializeSizes ===============================================
 * Abstract:
 *   Setup sizes of the various vectors.
 */
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0); /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S))
    {
        return; /* Parameter mismatch will be reported by Simulink */
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 1);

    if (!ssSetNumInputPorts(S, 1))
        return;
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S, 1))
        return;

    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);
    ssSetOutputPortWidth(S, 0, 1);

    ssSetNumSampleTimes(S, PORT_BASED_SAMPLE_TIMES);

    ssSetInputPortSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetInputPortOffsetTime(S, 0, 0.0);

    ssSetOutputPortSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOutputPortOffsetTime(S, 0, 0.0);

    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 1);
    ssSetNumPWork(S, 0);

    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
    
    ssSetInputPortDataType(S,0,SS_UINT16 );
    ssSetOutputPortDataType(S,0, SS_UINT16);

    ssSetInputPortDirectFeedThrough(S, 0, 1);

    /* specify the sim state compliance to be same as a built-in block */
    ssSetOperatingPointCompliance(S, USE_DEFAULT_OPERATING_POINT);

    /* Set this S-function as runtime thread-safe for multicore execution */
    ssSetRuntimeThreadSafetyCompliance(S, RUNTIME_THREAD_SAFETY_COMPLIANCE_TRUE);

    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

#if defined(MATLAB_MEX_FILE)
#define MDL_SET_INPUT_PORT_WIDTH
static void mdlSetInputPortWidth(SimStruct *S, int_T port,
                                 int_T inputPortWidth)
{
    ssSetInputPortWidth(S, port, inputPortWidth);
    ssSetOutputPortWidth(S, port, 1);
}
//
#define MDL_SET_OUTPUT_PORT_WIDTH
static void mdlSetOutputPortWidth(SimStruct *S, int_T port,
                                  int_T outputPortWidth)
{
    ssSetInputPortWidth(S, port, 0);
    ssSetOutputPortWidth(S, port, 1);
}

#define MDL_SET_INPUT_PORT_SAMPLE_TIME
#if defined(MDL_SET_INPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)
/* Function mdlSetInputPortSampleTime =========================================
 * Abstract:
 *    Set the input port sample time and then set the output port sample time
 *    to the appropriate slower rate or triggered.
 */
static void mdlSetInputPortSampleTime(SimStruct *S,
                                      int_T portIdx,
                                      real_T sampleTime,
                                      real_T offsetTime)
{
    ssSetInputPortSampleTime(S, portIdx, sampleTime);
    ssSetInputPortOffsetTime(S, portIdx, offsetTime);

    /* If the sample and offset are triggered then the block is being 
     * triggered and all of the sample times can be set to triggered.
     *
     * Note that in a different s-function it may be desirable for one
     * or more ports to have constant sample time. That is also permissible. 
     * See the "Constant sample time on ports" demo for information about
     * having a constant port sample time.
     */
    if (ssSampleAndOffsetAreTriggered(sampleTime, offsetTime))
    {
        ssSetOutputPortSampleTime(S, 0, sampleTime);
        ssSetOutputPortOffsetTime(S, 0, offsetTime);
    }
    else
    {
        /* The block is not in a triggered context and so we set the 
         * output port sample time to be a multiple of the input port 
         * sample time
         */
        ssSetOutputPortSampleTime(S, 0, sampleTime / ssGetInputPortWidth(S, 0));
        ssSetOutputPortOffsetTime(S, 0, offsetTime);
    }
}
#endif /* MDL_SET_INPUT_PORT_SAMPLE_TIME */

#define MDL_SET_OUTPUT_PORT_SAMPLE_TIME
#if defined(MDL_SET_OUTPUT_PORT_SAMPLE_TIME) && defined(MATLAB_MEX_FILE)
/* Function mdlSetOutputPortSampleTime =========================================
 * Abstract:
 *    Set the output port sample time and then set the input port sample time
 *    to the appropriate faster rate or triggered.
 */
static void mdlSetOutputPortSampleTime(SimStruct *S,
                                       int_T portIdx,
                                       real_T sampleTime,
                                       real_T offsetTime)
{
    ssSetOutputPortSampleTime(S, portIdx, sampleTime);
    ssSetOutputPortOffsetTime(S, portIdx, offsetTime);

    /* If the sample and offset are triggered then the block is being 
     * triggered and all of the sample times can be set to triggered 
     */
    if (ssSampleAndOffsetAreTriggered(sampleTime, offsetTime))
    {
        ssSetInputPortSampleTime(S, portIdx, sampleTime);
        ssSetInputPortOffsetTime(S, portIdx, offsetTime);
    }
    else
    {
        ssSetInputPortSampleTime(S, portIdx, sampleTime * ssGetOutputPortWidth(S, 0));
        ssSetInputPortOffsetTime(S, portIdx, offsetTime);
    }
}
#endif /* MDL_SET_OUTPUT_PORT_SAMPLE_TIME */

#define MDL_SET_DEFAULT_PORT_DIMENSION_INFO
/* Function: mdlSetDefaultPortDimensionInfo ===========================================
   * Abstract:
   *   In case no ports were specified, the default is an input port of width 2
   *   and an output port of width 1.
   */
static void mdlSetDefaultPortDimensionInfo(SimStruct *S)
{
    ssSetInputPortWidth(S, 0, 2);
    ssSetOutputPortWidth(S, 0, 1);
}
#endif

/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    Specify that we inherit our sample time from the driving block.
 *    However, we don't execute in minor steps.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    real_T sample_in = ssGetInputPortSampleTime(S, 0);
    real_T sample_out = ssGetOutputPortSampleTime(S, 0);

    real_T offset_in = ssGetInputPortOffsetTime(S, 0);
    real_T offset_out = ssGetOutputPortOffsetTime(S, 0);

    if (ssSampleAndOffsetAreTriggered(sample_in, offset_in) &&
        ssSampleAndOffsetAreTriggered(sample_out, offset_out))
    {
        return;
    }

    if (sample_in == CONTINUOUS_SAMPLE_TIME ||
        sample_out == CONTINUOUS_SAMPLE_TIME)
    {
        ssSetErrorStatus(S, "All sample times must be discrete.");
    }

    if (offset_in != 0 || offset_out != 0)
    {
        ssSetErrorStatus(S, "All sample time offsets must be zero.");
    }
    ssSetModelReferenceSampleTimeDefaultInheritance(S);
}

// #if defined(MATLAB_MEX_FILE)
// # define MDL_SET_WORK_WIDTHS
//   static void mdlSetWorkWidths(SimStruct *S)
//   {
//       if (!ssGetInputPortConnected(S,0)) {
//           ssWarning(S,"input is unconnected or grounded, "
//                     "setting input width to 2");
//       }
//       if (!ssGetOutputPortConnected(S,0)) {
//           ssWarning(S,"output is unconnected or terminated");
//       }
//       ssSetNumIWork(S, ssGetInputPortWidth(S,0));
//   }
// #endif /* defined(MATLAB_MEX_FILE) */

#define MDL_START /* Change to #undef to remove function */
#if defined(MDL_START)
/* Function: mdlStart =======================================================
   * Abstract:
   *    This function is called once at start of model execution.
   *    Initialize the IWOrk counter to zero.
   */
static void mdlStart(SimStruct *S)
{
    int_T *IWork = ssGetIWork(S);
    IWork[0] = 0;
}
#endif /*  MDL_START */

/* Function: mdlOutputs =======================================================
 * Abstract:
 *    y = rwork
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    if (ssGetPortBasedSampleTimeBlockIsTriggered(S))
    {
        /* Here we use the triggered algorithm */
        int_T *IWork = ssGetIWork(S);
        int_T maxCount = (int_T)(mxGetPr(ssGetSFcnParam(S, 0))[0]);

        if (IWork[0] == 0)
        {
            InputRealPtrsType port0Inputs = ssGetInputPortRealSignalPtrs(S, 0);
            real_T inputSignal = *port0Inputs[0];
            real_T *y = ssGetOutputPortSignal(S, 0);

            y[0] = inputSignal;
        }
        IWork[0] = (IWork[0] + 1) % maxCount;
    }
    else
    {
        /* Here we make use of the port based sample time algorithm
         * including ssIsSampleHit
         */
        int_T *IWork = ssGetIWork(S);
        int_T maxCount = ssGetInputPortWidth(S, 0);

        int outputTid = ssGetOutputPortSampleTimeIndex(S, 0);
        if (ssIsSampleHit(S, outputTid, tid))
        {
            InputUInt16PtrsType port0Inputs =
                ssGetInputPortSignalPtrs(S, 0);
            uint16_T *y = ssGetOutputPortSignal(S, 0);

            y[0] = *port0Inputs[IWork[0]];

            IWork[0] = (IWork[0] + 1) % maxCount;
        }
    }
}

/* Function: mdlUpdate ========================================================
 * Abstract:
 *    Update the rwork's after each major output has been done.
 */
// #define MDL_UPDATE
// static void mdlUpdate(SimStruct *S, int_T tid)
// {
//     int_T             i;
//     InputRealPtrsType uPtrs  = ssGetInputPortRealSignalPtrs(S,0);
//     int_T             ny     = ssGetOutputPortWidth(S,0);
//     real_T            *rwork = ssGetRWork(S);
//
//     UNUSED_ARG(tid); /* not used in single tasking mode */
//
//     for (i = 0; i < ny; i++) {
//         *rwork++ = *uPtrs[2*i] + *uPtrs[2*i+1];
//     }
// }

/* Function: mdlTerminate =====================================================
 * Abstract:
 *    No termination needed, but we are required to have this routine.
 */
static void mdlTerminate(SimStruct *S)
{
    UNUSED_ARG(S); /* unused input argument */
}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c"  /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif

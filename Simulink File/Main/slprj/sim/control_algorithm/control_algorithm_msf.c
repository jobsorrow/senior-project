#if !defined(S_FUNCTION_NAME)
#define S_FUNCTION_NAME control_algorithm_msf
#endif
#define S_FUNCTION_LEVEL 2
#if !defined(RTW_GENERATED_S_FUNCTION)
#define RTW_GENERATED_S_FUNCTION
#endif
#include <stdio.h>
#include <math.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define rt_logging_h
#include "control_algorithm_types.h"
#include "control_algorithm.h"
#include "control_algorithm_private.h"
real_T rtP_PWM_TIM_BASE_PRD ; real_T rtP_VSI_AMP ; real_T rtP_VSI_FREQ ;
const char * rt_GetMatSignalLoggingFileName ( void ) { return NULL ; } const
char * rt_GetMatSigLogSelectorFileName ( void ) { return NULL ; } void *
rt_GetOSigstreamManager ( void ) { return NULL ; } void * rt_slioCatalogue (
void ) { return NULL ; } void * rtwGetPointerFromUniquePtr ( void * uniquePtr
) { return NULL ; } void * CreateDiagnosticAsVoidPtr ( const char * id , int
nargs , ... ) { void * voidPtrDiagnostic = NULL ; va_list args ; va_start (
args , nargs ) ; slmrCreateDiagnostic ( id , nargs , args , &
voidPtrDiagnostic ) ; va_end ( args ) ; return voidPtrDiagnostic ; } void
rt_ssSet_slErrMsg ( void * S , void * diag ) { SimStruct * simStrcut = (
SimStruct * ) S ; if ( ! _ssIsErrorStatusAslErrMsg ( simStrcut ) ) {
_ssSet_slLocalErrMsg ( simStrcut , diag ) ; } else { _ssDiscardDiagnostic (
simStrcut , diag ) ; } } void rt_ssReportDiagnosticAsWarning ( void * S ,
void * diag ) { _ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; }
void rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } const char *
rt_CreateFullPathToTop ( const char * toppath , const char * subpath ) { char
* fullpath = NULL ; slmrCreateFullPathToTop ( toppath , subpath , & fullpath
) ; return fullpath ; } boolean_T slIsRapidAcceleratorSimulating ( void ) {
return false ; } void rt_RAccelReplaceFromFilename ( const char * blockpath ,
char * fileName ) { ( void ) blockpath ; ( void ) fileName ; } void
rt_RAccelReplaceToFilename ( const char * blockpath , char * fileName ) { (
void ) blockpath ; ( void ) fileName ; } void
slsaCacheDWorkPointerForSimTargetOP ( void * ss , void * * ptr ) { ( void )
ss ; ( void ) ptr ; } void slsaCacheDWorkDataForSimTargetOP ( void * ss ,
void * ptr , unsigned int sizeInBytes ) { ( void ) ss ; ( void ) ptr ; ( void
) sizeInBytes ; } void slsaSaveRawMemoryForSimTargetOP ( void * ss , const
char * key , void * ptr , unsigned int sizeInBytes , void * ( *
customOPSaveFcn ) ( void * dworkPtr , unsigned int * sizeInBytes ) , void ( *
customOPRestoreFcn ) ( void * dworkPtr , const void * data , unsigned int
sizeInBytes ) ) { ( void ) ss ; ( void ) key ; ( void ) ptr ; ( void )
sizeInBytes ; ( void ) customOPSaveFcn ; ( void ) customOPRestoreFcn ; }
#define MDL_PROCESS_PARAMETERS
#if defined(MATLAB_MEX_FILE)
static void mdlProcessParameters ( SimStruct * S ) { real_T * GlobalPrm_0 = (
real_T * ) NULL ; real_T * GlobalPrm_1 = ( real_T * ) NULL ; real_T *
GlobalPrm_2 = ( real_T * ) NULL ; if ( ! ssGetModelRefGlobalParamData ( S , 0
, ( void * * ) ( & GlobalPrm_0 ) ) ) return ; if ( GlobalPrm_0 != NULL ) { (
void ) memcpy ( & ( rtP_PWM_TIM_BASE_PRD ) , GlobalPrm_0 , sizeof ( real_T )
) ; } if ( ! ssGetModelRefGlobalParamData ( S , 1 , ( void * * ) ( &
GlobalPrm_1 ) ) ) return ; if ( GlobalPrm_1 != NULL ) { ( void ) memcpy ( & (
rtP_VSI_AMP ) , GlobalPrm_1 , sizeof ( real_T ) ) ; } if ( !
ssGetModelRefGlobalParamData ( S , 2 , ( void * * ) ( & GlobalPrm_2 ) ) )
return ; if ( GlobalPrm_2 != NULL ) { ( void ) memcpy ( & ( rtP_VSI_FREQ ) ,
GlobalPrm_2 , sizeof ( real_T ) ) ; } }
#endif
static void mdlInitializeConditions ( SimStruct * S ) { eupntxqbkrw * dw = (
eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; hcftxez5uk ( & ( dw -> rtb ) , & ( dw
-> rtdw ) ) ; } static void mdlReset ( SimStruct * S ) { eupntxqbkrw * dw = (
eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; nqhpeemfqd ( & ( dw -> rtb ) , & ( dw
-> rtdw ) ) ; } static void mdlPeriodicOutputUpdate ( SimStruct * S , int_T
tid ) { eupntxqbkrw * dw = ( eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; real_T
const * i_np32kshz4w = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; real_T
const * i_ffougt1xio = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; uint32_T
* o_B_2_1 = ( uint32_T * ) ssGetOutputPortSignal ( S , 0 ) ; if ( tid == 0 )
{ control_algorithm ( & ( dw -> rtm ) , i_np32kshz4w , i_ffougt1xio , o_B_2_1
, & ( dw -> rtb ) , & ( dw -> rtdw ) ) ; p1yivo5bj5 ( & ( dw -> rtdw ) ) ; }
} static void mdlInitializeSizes ( SimStruct * S ) { if ( ( S -> mdlInfo ->
genericFcn != ( NULL ) ) && ( ! ( S -> mdlInfo -> genericFcn ) ( S ,
GEN_FCN_CHK_MODELREF_SFUN_HAS_MODEL_BLOCK , - 1 , ( NULL ) ) ) ) { return ; }
ssSetNumSFcnParams ( S , 0 ) ; ssFxpSetU32BitRegionCompliant ( S , 1 ) ;
rt_InitInfAndNaN ( sizeof ( real_T ) ) ; if ( S -> mdlInfo -> genericFcn != (
NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ; }
ssSetRTWGeneratedSFcn ( S , 2 ) ; ssSetNumContStates ( S , 0 ) ;
ssSetNumDiscStates ( S , 0 ) ; ssSetSymbolicDimsSupport ( S , true ) ;
slmrInitializeIOPortDataVectors ( S , 2 , 1 ) ; if ( ! ssSetNumInputPorts ( S
, 2 ) ) return ; if ( ! ssSetInputPortVectorDimension ( S , 0 , 3 ) ) return
; ssSetInputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 0 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 0 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 0 , 1 ) ; ssSetInputPortOptimOpts ( S
, 0 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 0 ,
false ) ; ssSetInputPortSampleTime ( S , 0 , 5.0E-5 ) ;
ssSetInputPortOffsetTime ( S , 0 , 0.0 ) ; if ( !
ssSetInputPortVectorDimension ( S , 1 , 1 ) ) return ;
ssSetInputPortDimensionsMode ( S , 1 , FIXED_DIMS_MODE ) ;
ssSetInputPortFrameData ( S , 1 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetInputPortDataType ( S , 1 , SS_DOUBLE ) ;
} if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetInputPortUnit ( S , 1 ,
unitIdReg ) ;
#endif
} ssSetInputPortDirectFeedThrough ( S , 1 , 1 ) ;
ssSetInputPortRequiredContiguous ( S , 1 , 1 ) ; ssSetInputPortOptimOpts ( S
, 1 , SS_NOT_REUSABLE_AND_GLOBAL ) ; ssSetInputPortOverWritable ( S , 1 ,
false ) ; ssSetInputPortSampleTime ( S , 1 , 5.0E-5 ) ;
ssSetInputPortOffsetTime ( S , 1 , 0.0 ) ; if ( ! ssSetNumOutputPorts ( S , 1
) ) return ; if ( ! ssSetOutputPortVectorDimension ( S , 0 , 3 ) ) return ;
ssSetOutputPortDimensionsMode ( S , 0 , FIXED_DIMS_MODE ) ;
ssSetOutputPortFrameData ( S , 0 , FRAME_NO ) ; if ( ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { ssSetOutputPortDataType ( S , 0 , SS_UINT32 )
; } if ( ssGetSimMode ( S ) != SS_SIMMODE_SIZES_CALL_ONLY ) {
#if defined (MATLAB_MEX_FILE)
UnitId unitIdReg ; ssRegisterUnitFromExpr ( S , "" , & unitIdReg ) ; if (
unitIdReg == INVALID_UNIT_ID ) return ; ssSetOutputPortUnit ( S , 0 ,
unitIdReg ) ;
#endif
} ssSetOutputPortSampleTime ( S , 0 , 5.0E-5 ) ; ssSetOutputPortOffsetTime (
S , 0 , 0.0 ) ; ssSetOutputPortDiscreteValuedOutput ( S , 0 , 0 ) ;
ssSetOutputPortOkToMerge ( S , 0 , SS_NOT_OK_TO_MERGE ) ;
ssSetOutputPortICAttributes ( S , 0 , false , false , false ) ;
ssSetOutputPortOptimOpts ( S , 0 , SS_NOT_REUSABLE_AND_LOCAL ) ;
ssSetSimStateCompliance ( S , USE_CUSTOM_SIM_STATE ) ;
mr_control_algorithm_RegisterSimStateChecksum ( S ) ; ssSetNumSampleTimes ( S
, PORT_BASED_SAMPLE_TIMES ) ; ssSetParameterTuningCompliance ( S , true ) ;
ssSetNumRWork ( S , 0 ) ; ssSetNumIWork ( S , 0 ) ; ssSetNumPWork ( S , 0 ) ;
ssSetNumModes ( S , 0 ) ; { int_T zcsIdx = 0 ; }
ssSetOutputPortIsNonContinuous ( S , 0 , 0 ) ;
ssSetOutputPortIsFedByBlockWithModesNoZCs ( S , 0 , 0 ) ;
ssSetInputPortIsNotDerivPort ( S , 0 , 1 ) ; ssSetInputPortIsNotDerivPort ( S
, 1 , 1 ) ; ssSetModelReferenceSampleTimeInheritanceRule ( S ,
DISALLOW_SAMPLE_TIME_INHERITANCE ) ; ssSetRuntimeThreadSafetyCompliance ( S ,
RUNTIME_THREAD_SAFETY_COMPLIANCE_TRUE ) ; ssSetAcceptsFcnCallInputs ( S ) ;
ssSetModelReferenceNormalModeSupport ( S ,
MDL_START_AND_MDL_PROCESS_PARAMS_OK ) ; ssSupportsMultipleExecInstances ( S ,
false ) ; ssRegisterMsgForNotSupportingMultiExecInst ( S ,
 "<diag_root><diag id=\"Simulink:blocks:StateflowDataLoggingNotSupported\" pr=\"d\"><arguments><arg type=\"encoded\">YwBvAG4AdAByAG8AbABfAGEAbABnAG8AcgBpAHQAaABtAC8AUwBpAGcAbgBhAGwAIABDAG8AbgBkAGkAdABpAG8AbgBlAHIALwBUAHcAbwAgAEEAcgBtACAATQBvAGQAdQBsAGEAdABvAHIAIABhAG4AZAAgAEYAaQByAHMAdAAgAFEAdQBhAGQAcgBhAG4AdAAgAFQAcgBhAGMAawBlAHIAAAA=</arg><arg type=\"encoded\">PABfAF8AaQBpAFMAUwBfAF8APgA8AC8AXwBfAGkAaQBTAFMAXwBfAD4AAAA=</arg><arg type=\"encoded\">PABfAF8AaQB0AGUAcgBCAGwAawBfAF8APgA8AC8AXwBfAGkAdABlAHIAQgBsAGsAXwBfAD4AAAA=</arg><arg type=\"encoded\">YwBvAG4AdAByAG8AbABfAGEAbABnAG8AcgBpAHQAaABtAC8AUwBpAGcAbgBhAGwAIABDAG8AbgBkAGkAdABpAG8AbgBlAHIALwBUAHcAbwAgAEEAcgBtACAATQBvAGQAdQBsAGEAdABvAHIAIABhAG4AZAAgAEYAaQByAHMAdAAgAFEAdQBhAGQAcgBhAG4AdAAgAFQAcgBhAGMAawBlAHIAAAA=</arg></arguments><hs><h>AAAAQAMIhUBb</h></hs></diag></diag_root>"
) ; ssHasStateInsideForEachSS ( S , false ) ; ssSetOptions ( S ,
SS_OPTION_SUPPORTS_ALIAS_DATA_TYPES | SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME
| SS_OPTION_EXCEPTION_FREE_CODE | SS_OPTION_WORKS_WITH_CODE_REUSE ) ;
#if SS_SFCN_FOR_SIM
if ( S -> mdlInfo -> genericFcn != ( NULL ) && ssGetSimMode ( S ) !=
SS_SIMMODE_SIZES_CALL_ONLY ) { int_T retVal = 1 ;
mr_control_algorithm_MdlInfoRegFcn ( S , "control_algorithm" , & retVal ) ;
if ( ! retVal ) return ; }
#endif
#if SS_SFCN_FOR_SIM
if ( ssSetNumDWork ( S , 1 ) ) { int mdlrefDWTypeId ; ssRegMdlRefDWorkType (
S , & mdlrefDWTypeId ) ; if ( mdlrefDWTypeId == INVALID_DTYPE_ID ) return ;
if ( ! ssSetDataTypeSize ( S , mdlrefDWTypeId , sizeof ( eupntxqbkrw ) ) )
return ; ssSetDWorkDataType ( S , 0 , mdlrefDWTypeId ) ; ssSetDWorkWidth ( S
, 0 , 1 ) ; }
#else
if ( ! ssSetNumDWork ( S , 1 ) ) { return ; }
#endif
slmrRegisterSystemInitializeMethod ( S , mdlInitializeConditions ) ;
slmrRegisterSystemResetMethod ( S , mdlReset ) ;
slmrRegisterPeriodicOutputUpdateMethod ( S , mdlPeriodicOutputUpdate ) ;
ssSetSimulinkVersionGeneratedIn ( S , "10.3" ) ; ssSetNeedAbsoluteTime ( S ,
1 ) ; } static void mdlInitializeSampleTimes ( SimStruct * S ) { return ; }
#define MDL_SET_WORK_WIDTHS
static void mdlSetWorkWidths ( SimStruct * S ) { if ( S -> mdlInfo ->
genericFcn != ( NULL ) ) { _GenericFcn fcn = S -> mdlInfo -> genericFcn ;
ssSetSignalSizesComputeType ( S , SS_VARIABLE_SIZE_FROM_INPUT_VALUE_AND_SIZE
) ; } { static const char * toFileNames [ ] = { "" } ; static const char *
fromFileNames [ ] = { "" } ; if ( ! ssSetModelRefFromFiles ( S , 0 ,
fromFileNames ) ) return ; if ( ! ssSetModelRefToFiles ( S , 0 , toFileNames
) ) return ; } }
#define MDL_SETUP_RUNTIME_RESOURCES
static void mdlSetupRuntimeResources ( SimStruct * S ) { eupntxqbkrw * dw = (
eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; void * sysRanPtr = ( NULL ) ; int
sysTid = 0 ; ssGetContextSysRanBCPtr ( S , & sysRanPtr ) ; ssGetContextSysTid
( S , & sysTid ) ; if ( sysTid == CONSTANT_TID ) { sysTid = 0 ; } fne3us1x3z
( S , slmrGetTopTidFromMdlRefChildTid ( S , 0 , false ) , & ( dw -> rtm ) , &
( dw -> rtb ) , & ( dw -> rtdw ) , sysRanPtr , sysTid , ( NULL ) , ( NULL ) ,
0 , - 1 ) ; ssSetModelMappingInfoPtr ( S , & ( dw -> rtm . DataMapInfo . mmi
) ) ; if ( S -> mdlInfo -> genericFcn != ( NULL ) ) { _GenericFcn fcn = S ->
mdlInfo -> genericFcn ; } kxp4ajlw24 ( & ( dw -> rtm ) , & ( dw -> rtb ) , &
( dw -> rtdw ) ) ; }
#define MDL_START
static void mdlStart ( SimStruct * S ) { mdlProcessParameters ( S ) ; }
#define RTW_GENERATED_ENABLE
static void mdlEnable ( SimStruct * S ) { eupntxqbkrw * dw = ( eupntxqbkrw *
) ssGetDWork ( S , 0 ) ; kcqe4vz0mg ( & ( dw -> rtdw ) ) ; return ; } static
void mdlOutputs ( SimStruct * S , int_T tid ) { int denormalBackup =
_MM_GET_FLUSH_ZERO_MODE ( ) ; _MM_SET_FLUSH_ZERO_MODE ( _MM_FLUSH_ZERO_ON ) ;
eupntxqbkrw * dw = ( eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; real_T const *
i_np32kshz4w = ( real_T * ) ssGetInputPortSignal ( S , 0 ) ; real_T const *
i_ffougt1xio = ( real_T * ) ssGetInputPortSignal ( S , 1 ) ; uint32_T *
o_B_2_1 = ( uint32_T * ) ssGetOutputPortSignal ( S , 0 ) ; if ( tid !=
CONSTANT_TID && tid != PARAMETER_TUNING_TID ) { control_algorithm ( & ( dw ->
rtm ) , i_np32kshz4w , i_ffougt1xio , o_B_2_1 , & ( dw -> rtb ) , & ( dw ->
rtdw ) ) ; } _MM_SET_FLUSH_ZERO_MODE ( denormalBackup ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { eupntxqbkrw * dw = (
eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; p1yivo5bj5 ( & ( dw -> rtdw ) ) ;
return ; } static void mdlTerminate ( SimStruct * S ) { eupntxqbkrw * dw = (
eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; fnxpmbkzrw ( & ( dw -> rtm ) ) ;
return ; }
#define MDL_CLEANUP_RUNTIME_RESOURCES
static void mdlCleanupRuntimeResources ( SimStruct * S ) { eupntxqbkrw * dw =
( eupntxqbkrw * ) ssGetDWork ( S , 0 ) ; mtdeubrpvu ( & ( dw -> rtm ) , & (
dw -> rtdw ) ) ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static mxArray * mdlGetSimState ( SimStruct * S ) { static const char *
simStateFieldNames [ 6 ] = { "localX" , "mdlrefDW" , "disallowedStateData" ,
"tNext" , "tNextTid" , "nonContDerivSigInfoPrevVal" , } ; mxArray * ss =
mxCreateStructMatrix ( 1 , 1 , 6 , simStateFieldNames ) ; { mxArray *
mdlrefDW = mr_control_algorithm_GetDWork ( ssGetDWork ( S , 0 ) ) ;
mxSetFieldByNumber ( ss , 0 , 1 , mdlrefDW ) ; } { mxArray * data =
mr_control_algorithm_GetSimStateDisallowedBlocks ( ) ; mxSetFieldByNumber (
ss , 0 , 2 , data ) ; } ; mxSetFieldByNumber ( ss , 0 , 3 ,
mxCreateDoubleScalar ( ( double ) ssGetTNext ( S ) ) ) ; mxSetFieldByNumber (
ss , 0 , 4 , mxCreateDoubleScalar ( ( double ) ssGetTNextTid ( S ) ) ) ;
return ss ; }
#if !defined(MDL_SIM_STATE)
#define MDL_SIM_STATE
#endif
static void mdlSetSimState ( SimStruct * S , const mxArray * ss ) {
mr_control_algorithm_SetDWork ( ssGetDWork ( S , 0 ) , mxGetFieldByNumber (
ss , 0 , 1 ) ) ; ssSetTNext ( S , ( time_T ) mxGetScalar ( mxGetFieldByNumber
( ss , 0 , 3 ) ) ) ; ssSetTNextTid ( S , ( int_T ) mxGetScalar (
mxGetFieldByNumber ( ss , 0 , 4 ) ) ) ; }
#ifdef MATLAB_MEX_FILE 
#include "simulink.c"
#include "fixedpoint.c"
#else
#error Assertion failed: file must be compiled as a MEX-file
#endif

#include <stddef.h>
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "control_algorithm_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "control_algorithm.h"
#include "control_algorithm_capi.h"
#include "control_algorithm_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_StateflowSignalLoggingInfo rtStateflowChartLoggingInfo [
] = { { "isLowerInQ1" ,
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker"
, "" , 0 , 0 , 0 } , { "isUpperInQ1" ,
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker"
, "" , 0 , 0 , 0 } , { "maxPhase" ,
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker"
, "" , 0 , 0 , 0 } , { "minPhase" ,
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker"
, "" , 0 , 0 , 0 } , { "switchCommand" ,
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker"
, "" , 0 , 0 , 0 } } ; static rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0
, TARGET_STRING (
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker/maxPhase"
) , TARGET_STRING ( "maxPhase" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING (
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker/isLowerInQ1"
) , TARGET_STRING ( "isLowerInQ1" ) , 0 , 1 , 0 , 0 , 0 } , { 2 , 0 ,
TARGET_STRING (
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker/isUpperInQ1"
) , TARGET_STRING ( "isUpperInQ1" ) , 0 , 1 , 0 , 0 , 0 } , { 3 , 0 ,
TARGET_STRING (
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker/minPhase"
) , TARGET_STRING ( "minPhase" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 ,
TARGET_STRING (
 "control_algorithm/Signal Conditioner/Two Arm Modulator and First Quadrant Tracker/switchCommand"
) , TARGET_STRING ( "switchCommand" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , (
NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static rtwCAPI_States
rtBlockStates [ ] = { { 0 , - 1 , ( NULL ) , ( NULL ) , ( NULL ) , 0 , 0 , 0
, 0 , 0 , 0 , - 1 , 0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 }
;
#ifndef HOST_CAPI_BUILD
static void control_algorithm_InitializeDataAddr ( void * dataAddr [ ] ,
f0n4u3x2r4 * localDW ) { dataAddr [ 0 ] = ( void * ) ( & localDW ->
kzrowepidi ) ; dataAddr [ 1 ] = ( void * ) ( & localDW -> dr2md2nzaj ) ;
dataAddr [ 2 ] = ( void * ) ( & localDW -> afapjygekn ) ; dataAddr [ 3 ] = (
void * ) ( & localDW -> alyrnx2p4e ) ; dataAddr [ 4 ] = ( void * ) ( &
localDW -> p0ojj4jft2 ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void control_algorithm_InitializeVarDimsAddr ( int32_T * vardimsAddr [
] ) { vardimsAddr [ 0 ] = ( NULL ) ; }
#endif
#ifndef HOST_CAPI_BUILD
static void control_algorithm_InitializeLoggingFunctions ( RTWLoggingFcnPtr
loggingPtrs [ ] ) { loggingPtrs [ 0 ] = ( NULL ) ; loggingPtrs [ 1 ] = ( NULL
) ; loggingPtrs [ 2 ] = ( NULL ) ; loggingPtrs [ 3 ] = ( NULL ) ; loggingPtrs
[ 4 ] = ( NULL ) ; }
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "int" ,
"int32_T" , 0 , 0 , sizeof ( int32_T ) , SS_INT32 , 0 , 0 , 0 } , {
"unsigned char" , "boolean_T" , 0 , 0 , sizeof ( boolean_T ) , SS_BOOLEAN , 0
, 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static uint_T rtDimensionArray [ ] = { 1 , 1
} ; static const real_T rtcapiStoredFloats [ ] = { 5.0E-5 , 0.0 } ; static
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 1 ] , 0 , 0 } } ; static int_T
rtContextSystems [ 3 ] ; static rtwCAPI_LoggingMetaInfo loggingMetaInfo [ ] =
{ { 0 , 0 , "" , 0 , 0 } , { 1 , 0 , "" , 0 , 0 } , { 2 , 0 , "" , 0 , 0 } ,
{ 3 , 0 , "" , 0 , 0 } , { 4 , 0 , "" , 0 , 0 } } ; static
rtwCAPI_ModelMapLoggingStaticInfo mmiStaticInfoLogging = { 3 ,
rtContextSystems , loggingMetaInfo , 0 , NULL , { 0 , NULL , NULL } , 5 ,
rtStateflowChartLoggingInfo } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 5 , ( NULL ) , 0 , ( NULL ) , 0 } , { ( NULL
) , 0 , ( NULL ) , 0 } , { rtBlockStates , 0 } , { rtDataTypeMap ,
rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap ,
rtDimensionArray } , "float" , { 4269271276U , 2806181115U , 2560057369U ,
438655534U } , & mmiStaticInfoLogging , 0 , 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * control_algorithm_GetCAPIStaticMap (
void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
static void control_algorithm_InitializeSystemRan ( p5ahzaja2d * const
pee42luqnj , sysRanDType * systemRan [ ] , f0n4u3x2r4 * localDW , int_T
systemTid [ ] , void * rootSysRanPtr , int rootTid ) { UNUSED_PARAMETER (
pee42luqnj ) ; UNUSED_PARAMETER ( localDW ) ; systemRan [ 0 ] = ( sysRanDType
* ) rootSysRanPtr ; systemRan [ 1 ] = ( NULL ) ; systemRan [ 2 ] = ( NULL ) ;
systemTid [ 1 ] = pee42luqnj -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [
2 ] = pee42luqnj -> Timing . mdlref_GlobalTID [ 0 ] ; systemTid [ 0 ] =
rootTid ; rtContextSystems [ 0 ] = 0 ; rtContextSystems [ 1 ] = 0 ;
rtContextSystems [ 2 ] = 0 ; }
#endif
#ifndef HOST_CAPI_BUILD
void control_algorithm_InitializeDataMapInfo ( p5ahzaja2d * const pee42luqnj
, f0n4u3x2r4 * localDW , void * sysRanPtr , int contextTid ) {
rtwCAPI_SetVersion ( pee42luqnj -> DataMapInfo . mmi , 1 ) ;
rtwCAPI_SetStaticMap ( pee42luqnj -> DataMapInfo . mmi , & mmiStatic ) ;
rtwCAPI_SetLoggingStaticMap ( pee42luqnj -> DataMapInfo . mmi , &
mmiStaticInfoLogging ) ; control_algorithm_InitializeDataAddr ( pee42luqnj ->
DataMapInfo . dataAddress , localDW ) ; rtwCAPI_SetDataAddressMap (
pee42luqnj -> DataMapInfo . mmi , pee42luqnj -> DataMapInfo . dataAddress ) ;
control_algorithm_InitializeVarDimsAddr ( pee42luqnj -> DataMapInfo .
vardimsAddress ) ; rtwCAPI_SetVarDimsAddressMap ( pee42luqnj -> DataMapInfo .
mmi , pee42luqnj -> DataMapInfo . vardimsAddress ) ; rtwCAPI_SetPath (
pee42luqnj -> DataMapInfo . mmi , ( NULL ) ) ; rtwCAPI_SetFullPath (
pee42luqnj -> DataMapInfo . mmi , ( NULL ) ) ;
control_algorithm_InitializeLoggingFunctions ( pee42luqnj -> DataMapInfo .
loggingPtrs ) ; rtwCAPI_SetLoggingPtrs ( pee42luqnj -> DataMapInfo . mmi ,
pee42luqnj -> DataMapInfo . loggingPtrs ) ; rtwCAPI_SetInstanceLoggingInfo (
pee42luqnj -> DataMapInfo . mmi , & pee42luqnj -> DataMapInfo .
mmiLogInstanceInfo ) ; rtwCAPI_SetChildMMIArray ( pee42luqnj -> DataMapInfo .
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArrayLen ( pee42luqnj -> DataMapInfo .
mmi , 0 ) ; control_algorithm_InitializeSystemRan ( pee42luqnj , pee42luqnj
-> DataMapInfo . systemRan , localDW , pee42luqnj -> DataMapInfo . systemTid
, sysRanPtr , contextTid ) ; rtwCAPI_SetSystemRan ( pee42luqnj -> DataMapInfo
. mmi , pee42luqnj -> DataMapInfo . systemRan ) ; rtwCAPI_SetSystemTid (
pee42luqnj -> DataMapInfo . mmi , pee42luqnj -> DataMapInfo . systemTid ) ;
rtwCAPI_SetGlobalTIDMap ( pee42luqnj -> DataMapInfo . mmi , & pee42luqnj ->
Timing . mdlref_GlobalTID [ 0 ] ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void control_algorithm_host_InitializeDataMapInfo (
control_algorithm_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif

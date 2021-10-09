#ifndef RTW_HEADER_control_algorithm_h_
#define RTW_HEADER_control_algorithm_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap_simtarget.h"
#ifndef control_algorithm_COMMON_INCLUDES_
#define control_algorithm_COMMON_INCLUDES_
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "sf_runtime/sfc_sdi.h"
#endif
#include "control_algorithm_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_nonfinite.h"
typedef struct { real_T eiy0nd5lb0 ; } danotryi1w ; typedef struct {
sdiBlockID_t bp0gecfdi0 ; SignalExportStruct hqrw0con5a ; SignalExportStruct
omczrmjyh0 ; SignalExportStruct l2twyyzmpv ; SignalExportStruct ivsirucbty ;
SignalExportStruct hxabpgiu5e ; SignalExportStruct fimwnuarzz ;
SignalExportStruct h3sxrutbzd ; SignalExportStruct eu342jpw2a ;
SignalExportStruct pvjbtk5nng ; SignalExportStruct lzysoby01f ;
SignalExportStruct ghv5szcml5 ; SignalExportStruct c5xhn3ktul ;
SignalExportStruct dydu14zar0 ; SignalExportStruct hf3qguykfm ; real_T
hirsn11jpx ; real_T gra4l3ublw ; real_T mb0q4sfh2b ; real_T myz450mv2l ;
real_T izlbj1dnen ; real_T hdotu5beci ; real_T cgz3h0bptv ; struct { void *
AQHandles ; } neh4vsuexe ; struct { void * AQHandles ; } mcdkrxrkbq ; struct
{ void * AQHandles ; } pstwraz5ju ; struct { void * AQHandles ; } oqquzlftij
; struct { void * AQHandles ; } lbbe0xlagn ; void * lphu5azhng [ 5 ] ;
int32_T efsxjuqyyr ; int32_T dice0dlxd0 ; int32_T gejx2gzvwi ; int32_T
kzrowepidi ; int32_T alyrnx2p4e ; int32_T p0ojj4jft2 ; uint8_T bdwnyjohnx ;
uint8_T exkiwazazx ; uint8_T eipcku5lat [ 7 ] ; uint8_T j420mi1g4w [ 11 ] ;
boolean_T dr2md2nzaj ; boolean_T afapjygekn ; boolean_T ksxpsc1140 ; }
f0n4u3x2r4 ; struct ke4pd1dadxw_ { real_T P_3 ; real_T P_4 ; real_T P_5 ;
real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ; real_T P_10 ; real_T P_11
; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T P_15 ; real_T P_16 ;
real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ; } ; struct gft1dpw31n
{ struct SimStruct_tag * _mdlRefSfcnS ; struct { rtwCAPI_ModelMappingInfo mmi
; rtwCAPI_ModelMapLoggingInstanceInfo mmiLogInstanceInfo ; void * dataAddress
[ 5 ] ; int32_T * vardimsAddress [ 5 ] ; RTWLoggingFcnPtr loggingPtrs [ 5 ] ;
sysRanDType * systemRan [ 3 ] ; int_T systemTid [ 3 ] ; } DataMapInfo ;
struct { int_T mdlref_GlobalTID [ 1 ] ; } Timing ; } ; typedef struct {
danotryi1w rtb ; f0n4u3x2r4 rtdw ; p5ahzaja2d rtm ; } eupntxqbkrw ; extern
real_T rtP_PWM_TIM_BASE_PRD ; extern real_T rtP_VSI_AMP ; extern real_T
rtP_VSI_FREQ ; extern void fne3us1x3z ( SimStruct * _mdlRefSfcnS , int_T
mdlref_TID0 , p5ahzaja2d * const pee42luqnj , danotryi1w * localB ,
f0n4u3x2r4 * localDW , void * sysRanPtr , int contextTid ,
rtwCAPI_ModelMappingInfo * rt_ParentMMI , const char_T * rt_ChildPath , int_T
rt_ChildMMIIdx , int_T rt_CSTATEIdx ) ; extern void
mr_control_algorithm_MdlInfoRegFcn ( SimStruct * mdlRefSfcnS , char_T *
modelName , int_T * retVal ) ; extern mxArray * mr_control_algorithm_GetDWork
( const eupntxqbkrw * mdlrefDW ) ; extern void mr_control_algorithm_SetDWork
( eupntxqbkrw * mdlrefDW , const mxArray * ssDW ) ; extern void
mr_control_algorithm_RegisterSimStateChecksum ( SimStruct * S ) ; extern
mxArray * mr_control_algorithm_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * control_algorithm_GetCAPIStaticMap ( void )
; extern void kxp4ajlw24 ( p5ahzaja2d * const pee42luqnj , danotryi1w *
localB , f0n4u3x2r4 * localDW ) ; extern void hcftxez5uk ( danotryi1w *
localB , f0n4u3x2r4 * localDW ) ; extern void nqhpeemfqd ( danotryi1w *
localB , f0n4u3x2r4 * localDW ) ; extern void kcqe4vz0mg ( f0n4u3x2r4 *
localDW ) ; extern void mtdeubrpvu ( p5ahzaja2d * const pee42luqnj ,
f0n4u3x2r4 * localDW ) ; extern void p1yivo5bj5 ( f0n4u3x2r4 * localDW ) ;
extern void control_algorithm ( p5ahzaja2d * const pee42luqnj , const real_T
lhxmxwpdvw [ 3 ] , const real_T * giaopiymit , uint32_T alqhpn24ud [ 3 ] ,
danotryi1w * localB , f0n4u3x2r4 * localDW ) ; extern void fnxpmbkzrw (
p5ahzaja2d * const pee42luqnj ) ;
#endif

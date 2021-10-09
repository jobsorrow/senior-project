/*
 * File: control_algorithm_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "control_algorithm_ca.h"

CA_HWImpl_TestResults CA_control_algorithm_HWRes;
CA_PWS_TestResults CA_control_algorithm_PWSRes;
const CA_HWImpl CA_control_algorithm_ExpHW = {

#ifdef PORTABLE_WORDSIZES

  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#else

  16,                                  /* BitPerChar */
  16,                                  /* BitPerShort */
  16,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#endif

  1,                                   /* LongLongMode */
  1,                                   /* PortableWordSizes */
  "Texas Instruments->C2000",          /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  1,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_control_algorithm_ActHW;
void control_algorithm_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_control_algorithm_ActHW,
    &CA_control_algorithm_ExpHW, &CA_control_algorithm_PWSRes);
  caVerifyHWImpl(&CA_control_algorithm_ActHW, &CA_control_algorithm_ExpHW,
                 &CA_control_algorithm_HWRes);
}

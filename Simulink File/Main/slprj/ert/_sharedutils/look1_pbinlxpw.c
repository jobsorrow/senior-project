/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: look1_pbinlxpw.c
 *
 * Code generated for Simulink model 'model_in_the_loop'.
 *
 * Model version                  : 1.36
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Sun Oct 10 00:32:40 2021
 */

#include "rtwtypes.h"
#include "look1_pbinlxpw.h"

real_T look1_pbinlxpw(real_T u0, const real_T bp0[], const real_T table[],
                      uint32_T prevIndex[], uint32_T maxIndex)
{
  real_T frac;
  real_T yL_0d0;
  uint32_T bpIdx;
  uint32_T found;
  uint32_T iLeft;
  uint32_T iRght;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0UL]) {
    bpIdx = 0UL;
    frac = (u0 - bp0[0UL]) / (bp0[1UL] - bp0[0UL]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search using Previous Index */
    bpIdx = prevIndex[0UL];
    iLeft = 0UL;
    iRght = maxIndex;
    found = 0UL;
    while (found == 0UL) {
      if (u0 < bp0[bpIdx]) {
        iRght = (uint32_T)(bpIdx - 1UL);
        bpIdx = (uint32_T)((uint32_T)((uint32_T)(bpIdx + iLeft) - 1UL) >> 1UL);
      } else if (u0 < bp0[(uint32_T)(bpIdx + 1UL)]) {
        found = 1UL;
      } else {
        iLeft = (uint32_T)(bpIdx + 1UL);
        bpIdx = (uint32_T)((uint32_T)((uint32_T)(bpIdx + iRght) + 1UL) >> 1UL);
      }
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[(uint32_T)(bpIdx + 1UL)] - bp0[bpIdx]);
  } else {
    bpIdx = (uint32_T)(maxIndex - 1UL);
    frac = (u0 - bp0[(uint32_T)(maxIndex - 1UL)]) / (bp0[maxIndex] - bp0
      [(uint32_T)(maxIndex - 1UL)]);
  }

  prevIndex[0UL] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[bpIdx];
  return (table[(uint32_T)(bpIdx + 1UL)] - yL_0d0) * frac + yL_0d0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */

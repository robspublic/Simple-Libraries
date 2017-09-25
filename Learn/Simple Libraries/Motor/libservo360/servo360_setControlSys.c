/*
  @file servo360_setControlSys.c

  @author Parallax Inc

  @copyright
  Copyright (C) Parallax Inc. 2017. All Rights MIT Licensed.  See end of file.
 
  @brief 
*/


#include "simpletools.h"  
#include "servo360.h"

int servo360_setControlSys(int pin, int constant, int value)
{
  if(!servoCog) servo360_run();
  int p = servo360_findServoIndex(pin);
  if(p == -1)return -1;
  
  switch(constant)
  {
    case S360_KPV:
      fb[p].KpV = value;
      break;
    case S360_KIV:
      fb[p].KiV = value;
      break;
    case S360_KDV:
      fb[p].KdV = value;
      break;
    case S360_IV_MAX:
      fb[p].iMaxV = value;
      fb[p].iMinV = -value;
      break;
    case S360_KPA:
      fb[p].Kp = value;
      break;
    case S360_KIA:
      fb[p].Ki = value;
      break;
    case S360_KDA:
      fb[p].Kd = value;
      break;
    case S360_IA_MAX:
      fb[p].iMax = value;
      fb[p].iMin = -value;
      break;
  }  
}    


/**
 * TERMS OF USE: MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */
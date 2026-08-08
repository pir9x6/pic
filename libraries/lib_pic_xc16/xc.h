/*
 *  Generic include file for XC16
 *
 *  Copyright 2020 Microchip Technology
 */

/*-------------------------------------------------------------------------
 * (c) Copyright 1999-2020 Microchip Technology, All rights reserved
 *
 * This software is developed by Microchip Technology Inc. and its
 * subsidiaries ("Microchip").
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1.      Redistributions of source code must retain the above copyright
 *         notice, this list of conditions and the following disclaimer.
 * 2.      Redistributions in binary form must reproduce the above
 *         copyright notice, this list of conditions and the following
 *         disclaimer in the documentation and/or other materials provided
 *         with the distribution. Publication is not required when
 *         this file is used in an embedded application.
 * 3.      Microchip's name may not be used to endorse or promote products
 *         derived from this software without specific prior written
 *         permission.
 *
 * THIS SOFTWARE IS PROVIDED BY MICROCHIP "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL MICROCHIP BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING BUT NOT LIMITED TO
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWSOEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


#ifndef _XC_H
#define _XC_H

#if __XC16_VERSION__ >= 1059
#include <builtins.h>
#endif

/* ---------------------------------------------------------- */
/* Some useful macros for inline assembler instructions       */
/* ---------------------------------------------------------- */

#define Nop()    __builtin_nop()
#define ClrWdt() __builtin_clrwdt()
#define Sleep()  __builtin_pwrsav(0)
#define Idle()   __builtin_pwrsav(1)

#if defined(__PIC24HJ128GP202__)
#include <p24HJ128GP202.h>
#endif

#if defined(__PIC24HJ128GP204__)
#include <p24HJ128GP204.h>
#endif

#if defined(__PIC24HJ128GP206__)
#include <p24HJ128GP206.h>
#endif

#if defined(__PIC24HJ128GP206A__)
#include <p24HJ128GP206A.h>
#endif

#if defined(__PIC24HJ128GP210__)
#include <p24HJ128GP210.h>
#endif

#if defined(__PIC24HJ128GP210A__)
#include <p24HJ128GP210A.h>
#endif

#if defined(__PIC24HJ128GP306__)
#include <p24HJ128GP306.h>
#endif

#if defined(__PIC24HJ128GP306A__)
#include <p24HJ128GP306A.h>
#endif

#if defined(__PIC24HJ128GP310__)
#include <p24HJ128GP310.h>
#endif

#if defined(__PIC24HJ128GP310A__)
#include <p24HJ128GP310A.h>
#endif

#if defined(__PIC24HJ128GP502__)
#include <p24HJ128GP502.h>
#endif

#if defined(__PIC24HJ128GP504__)
#include <p24HJ128GP504.h>
#endif

#if defined(__PIC24HJ128GP506__)
#include <p24HJ128GP506.h>
#endif

#if defined(__PIC24HJ128GP506A__)
#include <p24HJ128GP506A.h>
#endif

#if defined(__PIC24HJ128GP510__)
#include <p24HJ128GP510.h>
#endif

#if defined(__PIC24HJ128GP510A__)
#include <p24HJ128GP510A.h>
#endif

#if defined(__PIC24HJ12GP201__)
#include <p24HJ12GP201.h>
#endif

#if defined(__PIC24HJ12GP202__)
#include <p24HJ12GP202.h>
#endif

#if defined(__PIC24HJ16GP304__)
#include <p24HJ16GP304.h>
#endif

#if defined(__PIC24HJ256GP206__)
#include <p24HJ256GP206.h>
#endif

#if defined(__PIC24HJ256GP206A__)
#include <p24HJ256GP206A.h>
#endif

#if defined(__PIC24HJ256GP210__)
#include <p24HJ256GP210.h>
#endif

#if defined(__PIC24HJ256GP210A__)
#include <p24HJ256GP210A.h>
#endif

#if defined(__PIC24HJ256GP610__)
#include <p24HJ256GP610.h>
#endif

#if defined(__PIC24HJ256GP610A__)
#include <p24HJ256GP610A.h>
#endif

#if defined(__PIC24HJ32GP202__)
#include <p24HJ32GP202.h>
#endif

#if defined(__PIC24HJ32GP204__)
#include <p24HJ32GP204.h>
#endif

#if defined(__PIC24HJ32GP302__)
#include <p24HJ32GP302.h>
#endif

#if defined(__PIC24HJ32GP304__)
#include <p24HJ32GP304.h>
#endif

#if defined(__PIC24HJ64GP202__)
#include <p24HJ64GP202.h>
#endif

#if defined(__PIC24HJ64GP204__)
#include <p24HJ64GP204.h>
#endif

#if defined(__PIC24HJ64GP206__)
#include <p24HJ64GP206.h>
#endif

#if defined(__PIC24HJ64GP206A__)
#include <p24HJ64GP206A.h>
#endif

#if defined(__PIC24HJ64GP210__)
#include <p24HJ64GP210.h>
#endif

#if defined(__PIC24HJ64GP210A__)
#include <p24HJ64GP210A.h>
#endif

#if defined(__PIC24HJ64GP502__)
#include <p24HJ64GP502.h>
#endif

#if defined(__PIC24HJ64GP504__)
#include <p24HJ64GP504.h>
#endif

#if defined(__PIC24HJ64GP506__)
#include <p24HJ64GP506.h>
#endif

#if defined(__PIC24HJ64GP506A__)
#include <p24HJ64GP506A.h>
#endif

#if defined(__PIC24HJ64GP510__)
#include <p24HJ64GP510.h>
#endif

#if defined(__PIC24HJ64GP510A__)
#include <p24HJ64GP510A.h>
#endif

#if defined(__dsPIC33FJ128GP202__)
#include <p33FJ128GP202.h>
#endif

#if defined(__dsPIC33FJ128GP204__)
#include <p33FJ128GP204.h>
#endif

#if defined(__dsPIC33FJ128GP206__)
#include <p33FJ128GP206.h>
#endif

#if defined(__dsPIC33FJ128GP206A__)
#include <p33FJ128GP206A.h>
#endif

#if defined(__dsPIC33FJ128GP306__)
#include <p33FJ128GP306.h>
#endif

#if defined(__dsPIC33FJ128GP306A__)
#include <p33FJ128GP306A.h>
#endif

#if defined(__dsPIC33FJ128GP310__)
#include <p33FJ128GP310.h>
#endif

#if defined(__dsPIC33FJ128GP310A__)
#include <p33FJ128GP310A.h>
#endif

#if defined(__dsPIC33FJ128GP706__)
#include <p33FJ128GP706.h>
#endif

#if defined(__dsPIC33FJ128GP706A__)
#include <p33FJ128GP706A.h>
#endif

#if defined(__dsPIC33FJ128GP708__)
#include <p33FJ128GP708.h>
#endif

#if defined(__dsPIC33FJ128GP708A__)
#include <p33FJ128GP708A.h>
#endif

#if defined(__dsPIC33FJ128GP710__)
#include <p33FJ128GP710.h>
#endif

#if defined(__dsPIC33FJ128GP710A__)
#include <p33FJ128GP710A.h>
#endif

#if defined(__dsPIC33FJ128GP802__)
#include <p33FJ128GP802.h>
#endif

#if defined(__dsPIC33FJ128GP804__)
#include <p33FJ128GP804.h>
#endif

#if defined(__dsPIC33FJ128MC202__)
#include <p33FJ128MC202.h>
#endif

#if defined(__dsPIC33FJ128MC204__)
#include <p33FJ128MC204.h>
#endif

#if defined(__dsPIC33FJ128MC506__)
#include <p33FJ128MC506.h>
#endif

#if defined(__dsPIC33FJ128MC506A__)
#include <p33FJ128MC506A.h>
#endif

#if defined(__dsPIC33FJ128MC510__)
#include <p33FJ128MC510.h>
#endif

#if defined(__dsPIC33FJ128MC510A__)
#include <p33FJ128MC510A.h>
#endif

#if defined(__dsPIC33FJ128MC706__)
#include <p33FJ128MC706.h>
#endif

#if defined(__dsPIC33FJ128MC706A__)
#include <p33FJ128MC706A.h>
#endif

#if defined(__dsPIC33FJ128MC708__)
#include <p33FJ128MC708.h>
#endif

#if defined(__dsPIC33FJ128MC708A__)
#include <p33FJ128MC708A.h>
#endif

#if defined(__dsPIC33FJ128MC710__)
#include <p33FJ128MC710.h>
#endif

#if defined(__dsPIC33FJ128MC710A__)
#include <p33FJ128MC710A.h>
#endif

#if defined(__dsPIC33FJ128MC802__)
#include <p33FJ128MC802.h>
#endif

#if defined(__dsPIC33FJ128MC804__)
#include <p33FJ128MC804.h>
#endif

#if defined(__dsPIC33FJ12GP201__)
#include <p33FJ12GP201.h>
#endif

#if defined(__dsPIC33FJ12GP202__)
#include <p33FJ12GP202.h>
#endif

#if defined(__dsPIC33FJ12MC201__)
#include <p33FJ12MC201.h>
#endif

#if defined(__dsPIC33FJ12MC202__)
#include <p33FJ12MC202.h>
#endif

#if defined(__dsPIC33FJ16GP101__)
#include <p33FJ16GP101.h>
#endif

#if defined(__dsPIC33FJ16GP102__)
#include <p33FJ16GP102.h>
#endif

#if defined(__dsPIC33FJ16GP304__)
#include <p33FJ16GP304.h>
#endif

#if defined(__dsPIC33FJ16MC101__)
#include <p33FJ16MC101.h>
#endif

#if defined(__dsPIC33FJ16MC102__)
#include <p33FJ16MC102.h>
#endif

#if defined(__dsPIC33FJ16MC304__)
#include <p33FJ16MC304.h>
#endif

#if defined(__dsPIC33FJ256GP506__)
#include <p33FJ256GP506.h>
#endif

#if defined(__dsPIC33FJ256GP506A__)
#include <p33FJ256GP506A.h>
#endif

#if defined(__dsPIC33FJ256GP510__)
#include <p33FJ256GP510.h>
#endif

#if defined(__dsPIC33FJ256GP510A__)
#include <p33FJ256GP510A.h>
#endif

#if defined(__dsPIC33FJ256GP710__)
#include <p33FJ256GP710.h>
#endif

#if defined(__dsPIC33FJ256GP710A__)
#include <p33FJ256GP710A.h>
#endif

#if defined(__dsPIC33FJ256MC510__)
#include <p33FJ256MC510.h>
#endif

#if defined(__dsPIC33FJ256MC510A__)
#include <p33FJ256MC510A.h>
#endif

#if defined(__dsPIC33FJ256MC710__)
#include <p33FJ256MC710.h>
#endif

#if defined(__dsPIC33FJ256MC710A__)
#include <p33FJ256MC710A.h>
#endif

#if defined(__dsPIC33FJ32GP101__)
#include <p33FJ32GP101.h>
#endif

#if defined(__dsPIC33FJ32GP102__)
#include <p33FJ32GP102.h>
#endif

#if defined(__dsPIC33FJ32GP104__)
#include <p33FJ32GP104.h>
#endif

#if defined(__dsPIC33FJ32GP202__)
#include <p33FJ32GP202.h>
#endif

#if defined(__dsPIC33FJ32GP204__)
#include <p33FJ32GP204.h>
#endif

#if defined(__dsPIC33FJ32GP302__)
#include <p33FJ32GP302.h>
#endif

#if defined(__dsPIC33FJ32GP304__)
#include <p33FJ32GP304.h>
#endif

#if defined(__dsPIC33FJ32MC101__)
#include <p33FJ32MC101.h>
#endif

#if defined(__dsPIC33FJ32MC102__)
#include <p33FJ32MC102.h>
#endif

#if defined(__dsPIC33FJ32MC104__)
#include <p33FJ32MC104.h>
#endif

#if defined(__dsPIC33FJ32MC202__)
#include <p33FJ32MC202.h>
#endif

#if defined(__dsPIC33FJ32MC204__)
#include <p33FJ32MC204.h>
#endif

#if defined(__dsPIC33FJ32MC302__)
#include <p33FJ32MC302.h>
#endif

#if defined(__dsPIC33FJ32MC304__)
#include <p33FJ32MC304.h>
#endif

#if defined(__dsPIC33FJ64GP202__)
#include <p33FJ64GP202.h>
#endif

#if defined(__dsPIC33FJ64GP204__)
#include <p33FJ64GP204.h>
#endif

#if defined(__dsPIC33FJ64GP206__)
#include <p33FJ64GP206.h>
#endif

#if defined(__dsPIC33FJ64GP206A__)
#include <p33FJ64GP206A.h>
#endif

#if defined(__dsPIC33FJ64GP306__)
#include <p33FJ64GP306.h>
#endif

#if defined(__dsPIC33FJ64GP306A__)
#include <p33FJ64GP306A.h>
#endif

#if defined(__dsPIC33FJ64GP310__)
#include <p33FJ64GP310.h>
#endif

#if defined(__dsPIC33FJ64GP310A__)
#include <p33FJ64GP310A.h>
#endif

#if defined(__dsPIC33FJ64GP706__)
#include <p33FJ64GP706.h>
#endif

#if defined(__dsPIC33FJ64GP706A__)
#include <p33FJ64GP706A.h>
#endif

#if defined(__dsPIC33FJ64GP708__)
#include <p33FJ64GP708.h>
#endif

#if defined(__dsPIC33FJ64GP708A__)
#include <p33FJ64GP708A.h>
#endif

#if defined(__dsPIC33FJ64GP710__)
#include <p33FJ64GP710.h>
#endif

#if defined(__dsPIC33FJ64GP710A__)
#include <p33FJ64GP710A.h>
#endif

#if defined(__dsPIC33FJ64GP802__)
#include <p33FJ64GP802.h>
#endif

#if defined(__dsPIC33FJ64GP804__)
#include <p33FJ64GP804.h>
#endif

#if defined(__dsPIC33FJ64MC202__)
#include <p33FJ64MC202.h>
#endif

#if defined(__dsPIC33FJ64MC204__)
#include <p33FJ64MC204.h>
#endif

#if defined(__dsPIC33FJ64MC506__)
#include <p33FJ64MC506.h>
#endif

#if defined(__dsPIC33FJ64MC506A__)
#include <p33FJ64MC506A.h>
#endif

#if defined(__dsPIC33FJ64MC508__)
#include <p33FJ64MC508.h>
#endif

#if defined(__dsPIC33FJ64MC508A__)
#include <p33FJ64MC508A.h>
#endif

#if defined(__dsPIC33FJ64MC510__)
#include <p33FJ64MC510.h>
#endif

#if defined(__dsPIC33FJ64MC510A__)
#include <p33FJ64MC510A.h>
#endif

#if defined(__dsPIC33FJ64MC706__)
#include <p33FJ64MC706.h>
#endif

#if defined(__dsPIC33FJ64MC706A__)
#include <p33FJ64MC706A.h>
#endif

#if defined(__dsPIC33FJ64MC710__)
#include <p33FJ64MC710.h>
#endif

#if defined(__dsPIC33FJ64MC710A__)
#include <p33FJ64MC710A.h>
#endif

#if defined(__dsPIC33FJ64MC802__)
#include <p33FJ64MC802.h>
#endif

#if defined(__dsPIC33FJ64MC804__)
#include <p33FJ64MC804.h>
#endif

#endif /* <xc.h> included. */

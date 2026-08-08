/*-------------------------------------------------------------------------
 * (c) Copyright 1999-2026 Microchip Technology, All rights reserved
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

#include <stdint.h>

void __builtin_write_OSCCONL( 
        unsigned char);
void __builtin_write_OSCCONH( 
        unsigned char);
void __builtin_write_DISICNT( 
        uint16_t);
void __builtin_write_NVM( 
        void);
void __builtin_write_CRYOTP( 
        void);
void __builtin_write_DATAFLASH( 
        void);
void __builtin_write_NVM_secure( 
        uint16_t,
        uint16_t);
void __builtin_write_DATAFLASH_secure( 
        uint16_t,
        uint16_t);
void __builtin_write_RTCWEN( 
        void);
void __builtin_write_RTCC_WRLOCK( 
        void);
void __builtin_write_PWMSFR( 
        volatile uint16_t *,
        uint16_t,
        volatile uint16_t *);
void __builtin_write_RPCON( 
        uint16_t);
uint16_t __builtin_readsfr( 
        volatile void *);
void __builtin_writesfr( 
        volatile void *,
        uint16_t);
#ifndef __XC_STRICT_MISRA
uint16_t __builtin_edspage();
uint16_t __builtin_tblpage();
uint16_t __builtin_edsoffset();
uint16_t __builtin_dataflashoffset();
uint16_t __builtin_tbloffset();
uint16_t __builtin_psvpage();
uint16_t __builtin_psvoffset();
uint16_t __builtin_dmaoffset();
uint16_t __builtin_dmapage();
uint32_t __builtin_tbladdress();
#endif
void __builtin_nop( 
        void);
int16_t __builtin_divsd( 
        const int32_t,
        const int16_t);
int16_t __builtin_modsd( 
        const int32_t,
        const int16_t);
int16_t __builtin_divmodsd( 
        const int32_t,
        const int16_t,
        int16_t *);
uint16_t __builtin_divud( 
        const uint32_t,
        const uint16_t);
uint16_t __builtin_modud( 
        const uint32_t,
        const uint16_t);
uint16_t __builtin_divmodud( 
        const uint32_t,
        const uint16_t,
        uint16_t *);
int16_t __builtin_divf( 
        int16_t,
        int16_t);
int32_t __builtin_mulss( 
        const int16_t,
        const int16_t);
uint32_t __builtin_muluu( 
        const uint16_t,
        const uint16_t);
int32_t __builtin_mulsu( 
        const int16_t,
        const uint16_t);
int32_t __builtin_mulus( 
        const uint16_t,
        const int16_t);
void __builtin_btg( 
        uint16_t *,
        const uint16_t);
void __builtin_btg_8( 
        volatile unsigned char *,
        const uint16_t);
void __builtin_btg_16( 
        volatile uint16_t *,
        const uint16_t);
void __builtin_btg_32( 
        volatile uint32_t *,
        const uint16_t);
int16_t __builtin_addab( 
        int16_t,
        int16_t);
int16_t __builtin_add( 
        int16_t,
        int16_t,
        int16_t);
int16_t __builtin_add_16( 
        int16_t,
        int16_t,
        int16_t);
int16_t __builtin_clr( 
        void);
int16_t __builtin_clr_prefetch( 
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t *,
        int16_t);
int16_t __builtin_ed( 
        int16_t,
        int16_t * *,
        int16_t,
        int16_t * *,
        int16_t,
        int16_t *);
int16_t __builtin_edac( 
        int16_t,
        int16_t,
        int16_t * *,
        int16_t,
        int16_t * *,
        int16_t,
        int16_t *);
int16_t __builtin_lac( 
        int16_t,
        int16_t);
int16_t __builtin_lac_16( 
        int16_t,
        int16_t);
int16_t __builtin_lac_32( 
        int32_t,
        int32_t);
int16_t __builtin_lacd( 
        int32_t,
        int16_t);
int16_t __builtin_mac( 
        int16_t,
        int16_t,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t *,
        int16_t);
int16_t __builtin_mac_16( 
        int16_t,
        int16_t,
        int16_t);
void __builtin_movsac( 
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t *,
        int16_t);
int16_t __builtin_mpy( 
        int16_t,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t);
int16_t __builtin_mpy_16( 
        int16_t,
        int16_t);
int16_t __builtin_mpyn( 
        int16_t,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t);
int16_t __builtin_mpyn_16( 
        int16_t,
        int16_t);
int16_t __builtin_msc( 
        int16_t,
        int16_t,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t * *,
        int16_t *,
        int16_t,
        int16_t *,
        int16_t);
int16_t __builtin_msc_16( 
        int16_t,
        int16_t,
        int16_t);
int16_t __builtin_sac( 
        int16_t,
        int16_t);
int16_t __builtin_sac_16( 
        int16_t,
        int16_t);
int32_t __builtin_sac_32( 
        int16_t,
        int16_t);
int32_t __builtin_sacd( 
        int16_t,
        int16_t);
int16_t __builtin_sacr( 
        int16_t,
        int16_t);
int16_t __builtin_sacr_16( 
        int16_t,
        int16_t);
int16_t __builtin_sftac( 
        int16_t,
        int16_t);
int16_t __builtin_subab( 
        int16_t,
        int16_t);
int16_t __builtin_ACCL( 
        int16_t);
int16_t __builtin_ACCH( 
        int16_t);
int16_t __builtin_ACCU( 
        int16_t);
uint16_t __builtin_tblrdl( 
        uint16_t);
uint16_t __builtin_tblrdh( 
        uint16_t);
unsigned char __builtin_tblrdhb( 
        uint16_t);
unsigned char __builtin_tblrdlb( 
        uint16_t);
void __builtin_tblwtl( 
        uint16_t,
        uint16_t);
void __builtin_tblwth( 
        uint16_t,
        uint16_t);
void __builtin_tblwtlb( 
        uint16_t,
        unsigned char);
void __builtin_tblwthb( 
        uint16_t,
        unsigned char);
void __builtin_disi( 
        int16_t);
uint32_t __builtin_section_begin( 
        const char *);
uint32_t __builtin_section_size( 
        const char *);
uint32_t __builtin_section_end( 
        const char *);
uint16_t __builtin_get_isr_state( 
        void);
void __builtin_set_isr_state( 
        uint16_t);
void __builtin_disable_interrupts( 
        void);
void __builtin_enable_interrupts( 
        void);
void __builtin_software_breakpoint( 
        void);
void __builtin_software_reset( 
        void);
#ifndef __XC_STRICT_MISRA
uint16_t __builtin_addr_low();
uint16_t __builtin_addr_high();
uint32_t __builtin_addr();
#endif
void __builtin_pwrsav( 
        uint16_t);
void __builtin_clrwdt( 
        void);
int16_t __builtin_fbcl( 
        int16_t);
uint16_t __builtin_ff1l( 
        uint16_t);
uint16_t __builtin_ff1r( 
        uint16_t);
int16_t __builtin_fbcl_16( 
        int16_t);
uint16_t __builtin_ff1l_16( 
        uint16_t);
uint16_t __builtin_ff1r_16( 
        uint16_t);
uint16_t __builtin_swap( 
        uint16_t);
unsigned char __builtin_swap_byte( 
        unsigned char);
unsigned char __builtin_swap_8( 
        unsigned char);
uint16_t __builtin_swap_16( 
        uint16_t);
int16_t __builtin_flim( 
        int16_t,
        int16_t,
        int16_t);
int16_t __builtin_flim_excess( 
        int16_t,
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_flimv_excess( 
        int16_t,
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_flim_16( 
        int16_t,
        int16_t,
        int16_t);
int16_t __builtin_flim_excess_16( 
        int16_t,
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_flimv_excess_16( 
        int16_t,
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_min( 
        int16_t,
        int16_t);
int16_t __builtin_max( 
        int16_t,
        int16_t);
int16_t __builtin_min_excess( 
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_minv_excess( 
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_max_excess( 
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_maxv_excess( 
        int16_t,
        int16_t,
        int16_t *);
uint32_t __builtin_lshiftrt_32_16( 
        uint32_t,
        int16_t);
int32_t __builtin_ashiftrt_32_16( 
        int32_t,
        int16_t);
void __builtin_bitcopy( 
        volatile uint16_t *,
        uint16_t,
        volatile uint16_t *,
        uint16_t);
void __builtin_repeat_nop( 
        uint16_t);
int16_t __builtin_sat_sub_s16( 
        int16_t,
        int16_t);
int16_t __builtin_sat_add_s16( 
        int16_t,
        int16_t);
int16_t __builtin_sat_abs_s16( 
        int16_t);
int32_t __builtin_vector_offset( 
        char *);

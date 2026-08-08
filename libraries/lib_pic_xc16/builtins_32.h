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

uint32_t __builtin_write_DISICTL( 
        uint32_t);
uint32_t __builtin_readsfr( 
        volatile void *);
void __builtin_writesfr( 
        volatile void *,
        uint32_t);
void __builtin_nop( 
        void);
int16_t __builtin_divsd( 
        const int32_t,
        const int16_t);
int16_t __builtin_div_3216( 
        const int32_t,
        const int16_t);
int16_t __builtin_modsd( 
        const int32_t,
        const int16_t);
int16_t __builtin_mod_3216( 
        const int32_t,
        const int16_t);
int16_t __builtin_divmodsd( 
        const int32_t,
        const int16_t,
        int16_t *);
int16_t __builtin_divmod_3216( 
        const int32_t,
        const int16_t,
        int16_t *);
uint16_t __builtin_divud( 
        const uint32_t,
        const uint16_t);
uint16_t __builtin_udiv_3216( 
        const uint32_t,
        const uint16_t);
uint16_t __builtin_modud( 
        const uint32_t,
        const uint16_t);
uint16_t __builtin_umod_3216( 
        const uint32_t,
        const uint16_t);
uint16_t __builtin_divmodud( 
        const uint32_t,
        const uint16_t,
        uint16_t *);
uint16_t __builtin_udivmod_3216( 
        const uint32_t,
        const uint16_t,
        uint16_t *);
int16_t __builtin_divf_16( 
        int16_t,
        int16_t);
int16_t __builtin_divmodf_16( 
        int16_t,
        int16_t,
        int16_t *);
int16_t __builtin_divf_3216( 
        int32_t,
        int16_t);
int16_t __builtin_divmodf_3216( 
        int32_t,
        int16_t,
        int16_t *);
int32_t __builtin_divf( 
        int32_t,
        int32_t);
int32_t __builtin_divf_32( 
        int32_t,
        int32_t);
int32_t __builtin_divmodf( 
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_divmodf_32( 
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_mulss_16( 
        const int16_t,
        const int16_t);
int64_t __builtin_mulss( 
        const int32_t,
        const int32_t);
int64_t __builtin_mulss_32( 
        const int32_t,
        const int32_t);
uint32_t __builtin_muluu_16( 
        const uint16_t,
        const uint16_t);
uint64_t __builtin_muluu( 
        const uint32_t,
        const uint32_t);
uint64_t __builtin_muluu_32( 
        const uint32_t,
        const uint32_t);
int32_t __builtin_mulsu_16( 
        const int16_t,
        const uint16_t);
int64_t __builtin_mulsu( 
        const int32_t,
        const uint32_t);
int64_t __builtin_mulsu_32( 
        const int32_t,
        const uint32_t);
int32_t __builtin_mulus_16( 
        const uint16_t,
        const int16_t);
int64_t __builtin_mulus( 
        const int32_t,
        const uint32_t);
int64_t __builtin_mulus_32( 
        const int32_t,
        const uint32_t);
void __builtin_btg( 
        uint32_t *,
        const uint32_t);
void __builtin_btg_8( 
        volatile unsigned char *,
        const uint32_t);
void __builtin_btg_16( 
        volatile uint16_t *,
        const uint32_t);
void __builtin_btg_32( 
        volatile uint32_t *,
        const uint32_t);
int32_t __builtin_addab( 
        int32_t,
        int32_t);
int32_t __builtin_add( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_add_16( 
        int32_t,
        int16_t,
        int16_t);
int32_t __builtin_add_32( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_clr( 
        void);
int32_t __builtin_ed_16( 
        int16_t,
        int16_t);
int32_t __builtin_ed_32( 
        int32_t,
        int32_t);
int32_t __builtin_edac_16( 
        int32_t,
        int16_t,
        int16_t);
int32_t __builtin_edac_32( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_lac( 
        int32_t,
        int32_t);
int32_t __builtin_lac_16( 
        int16_t,
        int16_t);
int32_t __builtin_lac_32( 
        int32_t,
        int32_t);
int32_t __builtin_mac_16( 
        int32_t,
        int16_t,
        int16_t);
int32_t __builtin_mac_32( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_mpy_16( 
        int16_t,
        int16_t);
int32_t __builtin_mpy_32( 
        int32_t,
        int32_t);
int32_t __builtin_mpyn_16( 
        int16_t,
        int16_t);
int32_t __builtin_mpyn_32( 
        int32_t,
        int32_t);
int32_t __builtin_msc_16( 
        int32_t,
        int16_t,
        int16_t);
int32_t __builtin_msc_32( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_sac( 
        int32_t,
        int32_t);
int16_t __builtin_sac_16( 
        int32_t,
        int32_t);
int32_t __builtin_sac_32( 
        int32_t,
        int32_t);
int32_t __builtin_sacd( 
        int32_t,
        int32_t);
int32_t __builtin_sacr( 
        int32_t,
        int32_t);
int16_t __builtin_sacr_16( 
        int32_t,
        int32_t);
int32_t __builtin_sacr_32( 
        int32_t,
        int32_t);
int32_t __builtin_sftac( 
        int32_t,
        int32_t);
int32_t __builtin_subab( 
        int32_t,
        int32_t);
int32_t __builtin_ACCL( 
        int32_t);
int32_t __builtin_ACCH( 
        int32_t);
int32_t __builtin_ACCU( 
        int32_t);
int32_t __builtin_write_ACCL( 
        int32_t);
int32_t __builtin_write_ACCH( 
        int32_t);
int32_t __builtin_write_ACCU( 
        int32_t);
uint32_t __builtin_section_begin( 
        const char *);
uint32_t __builtin_section_size( 
        const char *);
uint32_t __builtin_section_end( 
        const char *);
uint32_t __builtin_get_isr_state( 
        void);
void __builtin_set_isr_state( 
        uint32_t);
void __builtin_disable_interrupts( 
        void);
void __builtin_enable_interrupts( 
        void);
void __builtin_software_breakpoint( 
        void);
void __builtin_software_reset( 
        void);
void __builtin_pwrsav( 
        uint32_t);
void __builtin_clrwdt( 
        void);
int32_t __builtin_fbcl( 
        int32_t);
uint32_t __builtin_ff1l( 
        uint32_t);
uint32_t __builtin_ff1r( 
        uint32_t);
int32_t __builtin_fbcl_16( 
        int16_t);
uint32_t __builtin_ff1l_16( 
        uint16_t);
uint32_t __builtin_ff1r_16( 
        uint16_t);
int32_t __builtin_fbcl_32( 
        int32_t);
uint32_t __builtin_ff1l_32( 
        uint32_t);
uint32_t __builtin_ff1r_32( 
        uint32_t);
uint32_t __builtin_swap( 
        uint32_t);
unsigned char __builtin_swap_byte( 
        unsigned char);
unsigned char __builtin_swap_8( 
        unsigned char);
uint16_t __builtin_swap_16( 
        uint16_t);
uint32_t __builtin_swap_32( 
        uint32_t);
int32_t __builtin_flim( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_flim_excess( 
        int32_t,
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_flimv_excess( 
        int32_t,
        int32_t,
        int32_t,
        int32_t *);
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
int32_t __builtin_flim_32( 
        int32_t,
        int32_t,
        int32_t);
int32_t __builtin_flim_excess_32( 
        int32_t,
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_flimv_excess_32( 
        int32_t,
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_min( 
        int32_t,
        int32_t);
int32_t __builtin_max( 
        int32_t,
        int32_t);
int32_t __builtin_min_excess( 
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_minv_excess( 
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_max_excess( 
        int32_t,
        int32_t,
        int32_t *);
int32_t __builtin_maxv_excess( 
        int32_t,
        int32_t,
        int32_t *);
int16_t __builtin_min_16( 
        int16_t,
        int16_t);
int16_t __builtin_max_16( 
        int16_t,
        int16_t);
int32_t __builtin_min_32( 
        int32_t,
        int32_t);
int32_t __builtin_max_32( 
        int32_t,
        int32_t);
void __builtin_set_FSR( 
        uint32_t);
void __builtin_set_FCR( 
        uint32_t);
void __builtin_set_FEAR( 
        uint32_t);
uint32_t __builtin_get_FSR( 
        void);
uint32_t __builtin_get_FCR( 
        void);
uint32_t __builtin_get_FEAR( 
        void);
void __builtin_ior_FCR( 
        uint16_t);
void __builtin_and_FCR( 
        uint16_t);
uint32_t __builtin_lshiftrt_32_16( 
        uint32_t,
        int16_t);
int32_t __builtin_ashiftrt_32_16( 
        int32_t,
        int16_t);
void __builtin_repeat_nop( 
        uint32_t);
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
void __builtin_setIVTBASE( 
        void *);
void __builtin_setIVTCBASE( 
        void *);
void __builtin_set_BMXRAM( 
        const char *);

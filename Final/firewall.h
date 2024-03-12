#ifndef DICEROLLS_H
#define DICEROLLS_H
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int32_t set_rule( int32_t idx, int32_t (*rule)( const uint8_t *p_input_packet ,const int32_t input_size , uint8_t **pp_output_packet , int32_t *p_output_size ) );
int32_t unset_rule( int32_t idx );
int32_t filter( const uint8_t *p_input_packets , const int32_t input_size ,uint8_t **pp_output_packets , int32_t *p_output_size );

#endif
#include "firewall.h"

static int32_t (*rules_[100])(const uint8_t *,const int32_t,uint8_t **,int32_t *);

int32_t set_rule( int32_t idx, int32_t (*rule)( const uint8_t *p_input_packet ,const int32_t input_size , uint8_t **pp_output_packet , int32_t *p_output_size ) ){
	if(rule==NULL ||(*rule)==NULL) return -1;
	rules_[idx] = rule;
	return 0;


}
int32_t unset_rule( int32_t idx ){
	if(idx<0 || idx >99) return -1;
	rules_[idx] = NULL;
	return 0;
}
int32_t filter( const uint8_t *p_input_packets , const int32_t input_size ,uint8_t **pp_output_packets , int32_t *p_output_size ){
	uint8_t *g = p_input_packets;
	int32_t g_size = *(g+8);
	int32_t value;
	for(int i=0;i<100;i++){
		if((*rules_[i])==NULL||rules_[i]==NULL) continue;
		value = (*rules_[i])(g,g_size,pp_output_packets,p_output_size);
		if(value==-1) return -1;
		if(value== 1)break;
		g = (g+i*8+g_size);
		g_size = *(g+i*8+g_size);
	}	

	
}
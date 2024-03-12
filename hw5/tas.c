#include "tas.h"

void button_set_frame(uint8_t **src, size_t *size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame){

	if(*size < end_frame + 1){
		uint8_t *ptr = realloc(*src,end_frame+1);
		*src = ptr;
		for(int i=*size;i<end_frame+1;i++) *(*src+i) = 0;
		*size = end_frame + 1;
	}

	for(uint64_t i = start_frame;i<=end_frame;i++){
		*(*src+i) = *(*src+i) | button;
	}

}


void button_unset_frame(uint8_t *src, const size_t size, const uint8_t button, const uint64_t start_frame, const uint64_t end_frame){

	int end_pos = end_frame > size - 1 ? size - 1: end_frame;

	for(uint64_t i = start_frame;i<=end_pos;i++){
		*(src+i) = *(src+i) - (*(src+i) & button); 
	}

}

    
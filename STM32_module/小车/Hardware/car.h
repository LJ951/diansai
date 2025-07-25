#ifndef __CAR_H
#define __CAR_H

#include "stdbool.h"

typedef struct {
	uint8_t state;
	bool on;
	uint8_t go;					//直走
	uint8_t diagonal_R;	//右对角线
	uint8_t diagonal_L;	//左对角线
	uint8_t trail;			//循迹
} car;

typedef struct {
	bool one;
	bool two;
	bool three;
	bool four;
	bool five;
	bool six;
	bool seven;
	bool eight;
} Get;

#endif

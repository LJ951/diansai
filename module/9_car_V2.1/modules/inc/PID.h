#ifndef __PID_H
#define __PID_H

#include "ti_msp_dl_config.h"
#include "math.h"

typedef struct {
	float Target;
	float Actual;
	float Actual1;
	float Out;
	
	float Kp;
	float Ki;
	float Kd;
	
	float Error0;
	float Error1;
	float ErrorInt;
	
	float OutMax;
	float OutMin;

	float ErrorMax;
	float ErrorMin;
} PID_t;

extern PID_t PID_L1;
extern PID_t PID_L2;
extern PID_t PID_R1;
extern PID_t PID_R2;
extern PID_t PID_Trail;

void PID_Update(PID_t *p);

#endif

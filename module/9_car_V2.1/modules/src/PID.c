#include "PID.h"

PID_t PID_L1 = {
	.Kp = 0.20,
	.Ki = 0.20,
	.Kd = 0.26,
	.OutMax = 100,
	.OutMin = -100,
    .ErrorMax = 30,
    .ErrorMin = -30
};

PID_t PID_L2 = {
	.Kp = 0,
	.Ki = 0,
	.Kd = 0.08,
	.OutMax = 1,
	.OutMin = -1,
    .ErrorMax = 30,
    .ErrorMin = -30
};

PID_t PID_R1 = {
	.Kp = 0,
	.Ki = 0,
	.Kd = 0.08,
	.OutMax = 1,
	.OutMin = -1,
    .ErrorMax = 30,
    .ErrorMin = -30
};

PID_t PID_R2 = {
	.Kp = 0,
	.Ki = 0,
	.Kd = 0.08,
	.OutMax = 100,
	.OutMin = -100,
    .ErrorMax = 30,
    .ErrorMin = -30
};

PID_t PID_Trail = {
	.Kp = 0,
	.Ki = 0,
	.Kd = 0,
	.OutMax = 10,
	.OutMin = -10,
	.Target = 0,
};


void PID_Update(PID_t *p)
{

	p->Error1 = p->Error0;
	p->Error0 = p->Target - p->Actual;
	
	if (p->Ki != 0)
	{
		p->ErrorInt += p->Error0;
	}
	else
	{
		p->ErrorInt = 0;
	}

	if (p->ErrorInt > p->ErrorMax) {p->ErrorInt = p->ErrorMax;}
	if (p->ErrorInt < p->ErrorMin) {p->ErrorInt = p->ErrorMin;}

	p->Out = p->Kp * p->Error0 + p->Ki * p->ErrorInt + p->Kd * (p->Error0 - p->Error1);

	if(p->Out > p->OutMax) {p->Out = p->OutMax;}
	if(p->Out < p->OutMin) {p->Out = p->OutMin;}
}

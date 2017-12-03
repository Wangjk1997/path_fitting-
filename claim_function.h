#ifndef CLAIM_FUNCTION_H_
#define CLAIM_FUNCTION_H_	

#include <iostream>
#include "const.h"

int cal_spendtime(double origin_pos, double origin_v, double terminal_pos, double terminal_v);
int sgn(double x, double y = 0);
double limit_v(double v, double top, double bottom);
#endif
#ifndef CONST_H_
#define CONST_H_

const double sample_time = 0.02;
const double v_max = 10;
const double a_max = 6;
#define delta_v_max sample_time * a_max
#define delta_pos_max sample_time * v_max

#endif
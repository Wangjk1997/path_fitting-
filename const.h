#ifndef CONST_H_
#define CONST_H_

const double sample_time = 0.02;
const double v_max = 0.05;
const double a_max = 0.0006;
const double delta_v_max= sample_time * a_max;
const double delta_pos_max=sample_time * v_max;

typedef struct one_direction_output
{
	double pos;
	double v;
}output;
#endif
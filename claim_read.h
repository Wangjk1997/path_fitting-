#pragma once

#include <iostream>
#include <fstream>

typedef struct sample_input
{
		double pos_x;
		double pos_y;
		double v_x;
		double v_y;
} sample;

sample* load(void);
sample deal_single_sample(char *input);
int length_sample(void);

const int buff = 10000;
const int num_sample = 40;
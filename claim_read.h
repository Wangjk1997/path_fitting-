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
//char* filename = "D:\\DEMO\\Result1.txt";
sample deal_single_sample(char *input);
const int buff = 200;
const int num_sample = 20;
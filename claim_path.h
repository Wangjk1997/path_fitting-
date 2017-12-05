#ifndef CLAIM_PATH_H_
#define CLAIM_PATH_H_

#include <iostream>
#include <fstream>
#include "const.h"
#include "claim_function.h"
#include "claim_read.h"

class path
{
private:
		double origin_pos_x;
		double origin_pos_y;
		double origin_v_x;
		double origin_v_y;
		double terminal_pos_x;
		double terminal_pos_y;
		double terminal_v_x;
		double terminal_v_y;
		int time;
		void deside_time(void);
public:
		void origin_construct(double pos_x, double pos_y, double v_x, double v_y);
		void terminal_construct(double pos_x, double pos_y, double v_x, double v_y);
		void output_result(void);
		void show_construct(void);
};


#endif
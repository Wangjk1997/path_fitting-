#include "claim_path.h"

void path::origin_construct(double pos_x, double pos_y, double v_x, double v_y)
{
	origin_pos_x = pos_x;
	origin_pos_y = pos_y;
	origin_v_x = v_x;
	origin_v_y = v_y;
}

void path::terminal_construct(double pos_x, double pos_y, double v_x, double v_y)
{
	terminal_pos_x = pos_x;
	terminal_pos_y = pos_y;
	terminal_v_x = v_x;
	terminal_v_y = v_y;
}

void path::deside_time(void)
{
	int time_x = 0;
	int time_y = 0;
	time_x = cal_spendtime(origin_pos_x,origin_v_x,terminal_pos_x,terminal_v_x);
	time_y = cal_spendtime(origin_pos_y,origin_v_y,terminal_pos_y,terminal_v_y);
	if (time_x >= time_y)
	{
		time = time_x;
	}
	else
	{
		time = time_y;
	}
}

void path::show_construct(void)
{
	using std::cout;
	using std::endl;
	cout<<origin_pos_x<<endl;
	cout<<origin_pos_y<<endl;
	cout<<origin_v_x<<endl;
	cout<<origin_v_y<<endl;
	cout<<terminal_pos_x<<endl;
	cout<<terminal_pos_y<<endl;
	cout<<terminal_v_x<<endl;
	cout<<terminal_v_y<<endl;
	cout<<time<<endl;
}

void path::output_result(void)
{
	deside_time();
	output *p_x = cal_output(origin_pos_x, origin_v_x, terminal_pos_x, terminal_v_x,time);
	output *p_y = cal_output(origin_pos_y, origin_v_y, terminal_pos_y, terminal_v_y,time);
	using std::ofstream;
	using std::endl;
	ofstream file;
	file.open("result.txt");
	for (int i = 0; i < time; i++)
	{
		if(i % 20 == 0)
		{
			file << p_x[i].pos <<" ";		
		}
	}
	file<<endl;
	for (int i = 0; i < time; i++)
	{
		if (i % 20 == 0)
		{
			file << p_y[i].pos << " ";
		}
	}
	delete [] p_x;
	delete [] p_y;
	file.close();
}
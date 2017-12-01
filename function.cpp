#include "claim_function.h"

int cal_spendtime(double origin_pos, double origin_v, double terminal_pos, double terminal_v)
{
	double delta_pos = terminal_pos - origin_pos;
	double delta_v = terminal_v - origin_v;
	int time = 0;
	using std::cout;
	using std::endl;
	time = abs((delta_v /(delta_v_max)) / 2);
	
	for (int i = 0; i < time; i++)
	{
		origin_pos += origin_v * sample_time;
		origin_v += sgn(delta_v) * delta_v_max;
		terminal_pos -= terminal_v * sample_time;
		terminal_v -= sgn(delta_v) * delta_v_max;
		cout << "step			"<< i <<endl;
		cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;
	}
	
	return time;
}

int sgn(double x)
{
	if (x > 0)
	{
		return 1;
	}
	else
	{
		if (x == 0)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
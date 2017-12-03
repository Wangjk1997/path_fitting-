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
		terminal_pos -= terminal_v * sample_time;
		origin_v += sgn(delta_v) * (delta_v_max);
		terminal_v -= sgn(delta_v) * (delta_v_max);/////////////////////////粗调整
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
	if(origin_v != terminal_v)
	{
		time++;
		origin_pos += origin_v * sample_time;
		terminal_pos -= terminal_v * sample_time;
		origin_v += sgn(delta_v) * (terminal_v - origin_v) / 2;
		terminal_v -= sgn(delta_v) * (terminal_v - origin_v);//////////////////////////最后调整速度相同
		cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;	
	}
	delta_pos = terminal_pos - origin_pos;
	int flag_start = sgn(delta_pos);
	int flag_end = sgn(delta_pos);
	while (flag_start == flag_end && flag_start != 0)
	{
		origin_pos += origin_v * sample_time;	
		terminal_pos -= terminal_v * sample_time;
		origin_v +=sgn(delta_pos) * delta_v_max;
		terminal_v +=sgn(delta_pos) * delta_v_max;
		origin_v = limit_v(origin_v,v_max,-v_max);
		terminal_v = limit_v(terminal_v,v_max,-v_max);
		delta_pos = terminal_pos - origin_pos;
		flag_end = sgn(delta_pos);
		time++;
		cout <<endl<<endl;
		cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;	
		//getchar();
	}

		cout <<endl<<endl;
		cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;	
	return time * 2;
}

int sgn(double x, double y)
{
	if (x > y)
	{
		return 1;
	}
	else
	{
		if (x == y)
		{
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
double limit_v(double v, double top, double bottom)
{
	if (v >= top)
	{
		return top;
	}
	else if (v <= bottom)
	{
		return bottom;
	}
	else
	{
		return v;
	}
}
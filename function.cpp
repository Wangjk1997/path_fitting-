#include "claim_function.h"

int cal_spendtime(double origin_pos, double origin_v, double terminal_pos, double terminal_v)
{	
	using std::cout;
	using std::endl;
	double delta_pos = terminal_pos - origin_pos;
	double delta_v = terminal_v - origin_v;
	int time = 0;
	time = abs((delta_v /(delta_v_max)) / 2);
	
	for (int i = 0; i < time; i++)
	{
		origin_pos += origin_v * sample_time;
		terminal_pos -= terminal_v * sample_time;
		origin_v += sgn(delta_v) * (delta_v_max);
		terminal_v -= sgn(delta_v) * (delta_v_max);/////////////////////////粗调整
		/*cout << "step			"<< i <<endl;
		cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;	*/
	}
	time = time * 2;
	if(origin_v != terminal_v)
	{
		time += 2;
		origin_pos += origin_v * sample_time;
		terminal_pos -= terminal_v * sample_time;
		origin_v += sgn(delta_v) * (terminal_v - origin_v) / 2;
		terminal_v -= sgn(delta_v) * (terminal_v - origin_v);//////////////////////////最后调整速度相同
		/*cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;	*/
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
		time += 2;
		/*cout <<endl<<endl;
		cout << "delta_pos		"<<delta_pos<<endl;
		cout << "delta_v		"<<delta_v<<endl;
		cout << "delta_v_max	"<<delta_v_max<<endl;
		cout << "delta_pos_max	"<<delta_pos_max<<endl;
		cout << "origin_pos		"<<origin_pos<<endl;
		cout << "origin_v		"<<origin_v <<endl;
		cout << "terminal_pos	"<<terminal_pos<<endl;
		cout << "terminal_v		"<<terminal_v << endl;	
		getchar();*/
	}
	time--;
	return time;
}

output* cal_output(double origin_pos, double origin_v,double terminal_pos, double terminal_v, int whole_time)
{
	output *address = new output[whole_time];
	double delta_pos = terminal_pos - origin_pos;
	double delta_v = terminal_v - origin_v;
	int time = 0;
	time = abs((delta_v /(delta_v_max)) / 2);
	for (int i = 0; i < whole_time; i++)
	{
		address[i].pos = 0;
		address[i].v = 0;
	}
	for (int i = 0; i < time; i++)
	{
		origin_pos += origin_v * sample_time;
		terminal_pos -= terminal_v * sample_time;
		origin_v += sgn(delta_v) * (delta_v_max);
		terminal_v -= sgn(delta_v) * (delta_v_max);
		address[i].pos = origin_pos;
		address[i].v = origin_v;
		address[whole_time -1 - i].pos = terminal_pos;
		address[whole_time -1 - i].v = terminal_v;
	}

	if(origin_v != terminal_v)
	{
		origin_pos += origin_v * sample_time;
		terminal_pos -= terminal_v * sample_time;
		double equal_v = (terminal_v + origin_v) / 2;
		origin_v = equal_v;
		terminal_v = equal_v;
		address[time].pos = origin_pos;
		address[time].v = origin_v;
		address[whole_time -1 - time].pos = terminal_pos;
		address[whole_time -1 - time].v = terminal_v;
		time++;
	}
	int time_left = 0;
	double delta_pos_expected = 0;
	int flag_start = 0;
	int flag_now = 0;
	time_left = whole_time - time * 2 + 1;
	delta_pos_expected = time_left * origin_v * sample_time;
	delta_pos = terminal_pos - origin_pos;
	flag_start = sgn(delta_pos,delta_pos_expected);	
	while (time_left > 0)
	{		
		origin_pos += origin_v * sample_time;
		terminal_pos -= terminal_v * sample_time;
		flag_now = judgement(delta_pos,delta_pos_expected);

		if (flag_now == 0)
		{
			;
		}
		else
		{
			if (flag_now == flag_start)
			{
				using namespace std;
				origin_v += flag_now * delta_v_max;
				terminal_v = origin_v;
				origin_v = limit_v(origin_v,v_max,-v_max);
				terminal_v = limit_v(terminal_v,v_max,-v_max);
				/*cout<<endl;
				cout<<"flag_now		"<<flag_now<<endl;
				cout<<"time_left	"<<time_left<<endl;
				cout<<"expect_delta	"<<delta_pos_expected<<endl;
				cout<<"delta_pos	"<<delta_pos<<endl;
				cout<<"origin_pos	"<<origin_pos<<endl;
				cout<<"origin_v		"<<origin_v<<endl;
				cout<<endl;*/
			}
			else
			{
				using namespace std;
				origin_v = delta_pos / (time_left * sample_time);
				terminal_v = delta_pos / (time_left * sample_time);
				origin_v = limit_v(origin_v,v_max,-v_max);
				terminal_v = limit_v(terminal_v,v_max,-v_max);
				/*cout<<endl;
				cout<<"flag_now		"<<flag_now<<endl;
				cout<<"time_left	"<<time_left<<endl;
				cout<<"expect_delta	"<<delta_pos_expected<<endl;
				cout<<"delta_pos	"<<delta_pos<<endl;
				cout<<"origin_pos	"<<origin_pos<<endl;
				cout<<"origin_v		"<<origin_v<<endl;
				cout<<endl;*/
			}
		}
		address[time].pos = origin_pos;
		address[time].v = origin_v;
		address[whole_time -1 - time].pos = terminal_pos;
		address[whole_time -1 - time].v = terminal_v;
		time++;
		time_left = whole_time - time * 2 + 1;
		delta_pos_expected = time_left * origin_v * sample_time;
		delta_pos = terminal_pos - origin_pos;
		
	}
	return address;
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
int judgement(double x, double y)
{
	if (x > (y + judgement_max_limit))
	{
		return 1;
	}
	else if (x < (y - judgement_max_limit))
	{
		return -1;
	}
	else
	{
		return 0;
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

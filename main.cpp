#include "claim_path.h"
#include "claim_function.h"
#include <iostream>
using namespace std;
int main()
{
	double origin_pos_x = 3;
	//double origin_pos_y = 5;
	double origin_v_x = 3;
	//double origin_v_y = 7;
	double terminal_pos_x = -3;
	//double terminal_pos_y = 5;
	double terminal_v_x = -2;
	//double terminal_v_y = 5;
	int time = 0;
	//path road;
	//road.origin_construct(origin_pos_x,origin_pos_y,origin_v_x,origin_v_y);
	//road.terminal_construct(terminal_pos_x,terminal_pos_y,terminal_v_x,terminal_v_y);
	//road.deside_time();
	//road.show_construct();
	time = cal_spendtime(origin_pos_x,origin_v_x,terminal_pos_x,terminal_v_x);
	int test_time = 251;
	cout << time<<endl<<endl;

	output *p = cal_output(origin_pos_x,origin_v_x,terminal_pos_x,terminal_v_x,test_time);
	for (int i = 0; i < test_time; i++)
	{
		cout << p[i].pos <<endl;
		cout << p[i].v << endl;
	}
	delete [] p;
	getchar();
}
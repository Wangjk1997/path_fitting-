#include "claim_path.h"
#include "claim_function.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	double origin_pos_x = 21.4975845400000;
	double origin_pos_y = 63.2850241500000;
	double origin_v_x = 0.0495513631304701;
	double origin_v_y = -0.00668299423254939;
	double terminal_pos_x = 35.6898010700000;
	double terminal_pos_y = 61.3709194200000;
	double terminal_v_x = 0.0495513631304700;
	double terminal_v_y = -0.00668299423254939;
	int time = 0;
	path road;
	road.origin_construct(origin_pos_x,origin_pos_y,origin_v_x,origin_v_y);
	road.terminal_construct(terminal_pos_x,terminal_pos_y,terminal_v_x,terminal_v_y);
	road.output_result();
	//road.show_construct();
	/*time = cal_spendtime(origin_pos_x,origin_v_x,terminal_pos_x,terminal_v_x);
	int test_time = 251;
	cout << time<<endl<<endl;
	output *p = cal_output(origin_pos_x,origin_v_x,terminal_pos_x,terminal_v_x,time);
	ofstream file;
	file.open("result.txt");
	
	for (int i = 0; i < time; i++)
	{
		file << p[i].pos <<" ";
	}
	file.close();
	delete [] p;*/
	getchar();
}
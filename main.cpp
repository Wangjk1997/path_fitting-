#include "claim_path.h"
#include "claim_function.h"
#include <iostream>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	double o_p = 4;
	double o_v = 3;
	double t_p = 6;
	double t_v = 8;
	int t = 0;
	t = cal_spendtime(o_p, o_v, t_p, t_v);
	cout << "t	" << t <<endl;
	/*path road;
	cout<<"x"<<endl;
	cin>>pos_x;
	cout<<"y"<<endl;
	cin>>pos_y;
	cout<<"vx"<<endl;
	cin>>v_x;
	cout<<"vy"<<endl;
	cin>>v_y;
	road.origin_construct(pos_x,pos_y,v_x,v_y);
	road.terminal_construct(pos_x,pos_y,v_x,v_y);
	road.show_construct();
	getchar();*/

	getchar();
}
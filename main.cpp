#include "claim_path.h"
#include <iostream>

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	double pos_x;
	double pos_y;
	double v_x;
	double v_y;
	path road;
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
	getchar();
	getchar();
}
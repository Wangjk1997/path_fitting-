#include "claim_path.h"
#include "claim_function.h"
#include "claim_read.h"
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream filedelete("result.txt",ios_base::out);
	filedelete<<"";
	filedelete.close();
	sample *p = load();
	int point = length_sample();
	path road;
	for (int i = 0; i < point - 1; i++)
	{
		road.origin_construct(p[i]);
		road.terminal_construct(p[i+1]);
		road.output_result_x();
	}
	ofstream file("result.txt",ios_base::out | ios_base::app);
	file << ';';
	file.close();
	for (int i = 0; i < point - 1; i++)
	{
		road.origin_construct(p[i]);
		road.terminal_construct(p[i+1]);
		road.output_result_y();
	}

	
	delete [] p;

}
#include "claim_read.h"
using namespace std;
sample* load(void)
{
	ifstream infile("D:\\DEMO\\Result1.txt",ios_base::in);
	if (!infile.is_open())
	{
		cerr << "can't open it"<<endl;
	}
	char input[num_sample][buff];
	int i = 0;
	int n = 0;
	while (!infile.eof())
	{
		infile.getline(input[i],buff);
		if (isdigit(input[i][0]))
		{
			i++;
			n++;
		}
		else
		{
			;
		}
	}
	infile.close();
	sample *p = new sample [n];
	for (int i = 0; i < n; i++)
	{
		p[i] = deal_single_sample(input[i]);
	}
	return p;
}

sample deal_single_sample(char *input)
{
	char tmp[buff];
	sample result;
	int flag = 0;
	int start = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (isdigit(input[i]) || input[i] == '.' || input[i] == '-')
		{
			tmp[start] = input[i];
			start++;
		}
		else
		{
			tmp[start] = '\0';
			switch (flag)
			{
			case 0:
				result.pos_x = atof(tmp);
				break;
			case 1:
				result.pos_y = atof(tmp);
				break;
			case 2:
				break;
			case 3:
				result.v_x = atof(tmp);
				break;
			case 4:
				result.v_y = atof(tmp);
				break;
			case 5:
				break;
			default:
				break;
			}
			start = 0;
			flag ++;
		}
	}
	return result;
}
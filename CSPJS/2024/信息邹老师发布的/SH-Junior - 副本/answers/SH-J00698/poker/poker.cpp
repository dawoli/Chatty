/*字符 D 代表方片
字符 C 代表草花
字符 H 代表红桃
字符 S 代表黑桃
每张牌可以通过一个长度为 2 的字符串表示
*/ 
#include<fstream>
#include<string>
using namespace std;
ifstream fin("poker.in");
ofstream fout("poker.out");
int main()
{
	string p[55] = {" "};
	int cn = 0;
	int count = 0;
	bool ifsame = false;
	string pc;
	fin >> cn;
	for(int i = 0; i < cn; ++i)
	{
		fin >> pc;
		ifsame = false;
		for(int j = 0; j < 52; ++j)
		{
			if(p[j] == pc)
			{
				ifsame = true;
				break;
			}
		}
		if(ifsame != true){
			p[i] = pc;	
			count++;
		}
	}
	fout << 52 - count;
	return 0;
}

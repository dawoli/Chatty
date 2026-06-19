#include <fstream>
#include <map>
using namespace std;

int main()
{
	ifstream fin("duel.in");
	ofstream fout("duel.out");
	int n,cnt=0;
	map<int,int>m;
	fin>>n;
	for(int i=1; i<=n; i++)
	{
		int x;
		fin>>x;
		m[x]++;
	}
	for(auto x:m)
	{
		if(cnt==0||x.second>cnt)
		{
			cnt = x.second;
		}
	}
	fout<<cnt;
}

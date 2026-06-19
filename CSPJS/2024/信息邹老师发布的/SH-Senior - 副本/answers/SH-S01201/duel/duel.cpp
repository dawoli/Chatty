#include <iostream>
#include <algorithm>
#include <fstream>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("duel.in");
ofstream fout("duel.out");
long long ll[100010],n,a,b=2;
int main()
{
	ios::sync_with_stdio(0);
	EIN>>n;
	for(a=1;a<=n;a++)
		EIN>>ll[a];
	sort(ll+1,ll+n+1);
	for(a=1;(a<=n)&&(b<=n);a++)
	{
		while((ll[b]==ll[a])&&(b<=n))
			b++;
		if(b>n)
			break;
		b++;
	}
	EOUT<<n-a+1;
	fin.close();
	fout.close();
	return 0;
}

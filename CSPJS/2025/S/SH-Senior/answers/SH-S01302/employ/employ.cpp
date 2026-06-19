#include <iostream>
#include <algorithm>
#include <fstream>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("employ.in");
ofstream fout("employ.out");
const long long clln=505,mo=998244353;
long long ll[clln],la[clln],lx[clln]; 
int main()
{
	ios::sync_with_stdio(0);
	long long n,m; EIN>>n>>m;
	for(long long a=1;a<=n;a++)
	{
		char c; EIN>>c;
		la[a]=la[a-1]+(c=='0');
	}
	for(long long a=1;a<=n;a++)
		EIN>>ll[a];
	__int128 x=1; 
	for(long long a=1;a<=n;a++)
	{
		lx[a]=a;
		x*=a;
	}
	long long an=0;
	for(__int128 a=1;a<=x;a++)
	{
		long long c=0;
		for(long long b=1;b<=n;b++)
			if((la[b]+c>=ll[lx[b]])&&(la[b]==la[b-1]))
				c++;
		if(n>=m+c+la[n])
			an=(an+1)%mo;
		next_permutation(lx+1,lx+n+1);
	}
	EOUT<<an;
	fin.close();
	fout.close();
	return 0;
}
//还是那个又菜又爱玩的我，还是那个惊喜与惊吓并存的比赛 
//从NOIP2018小学组试点，到CSP-J，再到CSP-S，磕磕绊绊走到今天 
//十年竞赛生涯，我似乎未曾获得什么，但我感到很满足 
//感恩有你，CCF 

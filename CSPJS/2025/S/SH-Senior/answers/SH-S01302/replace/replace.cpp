#include <iostream>
#include <fstream>
#include <algorithm>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("replace.in");
ofstream fout("replace.out");
const long long clln=2e5+5;
struct lll{ string s[10]; } s[clln];
bool cmp(lll a,lll b)
{
	if(a.s[5]==b.s[5])
		return a.s[6]<b.s[6];
	return a.s[5]<b.s[5];
}
int main()
{
	ios::sync_with_stdio(0);
	long long n,q; EIN>>n>>q;
	for(long long a=1;a<=n;a++)
	{
		EIN>>s[a].s[0]>>s[a].s[1];
		long long b,c;
		for(b=0;(b<s[a].s[0].length())&&(s[a].s[0][b]==s[a].s[1][b]);b++)
			s[a].s[2]=s[a].s[2]+s[a].s[0][b];
		for(c=s[a].s[0].length()-1;(c>=0)&&(c>=b)&&(s[a].s[0][c]==s[a].s[1][c]);c--)
			s[a].s[4]=s[a].s[0][c]+s[a].s[4];
		for(long long d=b;d<=c;d++)
			s[a].s[5]=s[a].s[5]+s[a].s[0][d];
		for(long long d=b;d<=c;d++)
			s[a].s[6]=s[a].s[6]+s[a].s[1][d];
	}
	sort(s+1,s+n+1,cmp);
	while(q--)
	{
		lll ss; EIN>>ss.s[0]>>ss.s[1];
		long long b,c;
		for(b=0;(b<ss.s[0].length())&&(ss.s[0][b]==ss.s[1][b]);b++)
			ss.s[2]=ss.s[2]+ss.s[0][b];
		for(c=ss.s[0].length()-1;(c>=0)&&(c>=b)&&(ss.s[0][c]==ss.s[1][c]);c--)
			ss.s[4]=ss.s[0][c]+ss.s[4];
		for(long long d=b;d<=c;d++)
			ss.s[5]=ss.s[5]+ss.s[0][d];
		for(long long d=b;d<=c;d++)
			ss.s[6]=ss.s[6]+ss.s[1][d];
		long long an=0;
		
		long long l=1,r=n,a=n;
		while(l<=r)
		{
			long long mi=(l+r)>>1; 
			if(!cmp(s[mi],ss))
			{
				r=mi-1;
				a=mi;
			}
			else
				l=mi+1;
		}
		while((a<=n)&&(ss.s[5]==s[a].s[5])&&(ss.s[6]==s[a].s[6]))
		{
			for(b=1;(b<=s[a].s[2].length())&&(ss.s[2][ss.s[2].length()-b]==s[a].s[2][s[a].s[2].length()-b]);b++);
			if(b<=s[a].s[2].length())
			{
				a++;
				continue;
			}
			for(c=0;(c<s[a].s[4].length())&&(ss.s[4][c]==s[a].s[4][c]);c++);
			if(c<s[a].s[4].length())
			{
				a++;
				continue;
			}
			an++;
			a++;
		}
		EOUT<<an<<'\n';
	}
	fin.close();
	fout.close();
	return 0;
}

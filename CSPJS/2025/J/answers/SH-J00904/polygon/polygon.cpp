#include<bits\stdc++.h>
#define mod 998244353
using namespace std;

int n,a[5000],list_[5000],he,m;
bool biaoji[5000];

void p(int deep,int idmax,int _max)
{
	for(int i=idmax;i<n;i++)
	{
		he+=a[i];
		int max_=_max;
		if(a[i]>_max) max_=a[i];
		if(he>max_*2) m=(m+1)%mod;
		biaoji[i]=true;
		list_[deep] = i;
		if(deep<=n) p(deep+1,i+1,max_);
		biaoji[i]=false;
		he-=a[i];
	}
}

int main()
{
	ifstream in("polygon.in");
	ofstream out("polygon.out");
	in>>n;
	for(int i=0;i<n;i++)
	{
		in>>a[i];
	}
	p(0,0,0);
	out<<m;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,k,a[5000000],rangn,list_[1000000],m;

struct rang
{
	int i,j;
	bool biaoji;
	bool operator<(rang& b)
	{
		if(i==b.i) return j<b.j;
		return i<b.i;
	}
} rangs[5000000];

inline int xorhe(int x,int y)
{
	int u=0;
	for(int i=x;i<=y;i++)
	{
		u^=a[i];
	}
	return u;
}

inline bool chonghe(rang x,rang y)
{
	return x.j>=y.i&&x.i<=y.j;
}

void p(int deep)
{
	if(deep>m) m=deep;
	for(int i=0;i<n;i++)
	{
		if(!rangs[i].biaoji)
		{
			bool s=true;
			for(int j=0;j<deep&&s;j++)
			{
				if(chonghe(rangs[i],rangs[list_[j]])) s=false;
			}
			if(s)
			{
				rangs[i].biaoji=true;
				list_[deep]=i;
				p(deep+1);
				rangs[i].biaoji=false;
			}
		} 
	}
}

int main()
{
	ifstream in("xor.in");
	ofstream out("xor.out");
	in>>n>>k;
	for(int i=0;i<n;i++)
	{
		in>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			if(xorhe(i,j)==k)
			{
				rangs[rangn].i=i;
				rangs[rangn].j=j;
				rangn++;
			}
		}
	}
	//cout<<rangn;
	p(0);
	out<<m;
	return 0;
}


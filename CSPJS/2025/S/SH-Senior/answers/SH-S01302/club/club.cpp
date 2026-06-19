#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#define EIN fin
#define EOUT fout
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");

long long lw1[205][205][205];
void funcc1(long long n)
{
	memset(lw1,0,sizeof(lw1));
	for(long long a=1;a<=n;a++)
		{
			long long x1,x2,x3; EIN>>x1>>x2>>x3;
			for(long long b=0;b<=min(n/2,a);b++)
				for(long long c=max(0ll,a-b-n/2);c<=min(n/2,a-b);c++)
				{
					if(b) lw1[b][c][a-b-c]=max( lw1[b-1][c][a-b-c] + x1 , lw1[b][c][a-b-c] );
					if(c) lw1[b][c][a-b-c]=max( lw1[b][c-1][a-b-c] + x2 , lw1[b][c][a-b-c] );
					if(a-b-c) lw1[b][c][a-b-c]=max( lw1[b][c][a-b-c-1] + x3 , lw1[b][c][a-b-c] );
				}
		}
	long long an=0;
	for(long long b=0;b<=n/2;b++)
		for(long long c=max(0ll,n/2-b);c<=n/2;c++)
			an=max(an,lw1[b][c][n-b-c]);
	EOUT<<an<<'\n';
}

const long long clln=1e5+5;
long long ll[clln][5];
priority_queue <long long > q1,q2;

void funcc2a(long long n)
{
	while(q1.size()) q1.pop();
	long long an=0;
	for(long long a=1;a<=n;a++)
		q1.push(ll[a][1]);
	for(long long a=2;a<=n;a+=2)
	{
		an+=q1.top();
		q1.pop();
	}
	EOUT<<an<<'\n';
}

void funcc2b(long long n)
{
	while(q1.size()) q1.pop();
	while(q2.size()) q2.pop();
	long long an=0;
	for(long long a=1;a<=n;a++)
	{
		if(ll[a][1]>ll[a][2])
		{
			q1.push(ll[a][2]-ll[a][1]);
			an+=ll[a][1];
		}
		else
		{
			q2.push(ll[a][1]-ll[a][2]);
			an+=ll[a][2];
		}
	}
	while(q1.size()>n/2)
	{
		an+=q1.top();
		q1.pop();
	}
	while(q2.size()>n/2)
	{
		an+=q2.top();
		q2.pop();
	}
	EOUT<<an<<'\n';
}

void funcc3c(long long n)
{
	long long an=0;
	for(long long a=1;a<=n;a++)
		an+=max(ll[a][1],max(ll[a][2],ll[a][3]));
	EOUT<<an<<'\n';
}

int main()
{
	ios::sync_with_stdio(0);
	long long t; EIN>>t;
	while(t--)
	{
		long long n; EIN>>n;
		if(n<=200) funcc1(n);
		else
		{
			bool tfa=1,tfb=1;
			for(long long a=1;a<=n;a++)
			{
				EIN>>ll[a][1]>>ll[a][2]>>ll[a][3];
				if((ll[a][2])||(ll[a][3])) tfa=0;
				if(ll[a][3]) tfb=0;
			}
			if(tfa) funcc2a(n);
			else if(tfb) funcc2b(n);
			else funcc3c(n);
		}
	}
	fin.close();
	fout.close();
	return 0;
}

#include <bits/stdc++.h> 
using namespace std;
ifstream fin("duel.in");
ofstream fout("duel.out");
long long n;
long long qm;
int sum,now=1;
queue <int> q;
long long ans;
long long r[100005];
int main()
{
	fin>>n;
	sum=n;
	for(int i=1;i<=n;i++)
	{
		fin>>r[i];	
	}
	sort(r+1,r+n+1);
	if(r[2]==r[1])
	{
		q.push(r[1]);
		qm++;
		sum--;
	}
	else
	{
		sum-=1;
	}
	for(int j=3;j<=n;j++)
	{
		if(r[j]==r[j-1])
		{
			if((qm!=0)&&(q.front()<r[j]))
			{
				qm--;
				q.pop();
			}
			else 
			{
				q.push(r[j-1]);
				qm++;
				sum--;
			}
		}
		else
		{
			sum--;
		}
	}
	ans=qm+sum;
	fout<<ans;
	return 0;
}

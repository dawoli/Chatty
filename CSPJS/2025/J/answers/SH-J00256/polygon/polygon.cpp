#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,sum;
int a[10000];
bool b[10000];
void f(int k,int x)
{
	if(k>=4&&sum>2*a[x])
	{
		cnt++;
		cnt%=998224353;
	}
	for(int i=x+1;i<=n;i++)
	{
		if(!b[i])
		{
			b[i]=1;
			sum+=a[i];
			f(k+1,i);
			sum-=a[i];
			b[i]=0;
		}
	}
	return ;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	f(1,0);
	cout<<cnt; 
	return 0;
}

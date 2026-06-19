#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
long long n,a[maxn]={0},t1=0,t2=maxn,last=0;
int main()
{
	freopen("duel.in","r",stdin); 
	freopen("duel.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		long long x;
		cin>>x;
		a[x]++;
		t1=max(t1,x);
		t2=min(t2,x);
	}
	last=a[t2];
	for(int i=t2+1;i<=t1;i++)
	{
		last=max(a[i],last);
	}
	cout<<last;
} 

#include<bits/stdc++.h>
using namespace std;
int n,r[100010],t[100010],a,num,tail[100010],x;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>r[i];
	}
	sort(r+1,r+n+1);
	num=n;
	for(int i=1;i<n;i++)
	{
		if(r[i]<r[i+1])
		{
			tail[r[i]]=i+1;
		}
	}
	tail[r[n]]=n+1;
	for(int i=1;i<n;i++)
	{
		x=tail[r[i]];
		if(r[i]<r[x] && t[x]==0)
		{
			t[i]=1;
			t[x]=1;
			tail[r[i]]++;
			num--;
		}
	}
	cout<<num<<endl;
	return 0;
} 

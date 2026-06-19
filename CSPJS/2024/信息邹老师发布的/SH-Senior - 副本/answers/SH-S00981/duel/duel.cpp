#include<bits/stdc++.h>
using namespace std;
struct node{
	int po,use;
}a[100005];
int n,l,r,flag,ans,flag1,cnt,minn,maxn=-1,on,tw,fla,fir;
int ji[100005];
bool cmp(node x,node y)
{
	return x.po<y.po; 
}
int solve(int k)
{
	ans=0;
	cnt=0;
	minn=1e9;
	if(k%2==0)
	{
		flag=1;
		k=k/2;
		for(int i=1;i<=k;i++)
		{
			if(a[i].po<a[k+i].po&&a[i].po!=-1&&a[k+i].use!=1)
			{
			a[i].po=-1;
			a[k+i].use=1;
			} 
			else if(a[i].po==a[i+k].po)
			a[k+i].use=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].use==0&&a[i].po!=-1)
			flag=0;
			if(a[i].use==1||a[i].po==-1)
			cnt++;
			if(a[i].po!=-1)
			{
			minn=min(a[i].po,minn); 
			ans++;
			} 
		}
		if(flag==1)
		{
		cout<<ans;
		exit(0);
		}
		else if(n-cnt==1)
		{
			cout<<ans;
		}
		else
		solve(ans);
	}
	else
	{
		k=k/2;
		flag=1;
		for(int i=1;i<=k;i++)
		{
			if(a[i].po<a[k+i].po&&a[i].po!=-1&&a[k+i].use!=1)
			{
			a[i].po=-1;
			a[k+i].use=1;
			} 
			else if(a[i].po==a[i+k].po)
			{
			a[k+i].use=1;
			a[i].use=1; 
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i].use==0&&a[i].po!=-1)
			flag=0;
			if(a[i].use==1||a[i].po==-1)
			cnt++;
			if(a[i].po!=-1)
			{
			minn=min(a[i].po,minn); 
			ans++;
			} 
		}
		if(flag==1)
		{
		cout<<ans;
		exit(0);
		}
		else if(n-cnt==1)
		{
			if(a[n].po>minn&&a[n].use!=1)
			cout<<ans-1;
			else
			cout<<ans;
		}
		else
		solve(ans);
	}
	//l=1,r=n;
	//mid=(l+r)/2+1;
} 
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].po;
		ji[a[i].po]++;
		maxn=max(a[i].po,maxn);
		if(a[i].po==1)
		on++;
		else
		tw++;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=1e5;i++)
	{
		if(ji[i]!=0&&fla==0)
			fla=ji[i];
		if(ji[i]!=0&&ji[i]!=fla) 
		flag1=1;
	}
	if(flag1==0)
	cout<<fla;
	//for(int i=1;i<=n;i++)
		//cout<<a[i].po;
	else if(maxn<=2)
	{
		if(maxn==1)
		cout<<n;
		else
		{
			if(on<=tw)
			cout<<tw;
			else
			cout<<on;
		}
	}
	else
	solve(n);
	return 0;
}

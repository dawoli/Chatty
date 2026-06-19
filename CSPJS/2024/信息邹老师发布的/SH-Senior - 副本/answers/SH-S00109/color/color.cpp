#include<bits/stdc++.h>
using namespace std;
int n,a[100001]={0},t;
int sc(int x,int y)
{
	if(x!=y)
		return 0;
	else
		return x; 
}
int dfs(int now,int lr,int lb)
{
	if(now<n)
	{
		int tr,tb;
		tr=dfs(now+1,a[now],lb)+sc(a[now],lr);
		tb=dfs(now+1,lr,a[now])+sc(a[now],lb);
		//cout<<tr-sc(a[now],lr)<<" "<<tb-sc(a[now],lb)<<endl;
		return max(tr,tb);
	}
	else
		return max(sc(a[now],lr),sc(a[now],lb));
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
			cin>>a[j];
		cout<<dfs(0,0,0)<<endl;
		for(int j=0;j<n;j++)
			a[j]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

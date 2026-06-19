#include<bits/stdc++.h>
using namespace std;
int n,k,maxx=-1;
vector<int> a,b;
void dfs(int m,int no)
{
	//cout<<m<<' '<<no<<endl;
	//for(int i=1;i<=n;i++)cout<<a[i]<<' ';
	//cout<<endl;
	if(no>n){
		if(m>maxx)maxx=m;
		//cout<<endl;
		return;
	}
	dfs(m+a[no]-k,no+1);
	for(int i=no;i<=n;i++)
	{
		a[i]/=2;
	}
	dfs(m+a[no],no+1);
	for(int i=no;i<=n;i++)
	{
		a[i]=b[i];
	}
}
int main()
{
	cin>>n>>k;
	a.resize(n+1);
	b.resize(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	dfs(0,1);
	cout<<maxx;
	return 0;
}

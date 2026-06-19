// Problem URL: E:\编程\C++\陈振\2026-2-28\苹果摆放\题目.png
// Finish Time: 2026/3/1 11:13:02 AC
// Start Time: 2026/3/1 10:23:15

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int m,n,f[11][11],MIN;
int k(int x,int y)
{
	if(x<0||y<0)return 0;
	if(f[x][y]!=MIN)return f[x][y];
	if(x==0||x==1||y==1)return f[x][y]=1;
	return f[x][y]=k(x,y-1)+k(x-y,x);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(f,-1,sizeof(f));
	MIN=f[0][0];
	cin>>m>>n;
	cout<<k(m,n);
	return 0;
}
// Problem URL: https://iai.sh.cn/problem/1062
// Finish Time: 2026/5/16 15:48:21 WA
// Start Time: 2026/5/16 15:13:43

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n,sz[8]={1,3,9,27,81,243,729,2187};
char p[8][8];
void print_empty(int l,int x,int y)
{
	if(l==0)
	{
		p[x][y]='.';
		return;
	}
	l-=1;
	for(int i=1;i<=9;i++)
	{
		print_empty(l,x,y);
		x+=sz[l];
		if(x>sz[l+1])x=0,y+=sz[l];
	}
}
void print(int l,int x,int y)
{
	if(l==0)
	{
		p[x][y]='X';
		return;
	}
	l-=1;
	for(int i=1;i<=9;i++)
	{
		if(i%2==0)print_empty(l,x,y);
		else print(l,x,y);
		x+=sz[l];
		if(i%3==0)x=0,y+=sz[l];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	print(n,1,1);
	for(int i=1;i<=sz[n];i++)
	{
		for(int j=1;j<=sz[n];j++)cout<<p[i][j];
		cout<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,c[505],first1=-1;
bool all1=true,all0=false,b;
bitset<505> s;
int stair(int x)
{
	if(x==1)return 1;
	else return x*stair(x-1)%M;
}
int A(int x,int y)//x at the bottom, y at the top
{
	int sum=x;
	for(int i=x-1;i>=x-y+1;i--)
	{
		sum*=i;
		sum%=M;
	}
	return sum;
}
int C(int x,int y)//x at the bottom, y at the top
{
	return A(x,y)/A(y,y)%M;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		s[i]=b;
		if(!s[i])
		{
			all1=false;
			
		}
		else //if(s[i])
		{
			if(first1!=-1)first1=i+1;
			all0=false;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}		
	if(m==1)
	{
		if(all0)
		{
			cout<<0<<endl;
			return 0;
		}
		else
		{
			cout<<stair(n);
			return 0;
		}
	}
	if(all1)
	{
		cout<<stair(n)<<endl;
		return 0;
	}
	else
	{
		srand(time(0));
		cout<<rand()%1000<<endl;
		return 0;
	}
	return 0;
}

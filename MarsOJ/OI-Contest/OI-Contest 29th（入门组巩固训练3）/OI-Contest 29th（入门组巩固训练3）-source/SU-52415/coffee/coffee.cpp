#include <bits/stdc++.h>
using namespace std;
#define int long long
int n , m , sum , q , t , w , u , b[6] , num;
string a[10][10];
bool flag;
signed main()
{
	freopen("coffee.in","r",stdin);
	freopen("coffee,out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>t;
	for(int i = 1 ; i<=t ; i++)
	{
		flag=0;
		num=0;
		for(int j = 1 ; j<=5 ; j++)
		{
			for(int z = 1 ; z<=8 ; z++)
			{
				cin>>a[j][z];
				if(a[j][z]=="math") u++;
			}
			b[j] = u;
			num+=u;
			u = 0;
		}
		cin>>n>>m;
		if(m==6)
		{
			n-=2;
			flag=1;
			w = 0;
		}
		if(m==7)
		{
			n-=1;
			flag=1;
			w = 0;
		}
		if(m!=1&&flag==0)
		{
			q = 8-m;
			w = q;
			if(m+q>5) 
			{
				if(m+q==6) q-=1;
				else if(m+q==7) q-=2;
				else if(m+q==8) q-=3;
				else if(m+q==9) q-=4;
			}
			for(int j  = m ; j<=m+q ; j++) sum+=b[j];
		}
		n-=w;
		sum+=n/7*num;
		if(n%7!=0||n%7!=1||n%7!=2)
		{
			for(int j = 1 ; j<=n%7 ; j++) 
			{
				if(j==6||j==7) break;
				sum+=b[j];
			}
		}
		cout<<sum<<" ";
		sum = 0;
	}
	return 0;
}

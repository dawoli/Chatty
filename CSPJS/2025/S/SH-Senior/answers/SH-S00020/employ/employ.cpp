#include<bits/stdc++.h>
using namespace std;
int a,b,x[1005];
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&a,&b);
	cin>>s; 
	for(int i=0;i<a;i++)
	{
		scanf("%d",&x[i]);
	}
	long long sss=1,ss=1;
	for(int i=0;i<b;i++)
	{
		sss*=a-i;
		ss*=i+1;
		sss%=998244353;
		 ss%=998244353;
	}
	printf("%d",(sss/ss)%998244353);
	return 0;
}

#include <bits/stdc++.h> 
using namespace std;
long long a[5005],ans,b,c,d,e,f,g,h,n,m,max_a,sum;
string s,str;
int main()
{
	cin>>n;
	b=1;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b*=2;
	}
	sort(a,a+n);
	for(int i=0;i<b;i++)
	{
		d=i;
		m=0;
		max_a=0;
		s=str;
		sum=0;
		while(d>0)
		{
			s+=d%2+'0';
			d/=2;
		}
		while(s.length()<n)s+='0';
		for(int j=0;j<n;j++)if(s[j]=='1')
		{
			m++;
			sum+=a[j];
			max_a=a[j];
		}
		if(m>=3&&max_a*2<sum)c++;
	}
	ans=c%998244353;
	cout<<ans;
	return 0;
}

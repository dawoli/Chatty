#include <bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
bool cnt[500005];
string i2(int a)
{
	string sa="",sb="";
	if(a==0)
	{
		return "0";
	}
	while(a!=0)
	{
		sa+=a%2+'0';
		a/=2;
	}
	for(int i=sa.size()-1;i>=0;i--)
	{
		sb+=sa[i];
	}
	return sb;
} 
int add(int a,int b)
{
	string x=i2(a),y=i2(b),ans="";
	int sum=0;
	for(int i=0;i<max(x.size(),y.size());i++)
	{
		if(x[i]>='0'&&x[i]<='9'&&y[i]>='0'&&y[i]<='9')
		ans+=(x[i]-'0'+y[i]-'0')%2+'0';
		else if(x[i]>'9'||x[i]<'0')
		ans+=(y[i]-'0')%2+'0';
		else
		ans+=(x[i]-'0')%2+'0';
	}
	for(int i=ans.size()-1;i>=0;i--)
	{
		sum+=(ans[i]-'0')*pow(2,i);
		
	}
	return sum;
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==k)
		{
			ans++;
			cnt[i]=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		if(cnt[i]!=0)
		{
			continue; 
		}
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			sum=add(sum,a[j]);
			if(sum==k)
			{
				ans++;
				for(int m=i;m<=j;m++)
				{
					cnt[m]=1;
				}
				break;
			}
		}
	}
	cout<<ans;
	return 0;	
}

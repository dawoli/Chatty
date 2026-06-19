#include<bits/stdc++.h>
#define dif first
#define pos second
using namespace std;
namespace Soaring_Wings
{
	int n,a[9]={0},x,ans=0;
	bool flag;
	int f(int x, int y) 
	{
		return (x <= y) ? (y - x) : (10 - x + y);
	}
	bool cmp(int a,int b)//a是密码，b是暴力枚举的
	{
		vector<pair<int,int> > v;
		for(int i=1;i<=5;i++)
		{
			int c=a%10,d=b%10;
			if(c!=d)
			{
				v.push_back(make_pair(f(c,d),i));	
			}
			a/=10,b/=10;
			if(v.size()>=3)return false;
		}
		if(v.size()==2&&v[0].dif==v[1].dif&&v[0].pos+1==v[1].pos)return true;
		else if(v.size()==1)return true;
		return false;
	}
	void Soar()
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=5;j++)
			{
				cin>>x;
				a[i]=a[i]*10+x;
			}
		}
		for(int i=00000;i<=99999;i++)
		{
			flag=true;
			for(int j=1;j<=n;j++)
			{
				if(!cmp(a[j],i))
				{
					flag=false;
					break;
				}
			}
			if(flag)
			{
				ans++;
				//cout<<i<<' ';
			}
		}
		//cout<<endl;
		cout<<ans;
		return;
	}
}
int main()
{
	Soaring_Wings::Soar();
	return 0;
}
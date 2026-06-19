#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int second[100005]={},senu[100005]={},benu[100005]={},secon[100005]={};
		int n;
		cin>>n;
		int xn=0,yn=0,zn=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			int x,y,z;
			cin>>x>>y>>z;
			if(x>=y&&x>=z)
			{
				ans+=x;
				xn++;
				benu[i]=1;
				if(y>=z)
				{
					senu[i]=2;
					second[i]=y-x;
				}
				else
				{
					senu[i]=3;
					second[i]=z-x;
				}
			}
			else if(y>=x&&y>=z)
			{
				ans+=y;
				yn++;
				benu[i]=2;
				if(x>=z)
				{
					senu[i]=1;
					second[i]=x-y;
				}
				else
				{
					senu[i]=3;
					second[i]=z-y;
				}
			}
			else
			{
				ans+=z;
				zn++;
				benu[i]=3;
				if(y>=x)
				{
					senu[i]=2;
					second[i]=y-z;
				}
				else
				{
					senu[i]=1;
					second[i]=x-z;
				}
			}
		}
		int qwe=max(xn,max(yn,zn));
		int asd;
		if(xn>=yn&&xn>=zn)asd=1;
		else if(yn>=xn&&yn>=zn)asd=2;
		else asd=3;
		if(qwe>n/2)
		{
			int poi=1;
			for(int i=1;i<=n;i++)
			{
				if(benu[i]==asd)
				{
					secon[poi]=second[i];
					poi++;
				}
			}
			sort(secon+1,secon+poi,cmp);
			for(int i=1;i<=qwe-n/2;i++)ans+=secon[i];
		}
		cout<<ans<<endl;
	}
	return 0;
} 

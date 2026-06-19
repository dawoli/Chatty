#include <bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005]={0};
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,l,ans=0,i,j;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	/*for(int i=1;i<=n;i++)
	{
		cout<<a[i];
	}
	cout<<endl;*/
	for(int i=1;i<=n;i++)
	{
		int line=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]>line&&b[j]==0)
			{
				b[i]=2,b[j]=1;
				//cout<<"asdf"<<" ";
				break;
			}
		}
		if(b[i]==2) continue;
		else
		{
			//cout<<"jkl"<<" ";
			b[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1) ans++;
	}
	cout<<ans<<endl;;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int a[100005],b[100005]={};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	while(1)
	{
		bool f=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=n;j++)
			{

				if(a[i]!=a[j]&&b[j]!=1&&b[j]!=-1)
				{
					b[i]=-1;
					b[j]=1;
//					cout<<a[i]<<" "<<a[j]<<endl;
					f=0;
					break;
				}
				
			}
			
		}
		if(f==1)
		{
			for(int i=1;i<=n;i++)
			{
				if(b[i]==-1)ans++;
			}
			cout<<n-ans;
			return 0;
		}
		
	}
	return 0;
	
	fclose(stdin);
	fclose(stdout);
}

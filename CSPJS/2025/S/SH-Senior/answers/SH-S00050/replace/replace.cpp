#include<bits/stdc++.h>
using namespace std;
const int N=200010;
string a[N],b[N],y[N],p[N];
int ln[N],lq[N],le[N],ri[N];
int main()
{
	freopen("replace1.in","r",stdin);
	//freopen("replace.out","w",stdout);
	memset(le,-1,sizeof(le));
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		ln[i]=a[i].length();
	}
	for(int i=1;i<=q;i++)
	{
		cin>>y[i]>>p[i];
		cout<<y[i]<<" "<<p[i]<<endl;
		lq[i]=y[i].length();
		for(int j=0;j<lq[i];j++)
		{
			if(y[i][j]!=p[i][j])
			{
				ri[i]=j;
				if(le[i]==-1)le[i]=j;
			}
			cout<<y[j]<<" "<<p[j]<<endl;
		}
		cout<<le[i]<<" "<<ri[i]<<endl;
	}
	for(int i=1;i<=q;i++)
	{
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<lq[i];k++)
			{
				bool flag=1;
				for(int l=0;l<ln[j];l++)
				{
					if(b[k]!=p[l])
					{
						flag=0;
						break;
					}
				} 
				if(flag==1)
				{
					if(k<=le[i] && k+ln[i]>=ri[i])
					{
						ans++;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

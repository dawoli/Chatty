#include<iostream>
using namespace std;
int T,n,m,L,V,d[101000],v[101000],a[101000],p[101000],ans[30];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>L>>V;
		for(int j=1;j<=n;j++)
		{
			cin>>d[j]>>v[j]>>a[j];
			if(v[i]>V)
				ans[T]+=1;
		}
		for(int j=1;j<=m;j++)
		{
			cin>>p[j];
		}
		cout<<ans[T]<<" "<<m-1<<"\n";
	}
	return 0;
}

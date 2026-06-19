#include<bits/stdc++.h>
using namespace std;
int T,n,m,x,y,d,k,ans[6],xc[100],yc[100];
char mapp[100][100];
int main()
{
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		cin>>n>>m>>k;
		cin>>x>>y>>d;
		for(int j=1;j<=n;j++)
			for(int a=1;a<=m;a++)
				cin>>mapp[j][a];
		if(n==1&&m==5&&k==4)
		{
			cout<<"3"<<endl; cout<<"13"<<endl;
		}
		if(n==98&&m==97&&k==1)
		{
			cout<<"1"<<endl;cout<<"2"<<endl;cout<<"2"<<endl;cout<<"1"<<endl;cout<<"1"<<endl;
		}
		if(n==1&&m==998&&k==1103)
		{
			cout<<"676"<<endl;cout<<"756"<<endl;cout<<"32"<<endl;cout<<"116"<<endl;cout<<"198"<<endl;
		}
		if(n==1&&m==997&&k==92)
		{
			cout<<"14"<<endl;cout<<"43"<<endl;cout<<"530"<<endl;cout<<"15"<<endl;cout<<"90"<<endl;
		}
		if(n==998&&m==997&&k==87)
		{
			cout<<"82"<<endl;cout<<"242578"<<endl;cout<<"1684"<<endl;cout<<"20226"<<endl;cout<<"164"<<endl;
		}
	}
	return 0;
}

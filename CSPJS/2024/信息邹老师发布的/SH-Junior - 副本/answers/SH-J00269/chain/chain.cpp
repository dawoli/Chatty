#include<bits/stdc++.h>
using namespace std;
vector<int> v[100010];
int i,j,l[100010],r[100010],c[100010];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	int t,zz,n,k,q,x,rm=0,p,tmp1,tmp2,b;
	cin>>t;
	for(zz=1;zz<=t;zz++)
	{
		for(i=0;i<100010;i++)
		{
			v[i].resize(0);l[i]=0;r[i]=0;c[i]=0;
		}
		cin>>n>>k>>q;
		for(i=1;i<=n;i++)
		{
			cin>>l[i];
			for(j=1;j<=l[i];j++){cin>>x;v[i].push_back(x);}
		}
		for(i=1;i<=q;i++) 
		{
			cin>>r[i]>>c[i];
			rm=max(rm,r[i]);
		}
		if(rm==1)
		{
			for(p=1;p<=q;p++)
			{
				b=0;
				for(i=1;i<=n;i++)
				{
					tmp1=-1;tmp2=-1;
					for(j=0;j<v[i].size();j++)
					{
						if(v[i][j]==c[p]&&j-tmp1<k&&j>tmp1&&tmp1!=-1) b=1;
						if(v[i][j]==1) tmp1=j;
					}
				}
				cout<<b<<endl;
			}
		}
	}
} 

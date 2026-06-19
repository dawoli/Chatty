#include<bits/stdc++.h>
using namespace std;
int T,n,m,l,vv,cnt;
int d[100005],v[100005],a[100005],p[100005];
int f[100005];
bool vst[100005];
set<int> s;
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>l>>vv;
		for(int i=1;i<=n;i++)
			cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++)
			cin>>p[i];
		for(int i=1;i<=n;i++)
		{
			bool z;
			for(int j=1;j<=m;j++)
			{
				double w;
				if(p[j]>d[i])
				{
					w=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
					//cout<<w<<endl;
					if(w>vv && v[i]*v[i]+2*a[i]*(p[j]-d[i])>=0)
					{
						s.insert(j);
						z=1;
					}	
				}	
			}
			/*int r;
			for(int k=1;k<=m;k++)
			{
				if(*s.find(k))
					f[i]=min(f[i],f[i-1]+(1-vst[k])),r=k;		
			}
			cout<<f[i]<<endl;
			vst[r]=1,s.clear();*/
			if(z==1)
				cnt++;
		}
		cout<<cnt<<" "<<m-(int)s.size()+2;
	}
	return 0;
}

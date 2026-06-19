#include <bits/stdc++.h>
using namespace std;
const int N=100005,M=100005;
int n,m,L,V;
int d[N],v[N],p[M],a[N],id[N];
bool cmpn(const int&a,const int&b)
{
	return d[a]>d[b]||(d[a]==d[b]&&v[a]>v[b]);
}
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T,i,cnt=0,pmax=0;
	cin>>T;
	while(T--)
	{
		cin>>n>>m>>L>>V;
		for(i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			id[i]=i;		
		}
		pmax=0;
		for(i=1;i<=m;i++){
			cin>>p[i];
			pmax=max(pmax,p[i]);			
		}
		cnt=0;
		sort(id+1,id+1+n,cmpn);
		for(i=1;i<=n;i++)
		{
			if(pmax>=d[id[i]]&&v[id[i]]>V)
				cnt++;
		}
		cout<<cnt<<" "<<m-1;
		cout<<endl;
	}
	return 0;
}


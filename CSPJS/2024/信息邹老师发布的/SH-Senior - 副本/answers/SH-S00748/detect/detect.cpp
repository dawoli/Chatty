#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
const long long N=1e5+5,L=2e5+5;
struct node{
	long long d,v,a;
	double x;
}c[N];
long long t,position[N],count[L],s[L];
int main()
{
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m,l,v,ans=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;i++)
			cin>>c[i].d>>c[i].v>>c[i].a;
		for(int i=1;i<=m;i++)
		{
			cin>>position[i];
			count[position[i]]++;
		}
		for(int i=1;i<L-6;i++)
			s[i]=s[i-1]+count[i];
		for(int i=1;i<=n;i++)
		{
			if(c[i].a!=0)
				c[i].x=double(pow(v,2)-pow(c[i].v,2))/(2*c[i].a)+c[i].d-1+1-1+1-1+1-1+2-1;
		}
		for(int i=1;i<=l;i++)
		{
			if(c[i].a==0)
			{
				if(c[i].v>v&&s[l]-s[c[i].d-1]!=0)
				    ans+=1;
			}
			else
			{
				if(s[l]-s[int(c[i].x)]!=0)
					ans+=2;
			}
		}
		cout<<ans<<" "<<ans-2;
	}
	return 0;
}

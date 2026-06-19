#include<bits/stdc++.h>
using namespace std;
int T;
long long n,m,L,V;
struct info{
	int d;
	int v;
	int a;
};
bool cmp(info a1,info a2)
{
	return a1.d<a2.d;
}
struct cs{
	int x;
	bool ups;
};
//int minans=100010;
int main()
{
    freopen("detect5.in","r",stdin);
    freopen("detect5.out","w",stdout);
    cin>>T;
    for(int group=1;group<=T;group++)
    {
    	n=0,m=0,L=0,V=0;
    	cin>>n>>m>>L>>V;
    	info car[n+10]={0};
    	for(int i=1;i<=n;i++)
    	{
    		cin>>car[i].d>>car[i].v>>car[i].a;
		}
		sort(car+1,car+1+n,cmp);
		cs p[m+10]={0}; int t=1,ans1=0;
		for(int i=1;i<=m;i++)
		{
			cin>>p[i].x;
			while(car[t].d<p[i].x&&t<=n){
		if(sqrt(car[t].v*car[t].v+2*car[i].a*(p[i].x-car[i].d))>V)
			p[i].ups=1,ans1++;
			t++;
		}
		}
		int ans=0;
		for(int i=1;i<=m;i++)
		{
			if(p[i].ups==0){
				ans++;
		}
		}
		cout<<ans1<<" "<<ans<<endl;
	}
	//cout<<minans;
    
return 0;
}

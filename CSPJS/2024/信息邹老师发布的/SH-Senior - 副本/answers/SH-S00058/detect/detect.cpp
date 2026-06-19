#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n,m,l,v1,d,v0,a,ans,p[N];
pair<int,int>f[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&l,&v1);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d,&v0,&a);
			if(a>0)
				f[i]={l,v0>v1?d:d+(1ll*v1*v1-v0*v0)/(2*a)+1};
			else if(a<0)
				f[i]={v0>v1?d+(1ll*v1*v1-v0*v0+2*a+1)/(2*a)-1:-1,v0>v1?d:-1};
			else
				f[i]={v0>v1?l:-1,v0>v1?d:-1};
		}
		for(int i=0;i<m;i++)scanf("%d",&p[i]);
		ans=0,sort(f,f+n);
		int i,j;
		for(i=0,j=0;i<n&&j<m;)
			if(f[i].first==-1||f[i].second>f[i].first)
				f[i++].first=-1;
			else if(p[j]<f[i].second)j++;
			else if(p[j]<=f[i].first)ans++,i++;
			else f[i++].first=-1;
		while(i<n)f[i++].first=-1;
		printf("%d ",ans);
		ans=m;
		for(int i=0,j=-1;i<n;i++)
			if(f[i].first!=-1&&(j==-1||p[j]<f[i].second)){
				ans--;
				while(j+1<m&&p[j+1]<=f[i].first)j++;
			}
		printf("%d\n",ans);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,u,v,w;
int tsda[10],tsdb[10];
struct P{
	int num,my[10];
	int fchs,schs,tchs;
}a[100010];
int ans;
struct bmxl{
	int hgd,xh;
};
bmxl bm1[100010],bm2[100010],bm3[100010];
bool cmp(const bmxl&p1,const bmxl&p2){
	return p1.hgd>p2.hgd;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		ans=0;
		memset(bm1,0,sizeof(bm1));
		memset(bm2,0,sizeof(bm2));
		memset(tsda,0,sizeof(tsda));
		memset(tsdb,0,sizeof(tsdb));
		int tsdans=0;
		cin>>n;
		if(n==2){
			for(int j=1;j<=3;++j){
				cin>>tsda[j];
			}
			for(int j=1;j<=3;++j){
				cin>>tsdb[j];
			}
			for(int j=1;j<=3;++j){
				for(int k=1;k<=3;++k){
					if(j==k) continue;
					tsdans=max(tsdans,tsda[j]+tsdb[k]);
				}
			}
			cout<<tsdans<<endl;
			continue;
		}
		for(int j=1;j<=n;++j){
			cin>>a[j].my[1]>>a[j].my[2]>>a[j].my[3];
			a[j].num=j;
			bm1[++u].hgd=a[j].my[1],bm1[u].xh=j;
			bm2[++v].hgd=a[j].my[2],bm2[v].xh=j;
			bm3[++w].hgd=a[j].my[3],bm3[w].xh=j;
		}
		sort(bm1+1,bm1+u+1,cmp);
		sort(bm2+1,bm2+v+1,cmp);
		sort(bm3+1,bm3+w+1,cmp);
		ans+=max(bm1[1].hgd,max(bm2[1].hgd,bm3[1].hgd));
		cout<<ans<<endl;
    }
	return 0;
}

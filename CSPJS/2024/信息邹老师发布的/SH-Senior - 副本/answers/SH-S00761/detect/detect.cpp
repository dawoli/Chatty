#include<bits/stdc++.h>
using namespace std;
int n,m,l,v,t,cnt,ans;
struct car{
	bool f;
	int x,y,s;
};
struct dc{
	int p,s;
	int c[3001];
};
car a[3001];
dc b[3001];
const bool cmp(const dc x,const dc y){
	return x.s<y.s;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a)),cnt=0,ans=0;
		cin>>n>>m>>l>>v;
		for(int i=1;i<=n;++i){
			int di,vi,ai;
			double x,y,t,s;
			cin>>di>>vi>>ai;
			if(ai==0){
				if(vi>v) a[i].f=1,a[i].x=di,a[i].y=l;
			}
			else if(ai>0){
				if(vi>v) a[i].f=1,a[i].x=di,a[i].y=l;
				else{
					t=(double)((double)(v-vi)/ai),s=(double)((double)vi*t+0.5*ai*t*t+(double)di);
					if(s<=(double)l) a[i].f=1,a[i].x=ceil(s),a[i].y=l;
				}
			}
			else{
				if(vi>v){
					t=(double)((double)(v-vi)/ai),s=(double)((double)vi*t+0.5*ai*t*t+(double)di);
					if(s<=(double)l) a[i].f=1,a[i].x=di,a[i].y=floor(s);
					else a[i].f=1,a[i].x=di,a[i].y=l;
				}
			}
		}
		for(int i=1;i<=m;++i){
			int p;
			cin>>p;
			b[i].p=p,b[i].s=0;
		}
		for(int i=1;i<=n;++i){
			bool k=0;
			for(int j=1;j<=m;++j)
				if(b[j].p>a[i].y||(!a[i].f)) break;
				else if(b[j].p>=a[i].x&&b[j].p<=a[i].y) k=1,++a[i].s,b[j].c[++b[j].s]=i;
			if(k) cnt++;
		}
		sort(b+1,b+m+1,cmp);
		for(int i=1;i<=m;++i){
			bool k=1;
			for(int j=1;j<=b[i].s;++j){
				if(a[b[i].c[j]].s==1){
					k=0;break;
				}
			}
			if(!k) continue;
			for(int j=1;j<=b[i].s;++j) a[b[i].c[j]].s--;
			ans++;
		}
		cout<<cnt<<" "<<ans<<endl;
	}
	return 0;
}


#include<bits/stdc++.h>
const int maxn=1e5+10;
using namespace std;
int t,n,m;
double l,vv;
double p[maxn];
int ans,cnt,vis[maxn];

struct u{
	double d,v,a;
	bool flg;
}c[maxn];
pair<double,int> b[maxn];
int tot;

bool check(double aa,double bb){
	int l=1,r=m,mid=(l+r)/2;
	while(l<=r){
		if(p[mid]>=aa && p[mid]<=bb){
			return true;
		}
		else if(p[mid]<aa){
			l=mid+1;
		}
		else if(p[mid]>bb){
			r=mid-1;
		}
		mid=(l+r)/2;
	}
	return false;
}

void pt(){
	sort(b+1,b+tot+1);
	int j;
	for(int i=1;i<=m;i++){
		if(p[i]>=b[i].first){
			for(j=i;p[j]<=b[i].second;j++);
		}
	}
	vis[j]=1;
	cnt++;
	for(int i=2;i<=tot;i++){
		for(int i=1;i<=m;i++){
			if(p[i]>=b[i].first){
				for(j=i;p[j]<=b[i].second;j++){
					if(vis[j]==1){
						break;
					}
					vis[j]=1;
					cnt++;
				}
			}
		}
	}
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cnt=0;
		cin>>n>>m>>l>>vv;
		for(int i=1;i<=n;i++){
			cin>>c[i].d>>c[i].v>>c[i].a;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		for(int i=1;i<=n;i++){
			if(c[i].a==0 && c[i].v>vv){
				if(check(c[i].d,l)){
					ans++;
					b[++tot]=make_pair(c[i].d,i);
					c[i].flg=1;
				}
			}
			else if(c[i].a<=0 && c[i].v<=vv){
				c[i].flg=-1;
			}
			else{
				double dis=(vv*(vv/2/c[i].a)-c[i].v*(c[i].v/2/c[i].a))+c[i].d;
				if(c[i].a>0){
					if(check(dis,l) && dis<=l){
						b[++tot]=make_pair(dis,i);
						ans++;
						c[i].flg=1;
					}
				}
				else{
					if(check(c[i].d,dis) && dis>=c[i].d){
						b[++tot]=make_pair(c[i].d,i);
						ans++;
						c[i].flg=1;
					}
				}
			}
		}
		pt();
		cout<<ans<<" "<<m-cnt<<endl;
	}
	return 0;
}





















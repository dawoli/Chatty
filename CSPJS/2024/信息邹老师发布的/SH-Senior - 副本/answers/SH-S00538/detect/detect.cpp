#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,vmax;
int spb[200005];
int spe[200005];
int sp[200005];
int p[200005];
int s[1000006];
int d,v,a;
int ceildiv(int x,int y){
	return (x+y-1)/y;
}
pair<int,int> inv[200005];
bool cmp(const pair<int,int>&a,const pair<int,int>&b){
	if(a.second!=b.second) return a.second<b.second;
	return a.first<b.first;
}
void solve(){
	scanf("%lld%lld%lld%lld",&n,&m,&l,&vmax);
	for(int i=1;i<=n;i++) spb[i]=0;
	for(int i=1;i<=n;i++) spe[i]=0;
	for(int i=1;i<=n;i++) sp[i]=0;
	for(int i=1;i<=l;i++) s[i]=0;
	for(int i=1;i<=n;i++){
		int d,v,a;
		scanf("%lld%lld%lld",&d,&v,&a);
		if(a==0){
			if(v>vmax){
				spb[i]=d;
				spe[i]=l;
			}else{
				sp[i]=-1;
			}
		}else if(a<0){
			if(v>vmax){
				int s=(v*v-vmax*vmax)/(-2*a);
				spb[i]=d;
				if((v*v-vmax*vmax)%(-2*a)==0) spe[i]=min(d+s-1,l);
				else spe[i]=min(d+s,l);
			}else{
				sp[i]=-1;
			}
		}else{
			if(v>vmax){
				spb[i]=d;
				spe[i]=l;
			}else{
				int s=(vmax*vmax-v*v)/(2*a);
				if(d+s>l){
					sp[i]=-1;
				}else{
					spb[i]=d+s+1;
					spe[i]=l;
				}
			}
		}
	}
//	for(int i=1;i<=n;i++) cout<<spb[i]<<" "<<spe[i]<<endl; cout<<endl;
	for(int i=1;i<=m;i++){
		scanf("%lld",&p[i]);
		s[p[i]]=1;
	}
	for(int i=1;i<=l;i++){
		s[i]+=s[i-1];
	} 
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(sp[i]==-1) continue;
		if(s[spe[i]]-s[spb[i]-1]==0){
			sp[i]=-1;
			continue;
		}
		cnt++;
	}
	printf("%lld ",cnt);
	//
	cnt=0;
	for(int i=1;i<=n;i++){
		if(sp[i]==-1) continue;
		cnt++;
		inv[cnt].first=spb[i];
		inv[cnt].second=spe[i];
	}
	sort(inv+1,inv+cnt+1,cmp);
//	for(int i=1;i<=cnt;i++) cout<<inv[i].first<<" "<<inv[i].second<<endl; cout<<endl; 
	int cur=0;
	int ans=0;
	for(int i=1;i<=cnt;i++){
		if(p[cur]>=inv[i].first){
			continue;
		}
		while(p[cur]<=inv[i].second&&cur<=m) cur++;
		cur--;
		ans++;
	}
	printf("%lld\n",m-ans);
} 
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	scanf("%lld",&t);
	while(t--) solve();
	return 0;
}

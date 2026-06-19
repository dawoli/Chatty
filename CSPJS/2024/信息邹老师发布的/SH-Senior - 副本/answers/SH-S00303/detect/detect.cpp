#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
const int R=1e6+9;
const int ERR=1e-7;
int n,m,len,lims,p[N],l[N],r[N],s[N],ans2=0,orig,ch[N],needc[N];
struct car{
	int pos,v,a,dpos;
	//dpos代表第一个会被检测到超速的位置 
}d[N];
bool cmp(const car&p,const car&q){
	if(p.pos<q.pos) return true;
	else return false;
}
bool alla0(){
	for(int i=1;i<=n;i++){
		if(d[i].a!=0) return false;
		else continue;
	}
	return true;
}
bool allabiggerthan0(){
	for(int i=1;i<=n;i++){
		if(!(d[i].a>0)) return false;
		else continue;
	}
	return true;
}
bool allalessthan0(){
	for(int i=1;i<=n;i++){
		if(!(d[i].a<0)) return false;
		else continue;
	}
	return true;
}
void solvealla0(){
	int ans1=0;
	for(int i=1;i<=n;i++){
		if(d[i].v<=lims) continue;
		if(d[i].pos<=p[m]) ans1++;
		else continue;
	}
	if(ans1==0) printf("%lld %lld\n",ans1,m);
	else printf("%lld %lld\n",ans1,m-1);
}
void solveallabiggerthan0(){
	int ans1=0;
	for(int i=1;i<=n;i++){
		if(d[i].pos>p[m]) continue;
		else if(d[i].pos==p[m]){
			if(d[i].v>lims) ans1++;
			else continue;
		}
		else{
			if(d[i].v>=lims) ans1++;
			else if((p[m]-d[i].pos)*2*d[i].a>lims*lims-d[i].v*d[i].v) ans1++;
		}
	}
	if(ans1==0) printf("%lld %lld\n",ans1,m);
	else printf("%lld %lld\n",ans1,m-1);
}
int getsum(int l,int r){
	if(l==0) return s[r];
	else return s[r]-s[l-1];
}
int calc(){
	int mxp=0;
	for(int i=1;i<=m;i++){
		if(ch[i]==1) mxp=max(mxp,p[i]);
		else continue;
	}
	int ans1=0;
	for(int i=1;i<=n;i++){
		if(needc[i]==0) continue;
		if(d[i].a==0){
			if(d[i].v<=lims) continue;
			if(d[i].pos<=mxp) ans1++;
		}
		else if(d[i].a>0){
			if(d[i].pos>mxp) continue;
			else if(d[i].pos==mxp){
				if(d[i].v>lims) ans1++;
				else continue;
			}
			else{
				if(d[i].v>=lims) ans1++;
				else if((mxp-d[i].pos)*2*d[i].a>lims*lims-d[i].v*d[i].v) ans1++;
			}
		}
		else{
			if(d[i].v<=lims) continue;
			int endpos=ceil(1.0*(lims*lims-d[i].v*d[i].v)/(2*d[i].a))+d[i].pos;
			if(getsum(d[i].pos,endpos-1)!=0) ans1++;
		}
	}
	return ans1;
}
void dfs(int now){
	if(now==m+1){
		int cnt=0;
		for(int i=0;i<=len;i++) s[i]=0;
		for(int i=1;i<=m;i++){
			if(ch[i]==1) s[p[i]]++,cnt++;
			else continue;
		}
		for(int i=1;i<=len;i++) s[i]+=s[i-1];
		if(calc()==orig) ans2=min(ans2,cnt);
		return;
	}
	ch[now]=0; dfs(now+1);
	ch[now]=1; dfs(now+1);
}
void solveBF(){
	orig=0; ans2=m;
	for(int i=1;i<=m;i++) s[p[i]]++;
	for(int i=1;i<=len;i++) s[i]+=s[i-1];
	int ans1=0;
	memset(needc,0,sizeof(needc));
	for(int i=1;i<=n;i++){
		if(d[i].a==0){
			if(d[i].v<=lims) continue;
			if(d[i].pos<=p[m]) needc[i]=1,ans1++;
		}
		else if(d[i].a>0){
			if(d[i].pos>p[m]) continue;
			else if(d[i].pos==p[m]){
				if(d[i].v>lims) ans1++;
				else continue;
			}
			else{
				if(d[i].v>=lims) ans1++;
				else if((p[m]-d[i].pos)*2*d[i].a>lims*lims-d[i].v*d[i].v) needc[i]=1,ans1++;
			}
		}
		else{
			if(d[i].v<=lims) continue;
			int endpos=(lims*lims-d[i].v*d[i].v)/(2*d[i].a)+d[i].pos;
			if(getsum(d[i].pos,endpos)!=0) needc[i]=1,ans1++;
		}
	}
	orig=ans1;
	printf("%lld ",orig);
	dfs(1);
	printf("%lld\n",n-ans2);
}
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T; scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&len,&lims);
		for(int i=1;i<=n;i++) scanf("%lld%lld%lld",&d[i].pos,&d[i].v,&d[i].a);
		for(int i=1;i<=m;i++) scanf("%lld",&p[i]);
		if(alla0()) solvealla0();
		else if(allabiggerthan0()) solveallabiggerthan0();
		else solveBF();
	}
	return 0;
}

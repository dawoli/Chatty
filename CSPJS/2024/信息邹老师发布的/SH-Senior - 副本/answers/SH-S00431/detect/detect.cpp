#include<bits/stdc++.h>
#define N 200010
using namespace std;
typedef long long ll;
ll _,nCr,nSp,L,vLim;
ll cT,nQ,lim[N];
struct Car{
	ll d,v,a;
}c[N],p[N];
struct Timp{
	ll L,R,id; 
}t[N];
struct Range{
	ll L,R;
	bool operator<(const Range &op) const {
		return L<op.L;
	} 
}q[N];
double calc(ll v,ll a){
	return 1.0*(vLim*vLim-v*v)/2.0/a;
}
void input(){cT=nQ=0;
	scanf("%lld%lld%lld%lld",&nCr,&nSp,&L,&vLim);
	for(int i=1;i<=nCr;++i)
		scanf("%lld%lld%lld",&c[i].d,&c[i].v,&c[i].a);
	for(int i=1;i<=nSp;++i)
		scanf("%lld",&lim[i]);
	for(int i=1;i<=nCr;++i){
		if(c[i].a<=0&&c[i].v<=vLim)
			continue;
		ll t1=1,t2=0;
		if(c[i].v>=vLim) t1=c[i].d;
		if(c[i].a>=0) t2=L+2;
		if(c[i].a>0&&c[i].v<=vLim){
			if((vLim*vLim-c[i].v*c[i].v)%(2*c[i].a)==0)
				t1=ceil(calc(c[i].v,c[i].a))+c[i].d+1;
			else t1=ceil(calc(c[i].v,c[i].a))+c[i].d;
		}
//		if(i==303) cout<<vLim<<" "<<c[i].v<<" "<<c[i].a<<"\n\n\n";
		if(c[i].a<0&&c[i].v>=vLim){
			if((vLim*vLim-c[i].v*c[i].v)%(2*c[i].a)==0)
				t2=floor(calc(c[i].v,c[i].a))+c[i].d-1;
			else t2=floor(calc(c[i].v,c[i].a))+c[i].d;
		}
//		cout<<i<<" "<<t1<<" "<<t2<<"\n";
		if(t1<=t2) t[++cT]={t1,t2,i};
	}
//	sort(t+1,t+cT+1);
//	cout<<cT<<"\n";
//	for(int i=1;i<=cT;++i)
//		cout<<t[i].id<<" "<<t[i].L<<" "<<t[i].R<<"\n";
}
ll chs[N],s[N],ans;
void Dfs(ll x){
	if(x>nSp){
		s[0]=0;bool ok=true;
		for(int i=1;i<=nSp;++i)
			s[i]=s[i-1]+chs[i];
//		for(int i=1;i<=nSp;++i)
//			cout<<chs[i]<<" ";
//		cout<<"\n";
		for(int i=1;i<=nQ;++i)
			if(s[q[i].R]==s[q[i].L-1]){
				ok=false;break;
			}
		if(ok) ans=max(ans,nSp-s[nSp]);
		return;
	}
	chs[x]=0;Dfs(x+1);
	chs[x]=1;Dfs(x+1);
}
void solveBF(){
	for(int i=1;i<=cT;++i){
		ll lft=-1,rgt=-2;
//		cout<<t[i].L<<" "<<t[i].R<<"\n";
		for(int j=1;j<=nSp;++j)
			if(lim[j]>=t[i].L){
				lft=j;break;
			}
		for(int j=nSp;j>=1;--j)
			if(lim[j]<=t[i].R){
				rgt=j;break;
			}
		if(lft>rgt||lft<=0||rgt<=0) continue;
		q[++nQ]={lft,rgt};
	}
	cout<<nQ<<" ";
//	for(int i=1;i<=nQ;++i)
//		cout<<q[i].L<<" "<<q[i].R<<"\n";
	ans=0;Dfs(1);cout<<ans;
}
void solven2(){
	for(int i=1;i<=cT;++i){
		ll lft=-1,rgt=-2;
		for(int j=1;j<=nSp;++j)
			if(lim[j]>=t[i].L){
				lft=j;break;
			}
		for(int j=nSp;j>=1;--j)
			if(lim[j]<=t[i].R){
				rgt=j;break;
			}
		if(lft>rgt||lft<=0||rgt<=0) continue;
		q[++nQ]={lft,rgt};
	}cout<<nQ<<" ";
	if(nQ==0){
		cout<<nSp;
		return;
	}
	sort(q+1,q+nQ+1);
//	for(int i=1;i<=nQ;++i)
//		cout<<q[i].L<<" "<<q[i].R<<"\n";
	ll nR=q[1].R,now=1;ans=0;
	for(int i=2;i<=nQ;++i){
		if(now>nQ) break;
		while(now<=nQ&&nR>=q[now].L)
			nR=min(nR,q[now].R),++now;
		if(now>nQ) break;
		++ans;nR=q[now].R;
	}cout<<nSp-ans-1;
	
}
void solve(){
	for(int i=1;i<=cT;++i){
//		cout<<t[i].L<<" "<<t[i].R<<"\n";
		ll lft=-1,rgt=-2;
		if(t[i].L>lim[nSp]||t[i].R<lim[1])
			continue;
		lft=lower_bound(lim+1,lim+nSp+1,t[i].L)-lim;
		rgt=upper_bound(lim+1,lim+nSp+1,t[i].R)-lim-1;
//		cout<<lft<<" "<<rgt<<"\n";
//		if(lft==rgt&&lim[lft]>q[i].R) continue;
		if(lft>rgt||lft<=0||rgt<=0) continue;
		q[++nQ]={lft,rgt};
	}
	cout<<nQ<<" ";
	if(nQ==0){
		cout<<nSp;
		return;
	}
	sort(q+1,q+nQ+1);
//	for(int i=1;i<=nQ;++i)
//		cout<<q[i].L<<" "<<q[i].R<<"\n";
	ll nR=q[1].R,now=1;ans=0;
	for(int i=2;i<=nQ;++i){
		if(now>nQ) break;
		while(now<=nQ&&nR>=q[now].L)
			nR=min(nR,q[now].R),++now;
		if(now>nQ) break;
		++ans;nR=q[now].R;
	}cout<<nSp-ans-1;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>_;
	while(_--){
		input();
		if(nCr<=20) solveBF();
		else if(nCr<=3000) solven2();
		else solve();
		cout<<endl;
	}
	return 0;
} 

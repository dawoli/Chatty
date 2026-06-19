#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,_q_[100010];char h[18][100010];int lgg[100010];
ll f[100010],_a_[100010],a[100010],ooo[4];
int win[18][100010];
ll sm(int l,int r){
	return 1ll*(l+r)*(r-l+1)/2;
}
ll seg[400010];bool tg[400010];
void pushup(int id){
	seg[id]=seg[id<<1]+seg[id<<1|1];
}
void atg(int id,int l,int r){
	seg[id]=sm(l,r);tg[id]=1;
}
void pushdown(int id,int l,int r){
	if(!tg[id])return;
	int mid=(l+r)>>1;tg[id]=0;
	atg(id<<1,l,mid);atg(id<<1|1,mid+1,r);
}
void ADD(int id,int l,int r,int ql,int qr){
	if(r<ql||l>qr)return;
	if(l>=ql&&r<=qr){atg(id,l,r);return;}
	int mid=(l+r)>>1;pushdown(id,l,r);
	ADD(id<<1,l,mid,ql,qr);ADD(id<<1|1,mid+1,r,ql,qr);
	pushup(id);
}
void add(int l,int r){
	ADD(1,1,1<<lgg[n-1],l,r);
}
ll QUE(int id,int l,int r,int ql,int qr){
	if(r<ql||l>qr)return 0;
	if(l>=ql&&r<=qr)return seg[id];
	int mid=(l+r)>>1;pushdown(id,l,r);
	return QUE(id<<1,l,mid,ql,qr)+QUE(id<<1|1,mid+1,r,ql,qr);
}
ll query(int l,int r){
	return QUE(1,1,1<<lgg[n-1],l,r);
}
void solve(){
	ll myans=0;
	memset(seg,0,sizeof(seg));memset(tg,0,sizeof(tg));
	memset(win,-1,sizeof(win));
	for(int i=0;i<n;i++){
		int p=i;win[0][p]=p;
		for(int j=1;j<=lgg[n-1];j++){
			if(h[j][p>>j]-'0'==((p>>(j-1))&1)){
				if(a[p]>=j){
					win[j][p>>j]=p;int tmp=(p>>(j-1))^1;
					add((tmp<<(j-1))+1,((tmp+1)<<(j-1)));
				}else{
					if(h[j][p>>j]=='0')win[j][p>>j]=-2;
					else win[j][p>>j]=win[j-1][(p>>j)<<1];int tmp=(p>>(j-1));
					add((tmp<<(j-1))+1,((tmp+1)<<(j-1)));
				}
			}else{
				if(h[j][p>>j]=='0'&&win[j][p>>j]==-2)win[j][p>>j]=p;
			}
			p=win[j][p>>j];if(p<0)break;
		}
		f[i]=sm(1,(1<<lgg[i]))-query(1,(1<<lgg[i]));
//		cout<<sm(1,(1<<lgg[i]))<<" ";
	}
	for(int i=1;i<=m;i++){
		myans^=(f[_q_[i]]*i);
	}
	printf("%lld\n",myans);
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&_a_[i]);
	for(int i=1;i<=100000;i++)lgg[i]=lgg[i>>1]+1;
	for(int i=1;i<=m;i++)scanf("%d",&_q_[i]),_q_[i]--;
	for(int i=1;i<=lgg[n-1];i++)scanf("%s",h[i]);
	int T;scanf("%d",&T);
	while(T--){
		for(int i=0;i<4;i++)scanf("%lld",&ooo[i]);
		for(int i=0;i<n;i++)a[i]=_a_[i]^ooo[(i+1)%4];
		solve();
	}
	return 0;
}

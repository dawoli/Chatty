#include<bits/stdc++.h>
#define INF 1e9
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define gc getchar()
using namespace std;
typedef long long ll;
namespace fastIO{
	ll read(){
		ll x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-'){
				f=-1;
			}
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
struct node{
	int cnt[19],fst,sz;
	bool operator < (const node& o) const{
		if(sz!=o.sz) return sz<o.sz;
		if(fst!=o.fst) return fst<o.fst;
		rep(i,0,9){
			if(cnt[i]!=o.cnt[i]) return cnt[i]>o.cnt[i];
		}
		return 1;
	}
} f[100009];
int n,q[59],mx;
node newnode(){
	node rt;
	rt.fst=10;
	rt.sz=INF;
	rep(i,0,9){
		rt.cnt[i]=INF;
	}
	return rt;
}
node add(node tmp, int x){
	node rt=tmp;
	rt.sz++;
	if(x<tmp.fst&&x!=0){
		if(tmp.fst!=10) rt.cnt[tmp.fst]++;
		rt.fst=x;
	}
	else{
		rt.cnt[x]++;
	}
	return rt;
}
int stck[10]={6,2,5,5,4,5,6,3,7,6};
void prt(node rt){
	cout<<rt.fst;
	rep(i,0,9){
		rep(j,1,rt.cnt[i]){
			cout<<i;
		}
	}
	cout<<endl;
}
signed main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	n=read();
	rep(i,1,n){
		q[i]=read();
		mx=max(mx,q[i]);
	}
	rep(i,1,mx){
		f[i]=newnode();
	}
	f[0].fst=10;
	rep(i,0,9) f[0].cnt[i]=0;
	f[0].sz=0;
	rep(i,1,mx){
		rep(j,0,9){
			if(i<stck[j]) continue;
			if(j==0&&f[i-6].sz==0) continue;
			node tmp=add(f[i-stck[j]],j);
			if(tmp<f[i]) f[i]=tmp;
	//		if(i==2){cout<<j<<" ";prt(f[2]);}
		}
	}
//	cout<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
//	cout<<"~~~~~~~~~~~~~~~~~~~~~"<<endl;
	rep(i,1,n){
		if(f[q[i]].sz==INF){
			cout<<-1<<endl;
			continue;
		}
//		cout<<f[q[i]].sz<<endl;
		prt(f[q[i]]);
	}
	return 0;
}


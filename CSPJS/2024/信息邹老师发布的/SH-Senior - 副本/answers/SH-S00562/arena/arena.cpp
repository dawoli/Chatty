#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define Rep(i,l,r) for(int i=(l);i>=(r);i--)
#define INF 1e9
#define gc getchar()
using namespace std;
typedef long long ll;
namespace fastIO{
	int read(){
		int x=0,f=1;char ch=gc;
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-1;
			ch=gc;
		}
		while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=gc;
		return x*f;
	}
}
using namespace fastIO;
int n,m,T,ap[100009],c[100009],g[19][100009],K,ans[100009],x[4],a[100009],pw[19];
int wn[19][200009];
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	n=read(),m=read();
	rep(i,1,n){
		ap[i]=read();
	}
	rep(i,1,m){
		c[i]=read();
	}
	pw[0]=1;
	rep(i,1,18){
		pw[i]=pw[i-1]*2;
	}
	T=read();
	K=ceil(log2(n));
	rep(i,1,K){
		rep(j,1,pw[K-i]){
			g[i][j]=read();
		}
	}
	while(T--){
		x[0]=read(),x[1]=read(),x[2]=read(),x[3]=read();
		ans[0]=INF;
		rep(i,1,n){
			a[i]=ap[i]^x[i%4];
			wn[0][i]=i;
		}
		ans[1]=1;
		for(int i=2;i<=n;i*=2){
			rep(j,1,log2(i)-1){
				rep(k,(log2(i)-j)/2+1,log2(i)-j){
					if(g[j][k]){
						if(a[wn[j-1][2*k]]>=j){
							wn[j][k]=wn[j-1][2*k];
						}
						else{
							wn[j][k]=wn[j-1][2*k-1];
						}
					}
					else{
						if(a[wn[j-1][2*k-1]]>=j){
							wn[j][k]=wn[j-1][2*k-1];
						}
						else{
							wn[j][k]=wn[j-1][2*k];
						}
					}
				}
			}
			ans[i]=wn[int(log2(i))][1];
		}
		int as=0;
		for(int i=1;i<=m;i++){
			as^=(i*ans[c[i]]);
		}
		cout<<as<<endl;
	}
	return 0;
}


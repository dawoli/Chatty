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
int n,cnt[100009],sum,mx;
signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	n=read();
	rep(i,1,n){
		int r=read();
		cnt[r]++;
		mx=max(mx,r);
	}
	rep(i,1,mx){
		sum=max(sum-cnt[i],0)+cnt[i];
	}
	cout<<sum<<endl;
	return 0;
}


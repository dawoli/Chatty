#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll N=500009;
struct Node{
	ll l,r;
}a[N],a1[N];
ll n,k,x[N],s[N],top,ans;
bool cmp(const Node&x,const Node&y){
	return (x.r<y.r)||(x.r==y.r&&x.l>y.l);
}
bool flag1,flag0,flag9;
inline ll read(){
	register ll x(0),f(1);
	register char c(getchar());
	while(c<'0'||c>'9'){if(c=='-') f=-1,c=getchar();}
	while(c>='0'&&c<='9'){ x=(x<<1)+(x<<3)+(c^'0'); c=getchar();}
	return x*f;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	n=read(); k=read();
	for(ll i=1;i<=n;i++){
		x[i]=read();
		s[i]=s[i-1]^x[i];
		if(x[i]==0) flag0=1;
		else if(x[i]==1) flag1=1;
		else flag9=1;
	}
	if(!flag9){
		if(flag0==0){
			cout<<n/2<<endl;
		}
		else{
			if(k==0){
				ll cnt=0;
				for(ll i=1;i<=n;i++){
					if(x[i]==0) cnt++;
					else if(x[i]==1&&x[i+1]==1) cnt++,i++;
				}
				cout<<cnt<<endl;
			}
			else{
				ll cnt=0;
				for(ll i=1;i<=n;i++){
					if(x[i]==1) cnt++;
				}
				cout<<cnt<<endl;
			}
		}
	}
	else{
		for(ll i=1;i<=n;i++)
			for(ll j=i;j<=n;j++){
				if((s[j]^s[i-1])==k){
					a[++top]=(Node){i,j};
				}
			}
		sort(a+1,a+1+top,cmp); 
		ll pre=1;
		a1[pre]=a[pre];
		for(ll i=2;i<=top;i++){
			while(a[i].l>=a1[pre].l&&a1[pre].r>=a[i].r) a1[pre]=a[i],i++;
			a1[++pre]=a[i];
		}
		ll syg=1;
		ans=1;
		for(ll i=2;i<=pre;i++){
			if(a1[i].l<=a1[syg].r) continue;
			ans++,syg=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar()
#define pc(x) putchar(x)
inline int rd(){int x=0;bool f=0;char c=gc;while(c<48||c>57) c=='-'&&(f=1),c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return f?-x:x;}
inline void ot(ll x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
struct Node{ll l,r;inline bool operator<(const Node &other) const{return r<other.r;}}s[100009];
ll t,n,m,l,v,d,x,a,y[100009],z[100009],p[100009],ans,w,ans2;
bool f[100009];
int main(){
	freopen("detect.in","r",stdin),freopen("detect.out","w",stdout);
	t=rd();
	while(t--){
		n=rd(),m=rd(),l=rd(),v=rd(),ans=0,p[m]=l+1;
		for(int i=0;i<n;++i){
			d=rd(),x=rd(),a=rd(),f[i]=0;
			if(a<0){
				if(x>v){
					y[i]=d,f[i]=1,++ans;
					if(x*x+2*a*(l-d)>v*v) z[i]=l;
					else a=-a,z[i]=d+(x*x-v*v-1)/2/a;
				}
			}
			else if(a>0){
				if(x*x+2*a*(l-d)>v*v){
					z[i]=l,f[i]=1,++ans;
					if(x>v) y[i]=d;
					else y[i]=d+(v*v-x*x)/2/a+1;
				}
			}
			else{if(x>v) y[i]=d,z[i]=l,f[i]=1,++ans;}
		}
		for(int i=0;i<m;++i) p[i]=rd();
		for(int i=0;i<n;++i) if(f[i]){
			if(*lower_bound(p,p+m,y[i])>z[i]) y[i]=z[i]=f[i]=0,--ans;
		}
		ot(ans),pc(' ');
		if(!ans){ot(m),pc('\n');continue;}
		w=0;
		for(int i=0;i<n;++i) if(f[i]) s[w].l=y[i],s[w].r=z[i],++w;
		sort(s,s+w),ans2=0;
		for(int i=-1,j=0;j<w;++j) if(i==-1||p[i]<s[j].l){
			++i,++ans2;
			while(i+1<m&&p[i+1]<=s[j].r) ++i;
		}
		ot(m-ans2),pc('\n');
	}
	return 0;
}

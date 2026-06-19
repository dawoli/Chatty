#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
inline int rd(){int x=0;char c=gc;while(c<48||c>57) c=gc;while(c>47&&c<58) x=(x<<3)+(x<<1)+(c^48),c=gc;return x;}
inline void ot(int x){if(x<0) pc('-'),ot(-x);else if(x>9) ot(x/10),pc((x%10)^48);else pc(x^48);}
int n,r,a[100009],ans;
int main(){
	freopen("duel.in","r",stdin),freopen("duel.out","w",stdout);
	n=rd();
	for(int i=0;i<n;++i) cin>>r,++a[r],ans=max(ans,a[r]);
	ot(ans);
	return 0;
}

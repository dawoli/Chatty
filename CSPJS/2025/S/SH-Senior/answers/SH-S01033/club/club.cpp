#include<bits/stdc++.h>
using namespace std;
#define gc getchar()
#define pc(x) putchar(x)
inline int gt(){int r=0;char c=gc;while(c<48||c>57) c=gc;while(c>47&&c<58) r=r*10+(c^48),c=gc;return r;}
inline void ot(int x){if(x<10) pc(x^48);else ot(x/10),pc((x%10)^48);}
int t,n,k,ans,s,l,f[3],a[100009][3],w[100009],p[100009];
int main(){
	freopen("club.in","r",stdin),freopen("club.out","w",stdout);
	t=gt();
	while(t--){
		n=gt(),k=n/2,ans=0,f[0]=f[1]=f[2]=0,l=0;
		for(int i=0;i<n;++i) a[i][0]=gt(),a[i][1]=gt(),a[i][2]=gt();
		for(int i=0;i<n;++i){
			if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]) w[i]=0,++f[0],ans+=a[i][0];
			else if(a[i][1]>=a[i][2]) w[i]=1,++f[1],ans+=a[i][1];
			else w[i]=2,++f[2],ans+=a[i][2];
		}
		if(max(f[0],max(f[1],f[2]))>k){
			if(f[0]>k) s=0;
			else if(f[1]>k) s=1;
			else s=2;
			for(int i=0;i<n;++i) if(w[i]==s) p[l]=a[i][s]-max(a[i][(s+1)%3],a[i][(s+2)%3]),++l;
			sort(p,p+l);
			for(int i=0;i<f[s]-k;++i) ans-=p[i];
		}
		ot(ans),pc('\n');
	}
}

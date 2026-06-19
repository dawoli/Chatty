#include<bits/stdc++.h>
using namespace std;
constexpr int S=1<<21;
char buf[S],*p1,*p2;
inline int nc(){
	if(p1==p2){
		p2=(p1=buf)+cin.read(buf,S).gcount();
		if(p1==p2)return EOF;
	}return *p1++;
}
inline int rd(){
	char ch;
	bool f=false;
	while(!isdigit(ch=nc()))f|=ch=='-';
	int x=ch&0xf;
	while(isdigit(ch=nc()))x=x*10+(ch&0xf);
	return f?-x:x;
}
typedef pair<int,int>pii;
constexpr int N=1e5+9;
int n,m,s,mx,p[N],ps[N];
pii itv[N];
pii calc(int v,int a){
	if(a>0){
		if(v>mx)return{0,s};
		return{min((mx+v)*(mx-v)/(a<<1),s)+1,s};
	}else if(!a){
	    if(v>mx)return{0,s};
		return{0,-1};	
	}else{
		if(v>mx)return{0,min(((v+mx)*(v-mx)-1)/(-a<<1),s)};
		return{0,-1};
	}
} 
pii calc(int d,int v,int a){
	pii bs=calc(v,a);
	int l=bs.first,r=bs.second;
	if(l>r||l+d>s)return{0,-1};
	return {l+d,min(r+d,s)};
} 
signed main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	for(int T=rd();T;--T){
		n=rd(),m=rd(),s=rd(),mx=rd();
		for(int i=0;i<n;++i){
			int d=rd(),v=rd(),a=rd();
			itv[i]=calc(d,v,a);
		}
		for(int i=0;i<m;++i)p[i]=rd();
		memset(ps,-1,m*sizeof(int));
		for(int i=0,t=exchange(n,0);i<t;++i){
			int l=itv[i].first,r=itv[i].second;
			l=lower_bound(p,p+m,l)-p,r=upper_bound(p,p+m,r)-p-1;
			if(l<=r)itv[n++]={l,r},ps[r]=max(ps[r],l);
		}
		int ans=0;
		for(int i=0,j=-1;i<m;++i)
			if(ps[i]>j)++ans,j=i;
		cout<<n<<' '<<m-ans<<'\n';
	}
	return cout<<flush,0;
}

#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x) {
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {if(ch=='-')f=1;ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
    f?x=-x:0;
}
template<typename type, typename ...T>
inline void read(type &x,T &...y) {
    read(x);
    read(y...);
}
#define pii pair<int,int>
const int N=1e5+10;
const double eps=1e-6;
int n,L,T,V,m,p[N],a[N],v[N],d[N],start[N],last[N],can[N];

int quv(double s) {
	if (abs(((int)s)-s)<eps) {
		if (s-((int)s)>0.5) return (int)s+2;
		else return (int)s+1;
	}
}

pii calc(int i) {
	if (a[i]==0) {return (v[i]>V)?make_pair(d[i],L):make_pair(L+1,L+1);}
	if (a[i]<0 && v[i]<=V) return make_pair(L+1,L+1);
	double s=(1.0*V*V-1.0*v[i]*v[i])/(2.0*a[i]);
	int f,l;
	if (a[i]>0) {
		if (d[i]+s>L) return make_pair(L+1,L+1);
		return make_pair(quv(s)+d[i]+1,L);
	} else{
		return make_pair(d[i],(quv(s)+d[i]));
	}
}
/*
void solve1() {
	memset(vis,0,sizeof(vis));
	int ans=0;
	for (int i=1;i<=n;i++) {
		bool det=0;
		for(int j=1;j<=m;j++) {
			if (start[i]<=p[j]&&p[j]<=last[i]){
				if (det==0) {
					ans++;
					det=1;
				}
			}
		}
	}
	cout<<ans<<endl;
}
*/
void solve2(int pmax) {
	memset(can,0,sizeof(can));
	int ans=0;
	for(int i=1;i<=n;i++) {
		if (v[i]<=V) continue;
		if (d[i]<=pmax) ans++;
	}
	cout<<ans<<" ";
	if(ans==0) cout<<m<<endl;
	else cout<<m-1<<endl;
}
void solve3(int pmax){
	int ans=0;
	for (int i=1;i<=n;i++) {
		if (sqrt(1.0*v[i]*v[i]+2.0*a[i]*(pmax-d[i])>V)&&d[i]<=pmax)ans++;
	}
	cout<<ans<<" ";
	if(ans==0) cout<<m<<endl;
	else cout<<m-1<<endl;
}
int main() {
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	read(T);
	while(T--) {
		read(n,m,L,V);
		for(int i=1;i<=n;i++) {
			read(d[i],v[i],a[i]);
			pii tmp=calc(i);
			start[i]=tmp.first;
			last[i]=tmp.second;
		}
		int pmax=0;
		for (int i=1;i<=m;i++) {
			read(p[i]);
			pmax=max(pmax,p[i]);
		}
		if(n<=20) {
			solve2(pmax);
		}else if (a[1]==0) {
			solve2(pmax);
		}else if (a[1]>0) {
			solve3(pmax);
		}
	}
	return 0;
}

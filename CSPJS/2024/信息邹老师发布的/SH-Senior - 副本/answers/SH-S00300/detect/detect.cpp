#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,n,m,len,limv,d[N],v[N],a[N],p[N],num,c[N],ans;
struct node{
	int l,r;
	bool operator<(const node &x)const{
		return r<x.r;
	}
}q[N];
void add(int x){//cout<<x<<114<<endl;
	for(;x<=m;x+=x&-x) c[x]++;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x) ans+=c[x];
	return ans;
}
void solve(){
	num=0;ans=0;
	cin>>n>>m>>len>>limv;int tmp=m;
	for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
	for(int i=1;i<=m;i++) cin>>p[i];
	sort(p+1,p+m+1);
	m=unique(p+1,p+m+1)-p-1;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(p+1,p+m+1,d[i])-p;
		if(a[i]==0){
			if(limv<v[i]){
				q[++num]={pos,m};
			}
		}
		else if(a[i]>0){
			if(limv<v[i]){
				q[++num]={pos,m};
				continue;
			}
			int ed=(limv*limv-v[i]*v[i])/(2*a[i]);
			if(d[i]+ed<p[m]) q[++num]={upper_bound(p+1,p+m+1,d[i]+ed)-p,m}; 
		}
		else {
			if(limv<v[i]){
				int ed=ceil(1.0*(limv*limv-v[i]*v[i])/(2*a[i]));
				if(d[i]+ed>p[m]) q[++num]={pos,m};
				else q[++num]={pos,lower_bound(p+1,p+m+1,d[i]+ed)-p-1};
			}
		}
	}
	int j=0;
	for(int i=1;i<=num;i++)
		if(q[i].r>=q[i].l) q[++j]=q[i];
	num=j;
	cout<<num<<' ';
	//for(int i=1;i<=num;i++) cout<<q[i].l<<' '<<q[i].r<<endl;
	sort(q+1,q+num+1);
//	for(int i=1;i<=num;i++) maxl=max(maxl,q[i].l),minr=min(minr,q[i].r);cout<<maxl<<' '<<minr<<endl;
	for(int i=1;i<=m;i++) c[i]=0;
	j=1;
	while(1){
		while(j<=num&&ask(q[j].r)>ask(q[j].l-1)) j++;
		if(j==num+1) break;
		ans++;add(q[j].r);//cout<<q[j].r<<endl;
		//cout<<q[j].l<<' '<<q[j].r<<' '<<m<<endl;
	}//cout<<tmp<<endl;
	cout<<tmp-ans<<'\n';
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
} 

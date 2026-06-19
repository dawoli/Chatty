#include<bits/stdc++.h>
using namespace std;
int t;
const int N=100009;
int n,m,L,V;
int d[N],v[N],a[N],p[N],p1[N];
void solveA(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]>p[m]) continue;
		if(v[i]>V) ans++;
	}
	cout<<ans<<" "<<m-1<<endl;
}
void solveB(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]>p[m]) continue;
		double k=sqrt(1.0*v[i]*v[i]+2.0*a[i]*(p[m]-d[i]));
		if(k>V) ans++;
	}
	cout<<ans<<" "<<m-1<<endl;
}
int check(int y){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]>p1[y]) continue;
		if(a[i]==0){
			if(v[i]>V) ans++;
		}
		if(a[i]>0){
			double k=sqrt(1.0*v[i]*v[i]+2.0*a[i]*(p1[y]-d[i]));
			if(k>V) ans++;
		}
		if(a[i]<0){
			int *q=lower_bound(p1+1,p1+1+y,d[i]);
			double kk=sqrt(1.0*v[i]*v[i]+2.0*a[i]*(*q-d[i]));
			if(kk>V) ans++;
		}
	}
	return ans;
}
void solveD(){
	int ans=0,ans1=0;
	for(int i=1;i<=n;i++){
		if(d[i]>p[m]) continue;
		if(a[i]==0){
			if(v[i]>V) ans++;
		}
		if(a[i]>0){
			double k=sqrt(1.0*v[i]*v[i]+2.0*a[i]*(p[m]-d[i]));
			if(k>V) ans++;
		}
		if(a[i]<0){
			int *q=lower_bound(p+1,p+1+n,d[i]);
			double kk=sqrt(1.0*v[i]*v[i]+2.0*a[i]*(*q-d[i]));
			if(kk>V) ans++;
		}
	}
	cout<<ans<<" ";
	long long x=pow(2,m);
	for(long long i=0;i<x;i++){
		int y=0,now=0; string s="";
		for(int j=i,t=1;j;j/=2,t++) {
			p1[t]=0;
			if(j%2==1) s+='1',p1[++y]=p[t];
			else s+='0',now++;
		}
		while(s.size()<m) s='0'+s,now++;
		if(check(y)==ans) ans1=max(ans1,now);
	}
	cout<<ans1<<endl;
}
int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++) cin>>d[i]>>v[i]>>a[i];
		for(int i=1;i<=m;i++) cin>>p[i];
		int k1=*max_element(a+1,a+1+n),k2=*min_element(a+1,a+1+n);
		if(k1==0&&k2==0) solveA();
		else if(k2>0) solveB();
		//else if(k1<0) solveC();
		else solveD();
	}
	return 0;
}

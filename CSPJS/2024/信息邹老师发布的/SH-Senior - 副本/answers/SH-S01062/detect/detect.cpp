#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
const float ERR=0.000001;
int n,m,x[N],d[N],v[N],a[N],ans,T,q[29][29],cnt;
float V,L;
bool isA(){
	for (int i=1;i<=n;i++){
		if (a[i]!=0) return 0;
	}
	return 1;
}
void solveA(){
	ans=0;
	for (int i=1;i<=n;i++){
		if (v[i]>V and d[i]<=x[m]) ans++;
	}
	cout<<ans<<" "<<m-1<<endl;
}
bool isB(){
	for (int i=1;i<=n;i++){
		if (a[i]<=0) return 0;
	}
	return 1;
}
void solveB(){
	ans=0;
	for (int i=1;i<=n;i++){
		if (d[i]>x[m]) continue;
		if (v[i]>V){
			ans++;
			continue;
		}
		float p=(v[i]*v[i]*1.0+2.0*a[i]*(x[m]-d[i]))*1.0;
		p=sqrt(p);
		if (p-V>ERR) ans++;
	}
	cout<<ans<<" "<<m-1<<endl;
}
void solve20(){
	for (int i=1;i<=n;i++) q[i][0]=0;
	for (int i=1;i<=m;i++) q[0][i]=0;
	ans=0;
	int qry=0;
	float p=0.0;
	for (int i=1;i<=n;i++){
		if (d[i]>x[m]) continue;
		if (v[i]<=V and a[i]<=0) continue;
		for (int j=1;j<=m;j++){
			if (x[j]<d[i]) continue;
			p=(v[i]*v[i]*1.0+2.0*a[i]*(x[j]-d[i]))*1.0;
			if (p<0) break;
			p=sqrt(p);
			if (p-V>ERR){
				q[i][j]=1;
				q[i][0]++;
				q[0][j]=q[0][j]|(1<<i);
			}
		}
		if (q[i][0]>0){
			ans++;
			qry=qry|(1<<i);
		}
	}
	int pre=m+1,prn=0;
	for (int i=0;i<(1<<m);i++){
		cnt=0,prn=0;
		for (int k=0;k<m;k++){
			if ((i>>k)&1){
				cnt=cnt|q[0][k+1];
				prn++;
			}
		}
		if (cnt==qry){
			pre=min(pre,prn);
		}
	}
	cout<<ans<<" "<<m-pre<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	for (int qw=1;qw<=T;qw++){
		cin>>n>>m>>L>>V;
		for (int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for (int i=1;i<=m;i++){
			cin>>x[i];
		}
		if (isA()) solveA();
		else if (isB()) solveB();
		else if (n<=20 and m<=20) solve20();
	}
	return 0;
}

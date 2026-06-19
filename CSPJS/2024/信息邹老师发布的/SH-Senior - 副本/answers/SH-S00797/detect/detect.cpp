#include<bits/stdc++.h>
using namespace std;
int T,n,m,L,V;
int p[100005],d[100005],v[100005],a[100005];
void solve_1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(d[i]<=p[m]&&v[i]>V){
			ans++;
		}
	}
	cout<<ans<<' '<<m-1<<endl;
}
void solve(){
	int ans=0,pai[100005]={0};
	for(int i=1;i<=n;i++){
		if(a[i]>=0){
			if(pow(v[i],2)+2*a[i]*(p[m]-d[i])>V*V){
				ans++;
				pai[m]++;
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(pow(v[i],2)+2*a[i]*(p[i]-d[i])>V*V){
					ans++;
					pai[i]++;
				}
			}
		}
	}
	cout<<ans<<' ';
	ans=0;
	for(int i=1;i<=m;i++){
		if(pai[i]==0){
			ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>m>>L>>V;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
			if(a[i]){
				flag=0;
			}
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		if(flag){
			solve_1();
		}
		else{
			solve();
		}
	}
	return 0;
}

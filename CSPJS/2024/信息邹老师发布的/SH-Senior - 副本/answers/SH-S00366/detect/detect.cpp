#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10; 
int t,n,m;
long long L,V;
long long d[N],v[N],a[N],p[N];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		//输入 
		cin>>n>>m>>L>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			int x;
			cin>>p[i];
		}
		//计算超速车辆数量 
		int ans=0;
		bool lst=false; 
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(d[i]<=p[m] && v[i]>V){
					lst=true;
					ans++;
					//cout<<i<<"\n";
				}
			}
			if(a[i]>0){
				if(d[i]*a[i]*2 + v[i]*(V-v[i])*2 + (V-v[i])*(V-v[i]) < p[m]*a[i]*2){
					lst=true;
					ans++;
					//cout<<i<<"\n";
				}
			}
		}
		cout<<ans<<" ";
		//计算使用的测速仪
		ans=lst;
		cout<<m-ans<<"\n";
	}
	return 0;
}


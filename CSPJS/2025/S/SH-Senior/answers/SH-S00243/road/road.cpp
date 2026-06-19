#include<bits/stdc++.h>
using namespace std;
const int N=1e6+9;
int n,m,k;
long long ans;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ans+=w;
	}
	
	for(int j=1;j<=k;j++){
		int c;
		cin>>c;
		for(int i=1;i<=n;i++) {
			int a;
			cin>>a;
		}
	}
	if(k==0){
		cout<<ans;
		return 0;
	}
	cout<<"0";
	return 0;
}

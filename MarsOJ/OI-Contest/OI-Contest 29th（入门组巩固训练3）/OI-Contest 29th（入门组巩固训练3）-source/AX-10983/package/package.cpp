#include<bits/stdc++.h>
using namespace std;
	int f[1000000];
int main(){
	freopen("package.in","r",stdin);
	freopen("package.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++){
		cin>>f[i];
	}
	long long cnt=0;
	while(n--){
		int t,w;
		cin>>t>>w;
		cnt+=1ll*f[w];
	}
	cout<<cnt;
	return 0;
}


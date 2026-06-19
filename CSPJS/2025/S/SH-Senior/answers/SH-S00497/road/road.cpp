#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
int n,m,k,a[N],b[N],c[N];
int main(){
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		ans+=c[i];
	}
	cout<<ans<<endl;
	
	return 0;
}

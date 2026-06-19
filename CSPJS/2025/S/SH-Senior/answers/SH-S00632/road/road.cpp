#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1000005],b[1000005],val[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i]>>b[i]>>val[i];
	}
	sort(val+1,val+m+1);
	int ans;
	for(int i=m;i>=m/2;i--){
		ans+=val[i];
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
} 

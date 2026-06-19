#include<bits/stdc++.h>
using namespace std;
int t,n,a[100005][5],cnt[5],w[5],dp[100005][5];
bool flag[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int o,p,q,x,y,z;
			cin>>o>>p>>q>>x>>y>>z;
			cout<<max(o+max(y,z),max(p+max(x,z),q+max(x,y)))<<endl;
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

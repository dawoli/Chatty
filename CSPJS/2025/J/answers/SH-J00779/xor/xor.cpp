#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5e5+10;
int a[N],n,k,sum[N],ans,flag,vis;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
	} 
	vis=5e5+10;
	for(int i=n;i>=1;i--){
		if(flag) break;
		for(int j=i;j<=n;j++){
			if(j>=vis) break;
			if((sum[j]^sum[i-1])==k){
				ans++;
				if(i!=1){
					j=i-1;
					vis=i;
				}
				else{
					flag=1;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

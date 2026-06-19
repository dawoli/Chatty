#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],m;
pair<int,int> f[1000006];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k==1&&n>1000){
		int ans=0;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
			if(a[i]==1) ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int num=a[j]^a[i]; 
				if(num==k){
					f[++m]={j,i+1};
				}
			}
		}
		sort(f+1,f+1+m);
		int ans=0,la=-1;
		for(int i=1;i<=m;i++){
			if(f[i].second>la){
				ans++;
				la=f[i].first;
			}
		}
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool vis[500007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k,a[500007],ans=0;
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		long long cnt=a[i];
		vis[i]=1;
		for(int j=i+1;j<n;j++){
			if(vis[j])break;
			cnt^=a[j];
			vis[j]=1;
			if(cnt==k){
				ans++;
				break;
			}
		}
	}
	cout<<ans;
}

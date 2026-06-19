#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k; 
ll a[500010];
bool vis[500010];
int cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			cnt++;
			vis[i]=1;
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		ll sum=a[i];
		for(int j=i+1;j<=n;j++){
			if(vis[j]) break;
			sum^=a[j];
			if(sum==k){
				cnt++;
				i=j;
				break;
			}
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

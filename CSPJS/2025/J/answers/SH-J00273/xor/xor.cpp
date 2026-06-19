#include<bits/stdc++.h>
using namespace std;
int n,k;
int ans;
int a[500005];
int b[500005];
int h;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) b[i]=b[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=h;j<i;j++){
			if((b[i]^b[j])==k){
				ans++;
				h=i;
				break;
			}
		}
	}
	cout<<ans; 
	return 0;
}

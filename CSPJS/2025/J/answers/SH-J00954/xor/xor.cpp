#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int a[500005];
bool vis[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==k) {
			cnt++;
			vis[i]=1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			a[i]^=a[j];
			if(vis[j]){
				i=j+1;
				break;
			}
			if(a[i]==k) {
				cnt++;
				i=j+1;
				break;
			}
		}
	}
	cout<<cnt;
}

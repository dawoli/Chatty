#include<bits/stdc++.h>
using namespace std;
bool b[1005][1005];
int a[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	bool f=1;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) f=0;
	}
	if(k==0) {
		if(f){
			if(n==1) cout << 0;
			else if(n==2) cout << 2;
			else cout << n/2;
		}
		else{
			int ans=0;
			for(int i=2;i<=n;i++){
				if(a[i-1]==a[i]){
					ans++;
					i++;
				}
			}
			cout << ans;
		}
	}
	
}

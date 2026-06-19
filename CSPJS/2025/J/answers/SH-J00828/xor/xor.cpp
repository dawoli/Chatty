#include<bits/stdc++.h>
int n,k,ans;
int f[500005];
int main(){
	std::freopen("xor.in","r",stdin);
	std::freopen("xor.out","w",stdout);
	std :: cin >> n >> k;
	for(int i = 1;i <= n;i++){
		int temp;
		std :: cin>>temp;
		f[i]=temp^f[i-1]; 
	}	
	for(int l = 1;l <= n;l++){
		for(int r = l;r <= n;r++){
			if((f[l-1]^f[r])==k){
				ans++;
				l=r;
				break;
			}
		}
	}
	std :: cout << ans;
}

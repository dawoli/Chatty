#include <bits/stdc++.h> 
using namespace std;
#define int long long

int n,k,a[500005],s[500005],b[500005],x,ans;

signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin >> n >> k;
	for(int i=1;i <= n;i++){
		cin >> a[i];
		s[i] = s[i-1] ^ a[i];
	}
	for(int i=1;i <= n;i++){
		for(int j=i;j >= 1;j--){
			if((s[i]^s[j-1]) == k){
				b[i] = j;
				break;
			}
		}
	}
	for(int i=1;i <= n;i++){
		if(b[i] != 0&&b[i] > x){
			x = i;
			ans++;
		}
	}
	cout << ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5005],f[5005][5005],maxn,sum,ans;
bool g[5005];
int lowbit(int n){
	return (n&(-n));
}
int gb(int n){
	int ans = 0;
	while(n){
		n -= lowbit(n);
		ans++;
	}
	return ans;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	for(int i = 0;i < (1<<n);i++){	
		if(gb(i) >= 3){
			maxn = 0;
			sum = 0;
			for(int j = 1;j <= n;j++){
				if(((i>>(j-1))&1) == 1){
					sum += a[j];
					maxn = max(maxn,a[j]);
				}
			}
			if(sum > maxn*2){
				ans++;
				ans %= 998244353;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

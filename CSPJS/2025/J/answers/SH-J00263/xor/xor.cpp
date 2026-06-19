#include<bits/stdc++.h>
using namespace std;
#define N 1145141
int n,k,a[N],sum[N],cnt[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i = 1;i <= n;i++) cin>>a[i],sum[i] = sum[i - 1] ^ a[i];
	int lst = 0,ans = 0;
	cnt[0]++; 
	for(int i = 1;i <= n;i++){
		if(cnt[sum[i] ^ k]){
			ans++;
			for(int j = lst;j < i;j++) cnt[sum[j]]--;
			lst = i;
		}
		cnt[sum[i]]++;
	}
	cout<<ans<<endl;
}

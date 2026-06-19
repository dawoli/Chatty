#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
int n,k,ans;
int a[maxn],sum[maxn];
map<int,bool> mp;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&a[i]);
	}
	for(int i = 1;i <= n;i ++){
		sum[i] = sum[i - 1] ^ a[i];
	}
	mp[0] = true;
	for(int i = 1;i <= n;i ++){
		mp[sum[i]] = true;
		if(mp[k ^ sum[i]]){
			ans ++;
			mp.clear();
			mp[sum[i]] = true;
		}
	}
	printf("%d",ans);
	return 0;
}

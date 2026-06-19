#include<bits/stdc++.h>
#define ll long long
using namespace std;
int T,n;
int a[200010],pre[200010];
ll f[200010];
ll answer;
int bucket[1000010];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		memset(bucket,0,sizeof(bucket));
		memset(f,0,sizeof(f));
		ll temp = 0;
		cin>>n;
		for(int i = 1;i <= n;i++){
			cin>>a[i];
			if(bucket[a[i]] == i - 1 && i != 1){
				pre[i] = 0;
				temp += a[i];
			}else{
				pre[i] = bucket[a[i]];
			}
			bucket[a[i]] = i;
		}
		for(int i = n;i >= 1;i--){
			if(pre[i] != 0) f[pre[i] + 1] = max(f[pre[i] + 1],f[i]+a[i]);
			f[i - 1] = max(f[i - 1],f[i]);
		}
		cout<<(f[1]+temp)<<endl;
	}
	return 0;
}


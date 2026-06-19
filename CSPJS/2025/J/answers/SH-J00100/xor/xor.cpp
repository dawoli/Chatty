#include<bits/stdc++.h>
using namespace std;
int a[500010],sum[500010];
map<int,int> f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,ans=0;
	cin>>n>>k;
	f[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
		if(f[(sum[i]^k)]){
			ans++;
			f.clear();
		}
		f[sum[i]]++;
	}
	cout<<ans;
	return 0;
}

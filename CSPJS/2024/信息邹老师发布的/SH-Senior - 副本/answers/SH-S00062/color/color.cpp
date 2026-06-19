#include <bits/stdc++.h>
using namespace std;
long long t,n,a[200005],c[200005],v[1000005],ans,flag,ti;
void dfs(int k){
	if(k==n){
		long long r = 0,b = 0,sum = 0;
		for(int i = 1;i<=n;i++){
			if(c[i]==1){
				if(a[i]==r) sum+=a[i];
				r = a[i];
			}
			else if(c[i]==2){
				if(a[i]==b) sum+=a[i];
				b = a[i];
			}
		}
		ans = max(ans,sum);
		return;
	}
	if(v[a[k+1]]==1){
		dfs(k+1);
		return;
	}
	c[k+1] = 1;
	dfs(k+1);
	c[k+1] = 2;
	dfs(k+1);
	c[k+1] = 0;
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		flag = 0;
		memset(v,0,sizeof(v));
		for(int i = 1;i<=n;i++){
			cin >> a[i];
			if(v[a[i]]>0&&a[i]!=ti){
				flag++;
				ti = a[i];
				v[a[i]]++;
			}
			else v[a[i]] = 1;
		}
		if(flag==0) cout << 0 << endl;
		else if(flag==1) cout << (v[ti]-1)*ti << endl;
		else{
			dfs(0);
			cout << ans;
		}
	}
	return 0;
}

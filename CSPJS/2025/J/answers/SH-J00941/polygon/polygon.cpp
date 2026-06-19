#include<bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
int n,ans,maxn,sum;
int a[5005],vis[5005];

void dfs(int step,int index){
	if(step>=3 && step<=n+1 && sum>maxn*2){
		ans++;
		ans%=MOD;
	}
	if(step > n+1)	return;
	int tmp=maxn;
	for(int i=index;i<=n;i++){
		if(vis[i]==0){
			sum+=a[i];
			vis[i]=1;
			maxn=max(maxn,a[i]);
			dfs(step+1,i+1);
			sum-=a[i];
			vis[i]=0;
			maxn=tmp;
		}
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int m=0;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		m=max(m,a[i]);
	}
	if(m==1){
		cout << n-2;
	}
	else{
		sort(a+1,a+n+1);
		dfs(1,1);
		cout << ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005];char b[100005];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	long long ans = 1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i]==0)cnt++;
	}
	if(n-cnt<m){
		cout <<"0";
		return 0;
	}
	for(int i = 1; i <= n; i++){
		ans*=i;
		ans%=998244353;
		cout << ans << endl;
	}cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

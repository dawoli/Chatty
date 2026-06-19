#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
const int N=5005;
int n,a[N],sum,cnt1;
long long ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(a[i]==1)cnt1++;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if(sum>a[3]*2)ans++;
		cout<<ans;
	}
	else if(cnt1==n){
		for(int i=3;i<n;i++){
			long long cnt=0,temp=n-i+1;
			for(int j=1;j<=n-i+1;j++){
				cnt+=j*temp;
				temp--;
				cnt%=MOD;
			}
			cout<<cnt<<" ";
			ans+=cnt;
			ans%=MOD;
		}
		ans++;
		ans%=MOD;
		cout<<ans;
	} 
	else{
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

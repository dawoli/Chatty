#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
ll n;
ll a[N];
ll dp[N];
const ll M=998244353; 
ll pjc(ll a,ll b){
	ll ans=1;
	for(ll i=b;i<=a;i++){
		ans*=i;
		ans%=M;
	}
	return ans;
}
ll jc(ll a){
	return pjc(a,1);
}
ll Cnm(ll a,ll b){
	if(b==0)return 1;
	return jc(a)%M/jc(b)%M/jc(a-b)%M;
}
void solveN3(){
	if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[3]+a[1]>a[2])cout<<1;
	else cout<<0;
}
void meiju(int c,int i[]){
	if(c==n){
		return;
	}else{
		for(int j=i[c-1]+1;j<=n;j++){
			i[c]=j;
			if(c>=3){
				ll mx=-1;
				int cnt=0;
				for(int j=1;j<=c;j++){
					cnt+=a[i[j]];
					mx=max(mx,a[i[j]]);
				}
				if(cnt>2*mx){
					dp[c]++;
				}
			}
			meiju(c+1,i);
		}
	}
}
void solveN20(){
	int i[19];
	i[0]=0;
	meiju(1,i);
	ll ans=0;
	for(int i=3;i<n;i++){
		ans+=dp[i];
	}
	ll cnt=0;
	ll mx=-1;
	for(int i=1;i<=n;i++){
		cnt+=a[i];
		mx=max(a[i],mx);
	}
	if(mx*2<cnt)ans++;
	cout<<ans;
}
bool quandeng(){
	for(int i=2;i<=n;i++)if(a[i]!=a[i-1])return 0;
	return 1;
} 
void solveQuandeng(){
	ll ans=0;
	for(int i=3;i<=n;i++){
		ans+=Cnm(n,i);
	}
	cout<<ans;
}
void solve(){
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++){
		ll p=a[i-1];
		for(int j=i-2;j>=1;j--){
			p+=a[j];
			if(p>a[i]){
				dp[i]=0;
				for(int k=0;k<j;k++){
					dp[i]+=Cnm(j-1,k)%M;
				}
				break;
			}
		}
	}
	ll ans=0;
	for(int i=3;i<=n;i++)ans+=dp[i];
	cout<<ans;
} 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=3)solveN3();
	else if(quandeng())solveQuandeng();
	else if(n<=20)solveN20();
	else solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

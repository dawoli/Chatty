#include<iostream>
using namespace std;
typedef long long ll;
ll n,m;
char s[506];
ll ans=1;
ll arr[1009];
ll cnt;
ll M=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]=0)cnt++;
	}
	if(cnt+m>n){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%M;
	}
	cout<<ans;
	return 0;
//	998244353
}

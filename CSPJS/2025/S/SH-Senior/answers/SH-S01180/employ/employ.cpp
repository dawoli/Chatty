#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=509;
const ll MOD=998244353;
ll n,m;
bool all1=1;
char s[N];
ll c[N];
void workall1(){
	ll sum=1;
	for(ll i=n;i>=1;i--){
		sum*=i;
		sum%=MOD;
	}
	cout<<sum;
}
void workm1(){
	int i=1;
	for(;i<=n;i++){
		if(s[i]=='1'){
			break;
		}
	}
	i--;
	sort(c+1,c+n+1);
	int num=upper_bound(c+1,c+n+1,i)-c;
	num=n-num+1;
	ll sum=num;
	for(ll i=n-1;i>=1;i--){
		sum*=i;
		sum%=MOD;
	}
	cout<<sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0'){
			all1=0;
		}
	}
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	if(all1){
		workall1();
	}else if(m==1){
		workm1();
	}else{
		int ans=0;
		int p[N];
		for(int i=1;i<=n;i++){
			p[i]=i;
		}
		do{
			int prev=0,num=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1'&&prev<c[i]){
					num++;
				}else{
					prev++;
				}
			}
			if(num>=m){
				ans++;
			}
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	return 0;
}

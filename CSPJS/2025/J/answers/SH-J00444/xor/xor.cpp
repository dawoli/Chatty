#include<iostream>
using namespace std;
typedef long long ll;
ll a[500001],s[500001];
int n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	int ca=0,cb=0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		if(a[i]==1){
			ca++;
		}
		if(a[i]>=0&&a[i]<=1){
			cb++;
		}
	}
	if(ca==n){
		cout<<n/2;
		return 0;
	}else if(cb==n){
		int l=1;
		for(int r=1;r<=n;++r){
			if((s[l-1]^s[r])==k){
				ans++;
				l=r+1;
			}
		}
		cout<<ans;
		return 0; 
	}
	int l=1;
	for(int r=1;r<=n;++r){
		if((s[l-1]^s[r])==k){
			ans++;
			l=r+1;
		}
	}
	cout<<ans;
	return 0;
}

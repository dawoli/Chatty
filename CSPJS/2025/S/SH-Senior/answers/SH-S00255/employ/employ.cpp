#include<bits/stdc++.h>
using namespace std;
int MOD=998244353;
int main(){
//	freopen("employ.in","r",stdin);
//	freopen("employ.out","w",stdout);
	int n,m;
	bool b[509]={};
	int a[509]={};
	long long ans=0;
	cin>>n>>m;
	bool flag1=true;
	int lol=0;
	for(int i=0;i<n;i++){
		char k;
		do k=getchar();
		while(k==' ');
		b[i]=k-'0';
		if(b[i]!=1) flag1=false;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==0) lol++;
	}
	sort(a,a+n);
	if(m==n){
		if(flag1==false||lol!=0){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=2;i<=n;i++){
			ans*=n;
			ans%=MOD;
		}
		cout<<ans%MOD;
	}
	else if(m==1){
		ans=1;
		for(int i=n;i>=1;i--){
			ans*=max(0,i-a[i+1]);
			ans%=MOD;
		}
		long long ans2=1;
		for(int i=2;i<=n;i++){
			ans2*=n;
			ans2%=MOD;
		}
		if(ans2<ans) ans2+=MOD;
		cout<<ans2-ans;
	}
	else{
		ans=0;
		while(next_permutation(a,a+n)){
			int cnt=0,cnt2=0,cnt3=0;
			for(int i=0;i<n;i++){
				if(a[i]<=cnt){
					cnt++;
//					cnt2++;
				}
				else if(b[i]!=1){
					cnt++;
					cnt2++;
				}
				else{
					cnt2++;
					cnt3++;
				}
			}
			if(cnt3>=m) ans++;
		}
		cout<<ans%MOD;
	}
	return 0;
}



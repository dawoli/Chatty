#include<bits/stdc++.h> 
using namespace std;
const int mod=998244353;
int n,ans;
int a[5005]; 
int num(int l, int j){
	int cnt=0;
	int q=0;
	for(int i=1; i<=n; i++){
		for(int j=i; j<=n; j++){
			q+=a[j];
			for(int k=j; k<)
			if(q<l){
				cnt=(cnt+1)%mod;
			}
		}
	}
	return cnt;
}
int main(){
//	freeopen("polygon.in","r","stdin");
//	freeopen("polygon.out","w","stdout");
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
	sort(a+1, a+n+1);
	for(int i=n; i>0; i--){
		ans=(ans+num(a[i],i)%mod)%mod;
	}
	cout<<ans;
	return 0;
}

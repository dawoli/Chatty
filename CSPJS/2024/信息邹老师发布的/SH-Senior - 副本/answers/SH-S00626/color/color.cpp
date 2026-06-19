#include<bits/stdc++.h>
using namespace std;
inline void solve(){
	unsigned long long n;
	cin>>n;
	unsigned long long x,sum=0;
	cin>>x;
	for(unsigned long long i=1;i<n;i++){
		cin>>x;
		sum+=x;
	}
	cout<<sum;
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}

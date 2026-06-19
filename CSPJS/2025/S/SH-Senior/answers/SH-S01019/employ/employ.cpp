#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	
	cin >> n >> m;
	
	long long ans=0,tans=1;
	for(int j=1;j>=m;j--){
		for(int i=n;i>=j;i--){
			tans=tans*i%998244353;
		}
		ans=(ans+tans)%998244353;
	}
	
	cout << ans;
}

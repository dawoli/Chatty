#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b+c>2*max(a,max(b,c))){
			cout<<1;
			return 0;
		}
		else {
			cout<<0;
			return 0;
		}
	}
}

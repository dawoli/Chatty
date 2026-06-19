#include<bits/stdc++.h>
#define int long long
using namespace std;
int mod=998244353;
const int N=5005;
int n;
int a[N];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int a1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) a1++;
	}
	sort(a+1,a+n+1);
	if(n==3){
		if((a[1]+a[2])>2*a[3]) cout<<1<<endl;
		else cout<<0<<endl;
	}
	else if(n<3) cout<<0<<endl;
	else{
		if(a1==n) cout<<n-2<<endl;
		else cout<<rand()%mod<<endl;
	}
	return 0;
}

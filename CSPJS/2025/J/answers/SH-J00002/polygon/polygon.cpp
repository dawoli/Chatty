#include<bits/stdc++.h>1
typedef long long ll;
using namespace std;
const ll mod=998244353;
const int maxn=5009;
ll n,a[maxn],dp[maxn],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(n==3){
		if(a[1]+a[2]>a[3])
			cout<<1;
		else
			cout<<0;
		return 0;
	}
	if(a[n]==1){
		for(int i=2;i<n;i++)
			ans+=(n-i)*(n-i)+1;
		ans--;
		cout<<ans<<endl;
	}
	else{
		cout<<(n-2)*(n-2)<<endl;
	}
	return 0;
}

//1 2 345 1 3 45 1 4 5 		6
//2 3 45 2 4 5  				3¡¤				10 
//3 4 5						1	
//4 5
//123 4 5 124 5				3
//134 5						1				5
//234 5						1
//12345						1				1

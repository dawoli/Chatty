#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int t,n;
string dp[N]={"0","-1","1","7","4","2","6","8","10"};
string mn(string a,string b){
	if(a=="0"||a.length()>b.length())return b;
	if(a.length()<b.length())return a;
	return min(a,b);
}
void solve(){
	for(int i=9;i<N;i++){
		dp[i]="0";
	}for(int i=9;i<N;i++){
		for(int j=2;j<=7;j++){
			if(j!=6)dp[i]=mn(dp[i],dp[i-j]+dp[j]);
			else dp[i]=mn(dp[i],dp[i-j]+'0');
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	solve();
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n]<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,stick[5009],cnt;
ll dp[509][509];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>stick[i];
		cnt+=stick[i];
	}
	if(n<3)cout<<"0";
	else if(n==3&&cnt>(2*(*max_element(stick,stick+n)))){
		cout<<"1";
	}
	else if(n==3&&cnt<=(2*(*max_element(stick,stick+n)))){
		cout<<"0";
	}
	return 0;
}		

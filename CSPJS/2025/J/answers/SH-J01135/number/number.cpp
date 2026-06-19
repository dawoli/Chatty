#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char c;
ll x[19];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c){
		if(c-'0'>=0&&c-'9'<=0){
			x[c-'0']++;
		}
	}
	for(ll i=9;i>=0;i--){
		for(ll j=0;j<x[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int a[10];

signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
}

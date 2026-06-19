#include<bits/stdc++.h>
using namespace std;
string s;
int t[10];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	s=" "+s;
	int n=s.size();
	for(int i=1;i<=n;i++){
		if('0'<=s[i] && s[i]<='9'){
			t[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
	//#Shang4Shan3Ruo6Shui4
	return 0;
}

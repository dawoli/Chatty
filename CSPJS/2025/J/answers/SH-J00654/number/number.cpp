#include<bits/stdc++.h>
using namespace std;
int sum[11];
int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	string s;
	cin>>s;
	for(int i=0;i<int(s.length());i++){
		if(s[i]<='9' && s[i] >= '0'){
			sum[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sum[i];j++){
			cout<<i;
		}
	}
	return 0;
}

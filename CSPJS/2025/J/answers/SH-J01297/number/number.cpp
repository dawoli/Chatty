#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
string s, a;
int t , p[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>> s;
	for (int i =0 ;i < s.length();i++){
		if(s[i]>='0' && s[i] <= '9'){
			p[s[i]-'0']++;
		}
	}
	for (int i = 9;i >= 0;i--){
		for(int j = 0;j < p[i] ;j ++){
			cout << i;
		}
	}
	return 0;
}

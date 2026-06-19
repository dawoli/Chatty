#include<bits/stdc++.h>
using namespace std;
int c[100];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++) {
		c[s[i]-48]++;
	}
	for(int i=9;i>=0;i--) {
		while(c[i]--) {
			cout<<i;
		}
	}
	return 0;
}

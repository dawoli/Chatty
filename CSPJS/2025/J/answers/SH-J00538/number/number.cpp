#include<bits/stdc++.h>
using namespace std;
string s;
int t[20];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}

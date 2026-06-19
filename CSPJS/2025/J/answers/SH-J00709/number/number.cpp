#include<bits/stdc++.h>
using namespace std;
string s;
int len,cnt,b[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if('0'<=s[i] && s[i]<='9') b[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(b[i]--) printf("%d",i);
	}
	return 0;
}

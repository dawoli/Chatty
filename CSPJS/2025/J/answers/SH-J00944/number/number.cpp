#include <bits/stdc++.h>
using namespace std;
string s;
int a[10]={};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int s_=s.length();
	for(int i=0;i<s_;i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=10)
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			num[s[i]-'0']++;
		}
	}
	int flag=0;
	for(int i=1;i<=9;i++){
		if(num[i])flag++;
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for (int i=10;i>=0;i--){
		for (int j=1;j<=num[i];j++){
			cout<<i;
		}
	}
} 

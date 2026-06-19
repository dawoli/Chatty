#include<bits/stdc++.h>
using namespace std;
string s;
int cnt,num[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
			num[cnt++]=s[i]-'0';
	}
	sort(num,num+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
} 

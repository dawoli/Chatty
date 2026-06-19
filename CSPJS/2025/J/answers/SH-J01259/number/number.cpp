#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int s1=s.size();
	int arr[10]={};
	for(int i=0;i<s1;i++){
		if('0'<=s[i]&&s[i]<='9'){
			arr[s[i]-'0']++;
		}
	}
	string s2;
	for(int i=9;i>=0;i--){
		for(int j=0;j<arr[i];j++){
			s2+=char(i+'0');
		}
	}
	int s3=s2.size();
	for(int i=0;i<s3;i++){
		cout<<int(s2[i]-'0');
	}
	return 0;
}
//8:49 I love CCF 
//8:59补上的8:50的 刚做完签到题电脑网炸了什么意思 

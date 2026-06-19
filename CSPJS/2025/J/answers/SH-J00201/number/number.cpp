#include <bits/stdc++.h>
using namespace std;
int t[1000005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","W",stdout);
	string s,s2;
	cin >> s;
	if(s=="1"||s=="2"||s=="3"||s=="4"||s=="5"||s=="6"||s=="7"||s=="8"||s=="9"||s=="0"){
		cout << s;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			s2+=s[i];
		}
	} 
	for(int i=0;i<s2.size();i++){
		s2[i]=s2[i]-'0';
		t[i]=s2[i];
	}
	sort(t,t+s2.size(),cmp);
	for(int i=0;i<s2.size();i++){
		cout << t[i];
	}
	return 0;
}

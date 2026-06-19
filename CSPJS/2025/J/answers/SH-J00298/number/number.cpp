#include<bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	if(a>='0'&&a<='9'&&b>='0'&&b<='9'){
		return a>b;
	}if(a>='0'&&a<='9'){
		return true;
	}else{
		return false;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<s.length();i++){
		if(s[i]>='a'&&s[i]<='z') return 0;
		cout<<s[i];
	}
	return 0;
}

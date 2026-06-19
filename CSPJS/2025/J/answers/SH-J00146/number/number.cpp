#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,s2;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			s2+=s[i];
		}
	}
	sort(s2.begin(),s2.end());
	for(int i=s2.size()-1;i>=0;i--){
		cout<<s2[i];
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[23];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
//	bool fg=0;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9' && s[i]>='0'){
			a[s[i]-'0']++;
		//	if(s[i]!='0')fg=1;
		}
	}for(int i=10;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}cout<<endl;
	return 0;
}

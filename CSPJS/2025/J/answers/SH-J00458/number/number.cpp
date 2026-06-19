#include<bits/stdc++.h>
using namespace std;

int sh[10]={};
string s;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			sh[s[i]-'0']+=1;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=sh[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}

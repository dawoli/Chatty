#include<bits/stdc++.h>
using namespace std;
int k[10]={};
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9'&&s[i]>='0'){
			k[s[i]-'0']++;
		}
	}
	bool flag=0;
	for(int i=9;i>=0;i--){
		for(int j=1;j<=k[i];j++){
			cout<<i;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[s[i]-'0']++;
	}
	string ans="";
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			for(int j=1;j<=a[i];j++) ans+=char(48+i);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

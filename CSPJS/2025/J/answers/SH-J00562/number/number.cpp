#include<bits/stdc++.h>
using namespace std;
string s,ans;
int len,n;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.length();
	for(int i=0;i<len;i++){
		if(s[i]>='0'&&s[i]<='9') ans+=s[i];
	}
	sort(ans.begin(),ans.end(),cmp);
	cout<<ans;
	return 0;
}

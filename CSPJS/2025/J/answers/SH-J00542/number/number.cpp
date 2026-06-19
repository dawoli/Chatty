#include<bits/stdc++.h>
using namespace std;
int ans[1001000];
string s;
int main(){
	freopen("number.in","r",stdin);	
	freopen("number.out","w",stdout);
	
	int t=0;
	while(cin>>s){
		for(int i=0;i<s.size();i++){
			if('0'<=s[i]&&s[i]<='9') ans[t++]=s[i]-'0';
		}
	}
	sort(ans,ans+t,greater<int>());
	for(int i=0;i<t;i++){
		cout<<ans[i];
	}
}

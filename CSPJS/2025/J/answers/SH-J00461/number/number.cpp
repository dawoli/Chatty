#include<bits/stdc++.h>
using namespace std;
long long p=0,ans[1000010],cnt=0;
char c;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (;;){
		if (s[cnt]>='0'&&s[cnt]<='9'){
			ans[++p]=s[cnt]-'0';
		}
		if (cnt==s.length()-1) break;
		cnt++;
	}
	sort(ans+1,ans+p+1);
	for (int i=p;i>0;--i){
		cout<<ans[i];
	}
	return 0;
} 

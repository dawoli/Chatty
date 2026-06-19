#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1000000+10;
string s,ans;
int a[N],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9') a[++cnt] = s[i]-'0';
	}
	sort(a+1,a+1+cnt);
	for(int i=cnt;i>=1;i--){
		ans += a[i]+48;
	}
	while(ans[0]=='0' && ans.size()>1) ans.erase(0,1);
	if(ans=="") cout<<0;
	else cout<<ans;
	return 0;
}

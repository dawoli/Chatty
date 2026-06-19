#include <bits/stdc++.h>
using namespace std;
#define int long long
string s;
int a[1000005],cnt;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for (int i=0;i<s.size();i++){
		if ('0'<=s[i]&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+cnt);
	for (int i=cnt-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
} 

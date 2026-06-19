#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(int i=0;i<s.length();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<a[i];
}

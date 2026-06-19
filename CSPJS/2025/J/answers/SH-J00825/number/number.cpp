#include<bits/stdc++.h>
using namespace std;
string s;
int n[1000006],cur;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++) {
		if(s[i]<='9'&&s[i]>='0') n[++cur]=s[i]-'0';
	}
	sort(n+1,n+cur+1,cmp);
	for(int i=1;i<=cur;i++) cout<<n[i];
	return 0;
}

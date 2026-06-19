#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s;
int cnt[12];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i] and s[i]<='9') cnt[s[i]-'0']++;
	for(int x=9;x>=0;x--)while(cnt[x]--) cout<<x;
	return 0;
}

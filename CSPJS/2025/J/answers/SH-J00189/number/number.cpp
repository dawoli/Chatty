#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;int cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<cnt[i];j++)
			cout<<i;
	return 0;
}

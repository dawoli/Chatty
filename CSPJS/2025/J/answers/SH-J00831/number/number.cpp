#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int cnt[10];
// count sort or TLE
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i] && s[i]<='9')
			cnt[s[i]-'0']++;
	for(int k=9;k>=0;k--)
		for(int i=1;i<=cnt[k];i++)
			cout<<k;
	cout<<endl;
	return 0;
}


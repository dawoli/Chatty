#include<bits/stdc++.h>
using namespace std;
string s;
long long n;
int ans[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i = 0;i < s.length();i++)
		if(s[i] >= '0' && s[i] <= '9')
			ans[n++] = s[i] - '0';
	sort(ans,ans + n);
	for(long long i = n - 1;i >= 0;i--)
		cout<<ans[i];
	return 0;
}

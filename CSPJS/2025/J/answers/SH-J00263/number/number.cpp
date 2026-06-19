#include<bits/stdc++.h>
using namespace std;
signed main(){ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(0);
	string s,t = "";
	cin>>s;
	for(int i = 0;i < (int)s.size();i++)
		if('0' <= s[i] && s[i] <= '9') t += s[i];
	sort(t.begin(),t.end());
	reverse(t.begin(),t.end());
	cout<<t<<endl;
}

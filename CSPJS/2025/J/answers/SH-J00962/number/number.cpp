#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	cin>>s;
	sort(s.begin(),s.end());
	s=s.substr(0,upper_bound(s.begin(),s.end(),'9')-s.begin());
	reverse(s.begin(),s.end());
	cout<<s;
	return 0;
} 

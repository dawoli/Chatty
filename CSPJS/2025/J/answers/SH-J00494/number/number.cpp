#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
if(s.size()==1) cout<<s;
else if (s.size()==2){
	if (s[0]<s[1]) cout<<s[1]<<s[0];
	else cout<<s[0]<<s[1];
}
return 0; 
}

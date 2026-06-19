#include<bits/stdc++.h>
using namespace std;
string s;
int a,b[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		a=s[i]-'0';
		if(a<=9)b[i]=a;
		else b[i]=-1;
	}
	sort(b,b+s.size());
	for(int i=s.size()-1;i>=0;i--)
		if(b[i]>=0)
			cout<<b[i];
	return 0;
}

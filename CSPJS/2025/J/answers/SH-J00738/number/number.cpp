#include<bits/stdc++.h>
using namespace std;
int x[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i=0;i<=s.size()-1;i++)
		x[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=x[i];j++)
			cout<<i;
	return 0;
}

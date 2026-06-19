#include<bits/stdc++.h>
using namespace std;
string s;
int a[16],b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	b=s.size();
	for(int i=0;i<b;i++)
		a[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			cout<<i;
	return 0; 
} 

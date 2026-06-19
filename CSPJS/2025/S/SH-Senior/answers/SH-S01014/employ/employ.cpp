#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[505];
char difficulty[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)	difficulty[i]=s[i]-'0';
	for(int i=0;i<n;i++)	cin>>c[i];
	
	return 0;
}

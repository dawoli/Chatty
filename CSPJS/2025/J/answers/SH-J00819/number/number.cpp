#include<bits/stdc++.h>
using namespace std;
int change(char c){return (c-'0');}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	int n=s.length(),nummm[10]={0};
	for(int i=0;i<n;i++)if(isdigit(s[i]))nummm[change(s[i])]++;
	for(int i=9;i>=0;i--)for(int j=0;j<nummm[i];j++)cout<<i;
	cout<<endl;
	return 0;
}

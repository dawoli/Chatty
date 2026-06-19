#include<bits/stdc++.h>
using namespace std;
int cnt[300];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	for(int i = 0;i<s.size();i++)
		cnt[s[i]]++;
	for(int i = 57;i>=48;i--){
		for(int j = 1;j<=cnt[i];j++)cout<<i-48;
	}
	cout<<endl; 
}

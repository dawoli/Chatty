#include<bits/stdc++.h>
using namespace std;
int sz[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i]))sz[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(sz[i]>0){
			cout<<i;
			sz[i]--;
		}
	}
}

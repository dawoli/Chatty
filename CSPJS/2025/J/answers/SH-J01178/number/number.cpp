#include <bits/stdc++.h>
using namespace std;
int t[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9') t[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(t[i]){
			cout<<i;
			t[i]--;
		}
	}
	return 0;
}

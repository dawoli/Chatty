#include <bits/stdc++.h>
using namespace std;
int ans[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(isdigit(s[i])){
			ans[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<ans[i];j++){
			cout<<i;
		}
	}
	cout<<endl;
	return 0;
}

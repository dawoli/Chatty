#include<bits/stdc++.h>
using namespace std;
long long f[29];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			f[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(f[i]>0){
			cout<<i;
			f[i]--;
		}
	}
	return 0;
}

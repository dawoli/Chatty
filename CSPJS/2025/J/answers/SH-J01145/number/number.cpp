#include <bits/stdc++.h>
using namespace std;
string s;
int num[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(num,0,sizeof(num));
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(num[i]){
			cout<<i;
			num[i]--;
		}
	}
	return 0;
}

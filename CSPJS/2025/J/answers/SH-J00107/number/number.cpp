#include<bits/stdc++.h> 
#define int long long
using namespace std;
int t[10];
bool flag=true;
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			t[s[i]-'0']++;
			if(s[i]!='0')flag=false;
		}
	}if(flag)cout<<0;
	else{
		for(int i=9;i>=0;i--){
			while(t[i]--){
				printf("%lld",i);
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n[s.size()];
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			n[cnt++]=s[i]-'0';
		}
	}
	sort(n,n+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<n[i];
	}
	return 0;
}

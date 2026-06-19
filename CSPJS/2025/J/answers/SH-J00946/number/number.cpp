#include<bits/stdc++.h>
using namespace std;
int a[15];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9')
		a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)
		cout<<i;
	}
	return 0;
}

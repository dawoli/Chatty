#include<bits/stdc++.h>
using namespace std;
//char a[1000005];
int a[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]!=0){
			cout<<i;
			a[i]--;
		}
	}
}

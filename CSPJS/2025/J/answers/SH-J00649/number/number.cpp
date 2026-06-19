#include<bits/stdc++.h>
using namespace std;
string s;
int a[20],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			int t=s[i]-'0';
			a[t]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]--)cout<<i;
	}	
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen(" number.out","w",stdout);
	string s;
	string b;
	int c=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			b+=s[i];
			c+=1;
		}
	}
	int a[c];
	for(int i=0;i<c;i++){
		a[i]=b[i]-48;
	}
	sort(a,a+c);
	for(int i=c-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[50];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s,s1="";
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[int(s[i]-'0')]++;
		}
	}
	for(int i=9;i>=0;i--){
		char x=char(i+'0');
		for(int j=1;j<=a[i];j++){
			s1+=x;
		}
	}
	cout<<s1;
	return 0;
} 

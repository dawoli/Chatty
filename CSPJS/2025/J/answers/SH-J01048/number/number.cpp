#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	string s;
	cin>>s;
	int n=s.size();
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]>0){
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}

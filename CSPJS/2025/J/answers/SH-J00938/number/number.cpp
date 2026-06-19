#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t[10]={};
	int l=s.size();
	for(int i = 0;i < l;i ++){
		if(s[i]<='9'&&s[i]>='0'){
			int p=s[i]-'0';
			t[p]++;
		}
	}
	for(int i = 9;i >= 0;i --){
		while(t[i]){
			t[i]-=1;
			cout<<i; 
		}
	}
	return 0;
}


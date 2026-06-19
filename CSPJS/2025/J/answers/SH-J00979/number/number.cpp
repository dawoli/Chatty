#include<bits/stdc++.h>
using namespace std;
	int m[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int a=s.size();
	for(int i=0;i<a;i++){
		if(s[i]>=48&&s[i]<=57)m[int(s[i])-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<m[i];j++)cout<<i;
	}
	return 0;
} 

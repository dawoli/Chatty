#include<bits/stdc++.h>
using namespace std;
int a[20];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(char c:s){
		if('0'<=c&&c<='9'){
			a[c-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++) cout<<i;
	}
	return 0;
} 

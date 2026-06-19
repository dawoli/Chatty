#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
int main(){
	int al;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
			a[al]=s[i];
			a[al]+=-48;
			al++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<al;j++){
			if(a[j]==i){
				cout<<i;
			}
		}
	}
	return 0;
} 

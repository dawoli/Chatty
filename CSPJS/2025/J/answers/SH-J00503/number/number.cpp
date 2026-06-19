#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sstrings;
	cin>>sstrings;
	long long numberrr[10]={0};
	for(int indexxx=0;indexxx<sstrings.length();indexxx++){
		if(sstrings[indexxx]>='0'&&sstrings[indexxx]<='9')numberrr[sstrings[indexxx]-'0']++;
	}
	for(int indexxx=9;indexxx>=0;indexxx--){
		if(numberrr[indexxx]){
			for(long long jindexx=0;jindexx<numberrr[indexxx];jindexx++){
				cout<<indexxx;
			}
		} 
	}
	
	return 0; 
} 

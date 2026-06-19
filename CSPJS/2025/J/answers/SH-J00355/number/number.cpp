#include<bits/stdc++.h>
using namespace std;
int main(){
	
	string s;
	cin>>s;
	int l=s.size();
	int a[10]={};
	
	for(int i=0;i<l;i++){
		int x=s[i]-'0';
		if(x<0 || x>9){
			continue;
		}else{
			a[x]++;
		}
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}	
	
	
	
	
	
	
	return 0;
}

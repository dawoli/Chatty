#include<bits/stdc++.h>
using namespace std;
int a[10];
int k=0,j=0,t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char c;
	cin>>s;
	int k=0;
	while(k<s.size()){
		c=s[k];
		if('0'<=c&&'9'>=c){
			a[c-'0']++;
		}
		k++;
	} 
	for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

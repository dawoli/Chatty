#include <bits/stdc++.h>
using namespace std;

string s;
int a[15];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	if(a[9]!=0){
		for(int i=1;i<=a[9];i++){
			cout<<9;
		}
	}
	if(a[8]!=0){
		for(int i=1;i<=a[8];i++){
			cout<<8;
		}
	}
	if(a[7]!=0){
		for(int i=1;i<=a[7];i++){
			cout<<7;
		}
	}
	if(a[6]!=0){
		for(int i=1;i<=a[6];i++){
			cout<<6;
		}
	}
	if(a[5]!=0){
		for(int i=1;i<=a[5];i++){
			cout<<5;
		}
	}
	if(a[4]!=0){
		for(int i=1;i<=a[4];i++){
			cout<<4;
		}
	}
	if(a[3]!=0){
		for(int i=1;i<=a[3];i++){
			cout<<3;
		}
	}
	if(a[2]!=0){
		for(int i=1;i<=a[2];i++){
			cout<<2;
		}
	}
	if(a[1]!=0){
		for(int i=1;i<=a[1];i++){
			cout<<1;
		}
	}
	if(a[0]!=0){
		for(int i=1;i<=a[0];i++){
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

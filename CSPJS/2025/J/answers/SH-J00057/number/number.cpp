#include<bits/stdc++.h>
using namespace std;
string n[100013];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	int zero=0,one=0,two=0,three=0,four=0,five=0,six=0,seven=0,eight=0,nine=0;
	for(int i=0;i<n.size();i++){
		if(n[i]=='0'){
			zero++;
		}
		if(n[i]=='1'){
			one++;
		}
		if(n[i]=='2'){
			two++;
		}
		if(n[i]=='3'){
			three++;
		}
		if(n[i]=='4'){
			four++;
		}
		if(n[i]=='5'){
			five++;
		}
		if(n[i]=='6'){
			six++;
		}
		if(n[i]=='7'){
			seven++;
		}
		if(n[i]=='8'){
			eight++;
		}
		if(n[i]=='9'){
			nine++;
		}
	}
	for(int i=1;i<=nine;i++){
		cout<<9;
	}
	for(int i=1;i<=eight;i++){
		cout<<8;
	}
	for(int i=1;i<=seven;i++){
		cout<<7;
	}
	for(int i=1;i<=six;i++){
		cout<<6;
	}
	for(int i=1;i<=five;i++){
		cout<<5;
	}
	for(int i=1;i<=four;i++){
		cout<<4;
	}
	for(int i=1;i<=three;i++){
		cout<<3;
	}
	for(int i=1;i<=two;i++){
		cout<<2;
	}
	for(int i=1;i<=one;i++){
		cout<<1;
	}
	for(int i=1;i<=zero;i++){
		cout<<0;
	}
	return 0;
}

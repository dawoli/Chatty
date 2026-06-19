#include<bits/stdc++.h>
using namespace std;
int x1=0,x2=0,x3=0,x4=0,x5=0,x6=0,x7=0,x8=0,x9=0,x0=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			x0++;
		}else if(s[i]=='1'){
			x1++;
		}else if(s[i]=='2'){
			x2++;
		}else if(s[i]=='3'){
			x3++;
		}else if(s[i]=='4'){
			x4++;
		}else if(s[i]=='5'){
			x5++;
		}else if(s[i]=='6'){
			x6++;
		}else if(s[i]=='7'){
			x7++;
		}else if(s[i]=='8'){
			x8++;
		}else if(s[i]=='9'){
			x9++;
		}
	}
	for(int i=1;i<=x9;i++){
		cout<<9;
	}
	for(int i=1;i<=x8;i++){
		cout<<8;
	}
	for(int i=1;i<=x7;i++){
		cout<<7;
	}
	for(int i=1;i<=x6;i++){
		cout<<6;
	}
	for(int i=1;i<=x5;i++){
		cout<<5;
	}
	for(int i=1;i<=x4;i++){
		cout<<4;
	}
	for(int i=1;i<=x3;i++){
		cout<<3;
	}
	for(int i=1;i<=x2;i++){
		cout<<2;
	}
	for(int i=1;i<=x1;i++){
		cout<<1;
	}
	for(int i=1;i<=x0;i++){
		cout<<0;
	}
	return 0;
}

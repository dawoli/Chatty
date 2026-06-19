#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	long long ans0=0,ans1=0,ans2=0,ans3=0,ans4=0,ans5=0,ans6=0,ans7=0,ans8=0,ans9=0;
	cin>>n;
	for(int  i=0;i<n.size();i++){
		if(n[i]=='0') ans0++;
		if(n[i]=='1') ans1++;
		if(n[i]=='2') ans2++;
		if(n[i]=='3') ans3++;
		if(n[i]=='4') ans4++;
		if(n[i]=='5') ans5++;
		if(n[i]=='6') ans6++;
		if(n[i]=='7') ans7++;
		if(n[i]=='8') ans8++;
		if(n[i]=='9') ans9++; 
}
	for(int i=0;i<ans9;i++){
		cout<<9;
	}
	for(int i=0;i<ans8;i++){
		cout<<8;
	}
	for(int i=0;i<ans7;i++){
		cout<<7;
	}
	for(int i=0;i<ans6;i++){
		cout<<6;
	}
	for(int i=0;i<ans5;i++){
		cout<<5;
	}
	for(int i=0;i<ans4;i++){
		cout<<4;
	}
	for(int i=0;i<ans3;i++){
		cout<<3;
	}
	for(int i=0;i<ans2;i++){
		cout<<2;
	}
	for(int i=0;i<ans1;i++){
		cout<<1;
	}
	for(int i=0;i<ans0;i++){
		cout<<0;
	}
	return 0;
}

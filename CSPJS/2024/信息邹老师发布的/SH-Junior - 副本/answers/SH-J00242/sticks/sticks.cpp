#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	int ans[28]={-1,10,1,7,4,2,6,8};
	cin>>T;
	for (int i=1;i<=T;i++){
		int n;
		cin>>n;
		if (n==1)cout<<-1;
		if (n==2)cout<<1;
		if (n==3)cout<<7;
		if (n==4)cout<<4;
		if (n==5)cout<<2;
		if (n==6)cout<<6;
		if (n==7)cout<<8;
		if (n>7){
			int m=n%7;
			if (m==1)cout<<10;
			if (m==2)cout<<18;
			if (m==3)cout<<22;
			if (m==4)cout<<20;
			if (m==5)cout<<28;
			if (m==6)cout<<68;
			if (m==0)cout<<8;
			for (int j=1;j<n/7;j++)cout<<8;
		}
		cout<<endl;
	}
	return 0;
}

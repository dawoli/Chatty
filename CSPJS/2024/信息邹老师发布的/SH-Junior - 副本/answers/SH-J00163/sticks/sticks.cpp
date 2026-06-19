#include<bits/stdc++.h>
using namespace std;
const int N=20000,T=60;
int sn[7]={-1,-1,1,7,4,5,6};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		int n;
		cin>>n;
		if(n%7==0&&n!=0)for(int j=1;j<=n/7;j++)cout<<8;
		else if(n<7)cout<<sn[n];
		else{
			int cnt8=n/7-1;
			n-=cnt8*7;
			if(n==8)cout<<10;
			if(n==9)cout<<24;
			if(n==10)cout<<25;
			if(n==11)cout<<20;
			if(n==12)cout<<28;
			if(n==13)cout<<68;
			for(int j=1;j<=cnt8;j++)cout<<8;
		}
		cout<<endl;
	}
	return 0;
}

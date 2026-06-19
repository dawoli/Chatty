#include<bits/stdc++.h>
using namespace std;
int a[]={0,-1,1,7,4,2,6,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n<=7){
			cout<<a[n]<<"\n";
			continue;
		}
		if(n%7==0);
		else if(n%7==1){
			cout<<"10";
			n-=8;
		}
		else if(n%7==2){
			cout<<"1";
			n-=2;
		}
		else if(n%7==3){
			if(n==10){
				cout<<"22\n";
				continue;
			}
			cout<<"200";
			n-=17;
		}
		else if(n%7==4){
			cout<<"20";
			n-=11;
		}
		else if(n%7==5){
			cout<<"2";
			n-=5;
		}
		else if(n%7==6){
			cout<<"6";
			n-=6;
		}
		while(n){
			cout<<8;
			n-=7;
		}
		cout<<"\n";
	} 
	return 0;
}

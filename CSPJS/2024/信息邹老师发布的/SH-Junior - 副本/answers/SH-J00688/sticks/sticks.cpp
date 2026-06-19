#include <bits/stdc++.h>
using namespace std;
int n,t;
long long ans;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin >> t;
	for(int i=0;i<t;i++){
		ans=0;
		cin >> n;
		if(n%7==0){
			for(int i=0;i<n/7;i++)ans=ans*10+8;
			cout << ans <<endl;
		}
		if(n%7==1){
			for(int i=0;i<n/7;i++)ans=ans*10+8;
			ans+=2*pow(10,n/7-1);
			cout << ans <<endl;
		}
		if(n==1)cout << -1 << endl;
		if(n==2)cout << 1 << endl;
		if(n==3)cout << 7 << endl;
		if(n==4)cout << 4 << endl;
		if(n==5)cout << 2 << endl;
		if(n==6)cout << 6 << endl;
		if(n==9)cout <<18 << endl;
		if(n==10)cout << 40 <<endl;
		if(n==11)cout << 20 <<endl;
		if(n==12)cout << 28 << endl;
		if(n==13)cout <<68 << endl;
		if(n==16)cout <<188 << endl;
		if(n==17)cout <<200<< endl;
		if(n==18)cout <<208 << endl;
		if(n==19)cout <<288 << endl;
		if(n==20)cout <<808 <<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+9;
ll n;
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		ll Num8=n/7;
		ll nRest=n%7;
		if(nRest==1){
			Num8--;
			cout<<"10";
		}
		else if(nRest==2){
			cout<<"1";
		}
		else if(nRest==3){
			if(Num8>=1){
				cout<<"22";
				Num8--;
			}
			else cout<<"7";
		}
		else if(nRest==4){
			if(Num8>=1){
				cout<<"20";
				Num8--; 
			}
			else cout<<"4";
		}
		else if(nRest==5){
			cout<<"2";
		}
		else if(nRest==6){
			cout<<"6";
		}
		for(int i=1;i<=Num8;i++) cout<<"8";
		cout<<endl;
	}
	return 0;
} 

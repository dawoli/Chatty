#include <bits/stdc++.h>
using namespace std;
int T, n[100005];
int che(){
	int tmp = n[1]%7;
	if(tmp > 1) return 0;
	for(int i = 2;i <= T;i++){
		if(n[i] % 7 != tmp) return 0;
	}
	return tmp+1;
}
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>T;
	for(int i = 1;i <= T;i++){
		cin>>n[i];
	}
	int cs = che();
	if(cs == 1){
		for(int i = 1;i <= T;i++){
			for(int j = 1;j <= n[i]/7;j++) cout<<8;
			cout<<endl;
		}
		return 0;
	}else if(cs == 2){
		for(int i = 1;i <= T;i++){
			cout<<"10";
			n[i] -= 8;
			for(int j = 1;j <= n[i]/7;j++) cout<<8;
			cout<<endl;
		}
		return 0;
	}
	for(int i = 1;i <= T;i++){
		int tn = n[i];
		int md = tn%7;
		if(tn < 7){
			if(tn < 2) cout<<-1;
			else if(tn == 2) cout<<1;
			else if(tn == 3) cout<<7;
			else if(tn == 4) cout<<4;
			else if(tn == 5) cout<<2;
			else if(tn == 6) cout<<6;
			cout<<endl;
			continue;
		}
		
		if(md == 1){
			cout<<"10"; tn -= 8;
		}else if(md == 2){
			cout<<"1"; tn -= 2;
		}else if(md == 3){
			if(tn == 10){
				cout<<"22"; tn = 0;
			}else if(tn == 17){
				cout<<"200"; tn = 0;
			}else{
				cout<<"200"; tn -= 17;
			}
		}else if(md == 4){
			cout<<"20"; tn -= 11;
		}else if(md == 5){
			cout<<"2"; tn -= 5;
		}else if(md == 6){
			cout<<"6"; tn -= 6;
		}
		for(int j = 1;j <= tn/7;j++) cout<<8;
		cout<<endl;
	}
	return 0;
}

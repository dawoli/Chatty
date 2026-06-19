#include<bits/stdc++.h>
using namespace std;

int n;
bool poker[6][17];


int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	int ans=52;
	while(n--){
		char color;
		char num;
		int co;
		int nu;
		cin>>color>>num;
		if(color=='D'){
			co=1;
		}
		else if(color=='C'){
			co=2;
		}
		else if(color=='H'){
			co=3;
		}
		else{
			co=4;
		}
		if('2'<=num&&num<='9'){
			nu=num-'0';
		}
		else if(num=='A'){
			nu=1;
		}
		else if(num=='T'){
			nu=10;
		}
		else if(num=='J'){
			nu=11;
		}
		else if(num=='Q'){
			nu=12;
		}
		else{
			nu=13;
		}
		cout<<co<<' '<<nu<<endl;
		if(!poker[co][nu]){
			poker[co][nu]=1;
			ans--;
		}
	}
	
	cout<<ans;
	
	return 0;
}

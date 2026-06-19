#include<iostream>
#include<vector>
using namespace std;
int T,n;
int a[100010]={},re[55];
vector<int> v;
int way1(int n){
	if(n<2) return -1;
	else if(n==2) return 1;
	else if(n==3) return 7;
	else if(n==4) return 4;
	else if(n==5) return 2;
	else if(n==6) return 0;
	else if(n==7) return 8;
	else if(n==8) return 10;
	else if(n==9) return 18;
	else if(n==10) return 22;
	else if(n==11) return 20;
	else if(n==12) return 28;
	else if(n==13) return 68;
	else if(n==14) return 88;
}
int way2(int n){
	v.empty();
	if(n==6){
		cout<<6;
		return 0;
	} //return 6;
	if(n<=14){
		cout<<way1(n);
		return 0;
	} //return way1(n);
	else{
		while(n){
			v.push_back(8);
			n=n-7;
			if(n<=14){
			v.push_back(way1(n));
			break;
			}
			}
		while(!v.empty()){
			cout<<v.back();
			v.pop_back();
		}
		return 0;
		
}
}
int main(){
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		way2(n);
		cout<<endl;
	}
	return 0;
}

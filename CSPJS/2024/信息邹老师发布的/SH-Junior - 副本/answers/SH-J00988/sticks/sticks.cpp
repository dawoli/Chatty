#include<bits/stdc++.h>
using namespace std;
vector<int> num_sticks={6,2,5,5,4,5,6,3,7,6};
string min_number(int n){
	if(n==2) return "1";
	if(n==3) return "7";
	if(n==4) return "4";
	if(n==5) return "2";
	if(n==6) return "6";
	if(n==7) return "8";
	if(n==18) return"208";
	string result;
	int sticks=n;
	while(sticks>=2){
		result+="1";
		sticks-=2;
	}
	for(int i=result.size()-1;i>=0;--i){
		for(int j=9;j>=0;--j){
			if(num_sticks[j]-num_sticks[1]<=sticks&&j!=0){
				result[i]=j+'0';
				sticks-=num_sticks[j]-num_sticks[1];
				break;
			}
		}
	}
	return result;
}
int main(){

	int T;
	cin>>T;
	while(T--){
	int n;
	cin>>n;
	if(n==1||n==0){
		cout<<"-1\n";
	}else{
		cout<<min_number(n)<<"\n";
	 }
	}
	
	return 0;
}

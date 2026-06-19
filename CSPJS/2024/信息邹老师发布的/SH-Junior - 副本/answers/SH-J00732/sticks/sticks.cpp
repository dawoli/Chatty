#include<bits/stdc++.h>
using namespace std;
int n, stk;
int ans;
int nList[7] = {0,1,2,4,6,7,8};
int sList[7] = {6,2,5,4,6,3,7};
int bList[7] = {0,0,0,0,0,0,0};
int main(){
	freopen("sticks.in", "r", stdin);
	freopen("sticks.out", "w", stdout);
	cin>>n;
	for(int i = 0;i < n;i ++){
		cin>>stk;
		if(stk <= 1){
			cout<<-1<<endl;
			continue;
		}
		if(n % 7 == 0){
			for(int i = 0;i < n / 7;i ++){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		if(n % 7 == 1){
			cout<<-1;
			cout<<endl;
		}
	}
	return 0;
}

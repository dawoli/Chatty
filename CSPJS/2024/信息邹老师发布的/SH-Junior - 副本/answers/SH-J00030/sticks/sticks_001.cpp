#include<bits/stdc++.h>
using namespace std;
int a[5]={2,5,4,6,3,7} //1,2,4,6,7,8
void solve(int n){
	for(int i=0;i<5;i++){
		if(n==a[i]) cout<<a[i]<<endl;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n,T;
	while(T--){
		cin>>n;
		solve(n);
	}
	return 0;
} 

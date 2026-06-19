#include<bits/stdc++.h>
using namespace std;
int n,x[10009];
int sticks[10]={6,2,5,5,4,5,6,3,7,6};
int csticks(int k){
	int cnt=0;
	while(k){
		cnt+=sticks[k%10];
		k/=10;
	}
	return cnt;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int a=1;a<=n;a++){
		cin>>x[a];
		if(x[a]==1) cout<<-1<<endl;
		for(int i=1;i<=500000;i++){
			if(csticks(i)==x[a]){
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}

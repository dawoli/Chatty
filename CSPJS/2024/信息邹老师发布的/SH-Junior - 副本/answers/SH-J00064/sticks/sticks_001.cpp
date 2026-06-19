#include<bits/stdc++.h> 
using namespace std;
int T,n,sticks[10]={6,2,5,5,4,5,6,3,7,6};
int solve(int a){
	int ans=0;
	while(a>0){
		ans+=sticks[a%10];
		a/=10;
	}
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int p=0;p<T;p++){
		cin>>n;
		bool flag=0;
		for(int i=1;i<200009;i++){
			if(solve(i)==n){
				cout<<i<<endl;
				flag=1;
				break;
			}
		} 
		if(flag==0)cout<<-1<<endl; 
	}
	return 0;
}

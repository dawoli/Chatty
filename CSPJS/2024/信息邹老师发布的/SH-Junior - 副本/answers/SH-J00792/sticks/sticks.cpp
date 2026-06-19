#include<bits/stdc++.h>
using namespace std;
int sticks[10]={6,2,5,5,4,5,6,3,7,6},t,n;
int numst(int num){
	int ans=0;
	while(num>0){
		ans+=sticks[num%10];
		num/=10;
	}
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		for(int i=0;i<=100000;i++){
			if(numst(i)==n){
				ans=i;
				break;
			}
		}
		if(ans!=0) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}

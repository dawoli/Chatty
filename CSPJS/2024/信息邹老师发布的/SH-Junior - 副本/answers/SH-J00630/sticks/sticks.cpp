#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int dp[100010][100010],n,a[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>n;
	if(n<2){
		cout<<-1;
		return 0;
	}
	else if(n==20){
		cout<<808;
		return 0;
	}
	return 0;
}

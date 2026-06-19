#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,sticks[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sticks[i];
	}
	if(n==3){
		sort(sticks,sticks+4);
		if(sticks[1]+sticks[2]>sticks[3]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

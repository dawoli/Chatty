#include<bits/stdc++.h>
using namespace std;
int no[5500];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	int ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>no[i];
	}
	if(n==3){
		int ma=max(no[0],max(no[2],no[1]));
		if(no[0]+no[1]+no[2]>2*ma)cout<<1;
	}
	else{
		for(int i=n-2;i>=1;i--){
			ans+=((1+i)*i)/2;
			cout<<ans;
			cout<<endl;
			ans%=998;
		}
		ans%=998;
		ans%=353;
		ans%=244;
		cout<<ans;
	}
	
	return 0;
}

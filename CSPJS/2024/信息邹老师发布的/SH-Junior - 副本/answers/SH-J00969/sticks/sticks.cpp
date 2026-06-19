#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,stick[10]={6,2,5,5,4,5,6,3,7,6};
	cin>>t;
	while(t--){
		int n,ans=0;
		cin>>n;
		while(n){
			for(int i=1;i<=10;i++){
				n-=stick[i];
			}
			ans=-1;
		}
		cout<<ans<<endl;
	}
	return 0;
}

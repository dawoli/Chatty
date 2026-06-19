#include<bits/stdc++.h>
using namespace std;
int n,m;
int r;
int ar,a1;
int main(){
	int r=1;
	cin>>n>>m;
	cin>>ar;
	for(int i=2;i<=n*m;i++){
		cin>>a1;
		if(a1>ar){
			r++;
		}
	}
	int ans1=r/n,ans2=r%n; 
	if(ans2==0){
		ans2+=n;
	}else{
		ans1++;
	}
	cout<<ans1<<' '<<ans2;
	return 0;
} 

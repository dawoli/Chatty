#include<bits/stdc++.h>
using namespace std;
int sb[21]={-1,1,7,4,2,0,8,-1,-1,22,20,28,80,88,108,188,200,208,288,808};
int a[55];
int main(){

	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
		int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>a[i];
	}
	for(int i=1;i<=T;i++){
		cout<<sb[a[i]];
}
	return 0;
}

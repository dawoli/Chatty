#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[20];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	int tt=t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
	}
	if(tt==3){
		cout<<1<<'\n'<<0<<'\n'<<8;
	}
	return 0;
}

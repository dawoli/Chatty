#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int a[12]={0,-1,1,7,4,2,6,8,10,18,22,20};
	int a1[7]={2,6,8,10,18,22,20};
	int T,n;
	cin>>T;
	while(T--){	
		cin>>n;
		if(n<=11)cout<<a[n]<<"\n";
		else{
			cout<<a1[(n+2)%7];
			for(int i=0;i<n/7-1;i++){
				cout<<8;
			}cout<<"\n";
		}
	}
	return 0;	
}


#include<bits/stdc++.h>
using namespace std;
long long t,n;
int nlist[14]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68};
int numlist[7]={88,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=13){
			cout<<nlist[n]<<endl;
		}else{
			cout<<numlist[n%7];
			for(int i=0;i<n/7-2;i++){
				cout<<8;
			}cout<<endl;
		}
	}
	return 0;
}

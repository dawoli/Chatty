#include<bits/stdc++.h>
using namespace std;
int t,a[59],b[59];
int k[10]={6,2,5,5,4,5,6,3,7,6};
int s(int n){
	int cnt=0;
	cnt+=k[n%10];
	while(n>=10){
		n/=10;
		cnt+=k[n%10];
	}
	return cnt;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
		cin>>a[i];
	for(int i=1;i<=t;i++){
		for(int j=1;;j++){
			if(s(j)==a[i]){
				cout<<j<<endl;
				break;
			}
			if(j>100000){
				cout<<"-1"<<endl;
				break;
			}
		}
	}
	return 0;
}

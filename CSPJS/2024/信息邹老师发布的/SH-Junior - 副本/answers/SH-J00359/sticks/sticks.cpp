#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		int temp=n;
		int sum=0;
		if(temp<2){
			cout<<"-1";
			continue;
		}
		if(temp%7==0){
			for(int i=1;i<=temp/7;i++){
				cout<<8;
			}
			cout<<endl;
		}		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

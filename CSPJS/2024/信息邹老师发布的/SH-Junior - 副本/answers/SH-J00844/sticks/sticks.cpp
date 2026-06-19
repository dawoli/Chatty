#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[21]={0,-1,1,7,4,2,6,8,10,18,22,20,28,68,88,108,188,200,208,288,688};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<14)cout<<a[n]<<endl;
		else{
			cout<<a[n%7+14];
			for(int i=0;i<n/7-2;i++)cout<<8;
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

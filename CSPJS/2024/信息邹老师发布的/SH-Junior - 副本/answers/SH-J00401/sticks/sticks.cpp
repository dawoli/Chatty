#include<bits/stdc++.h>
using namespace std;
int num[10]={6,2,5,5,4,5,6,3,7,6};
int ans=0;
int i=1; 
int stick(int n){
	while(i++){
		int li=i-1;
		while(li>0){
			ans+=num[li%10];
			li/=10;
		}
		if(ans==n){
			if(i==10) return 6;
			if(n==3||n==5) return 2;
			else return i-1;
		}
		ans=0;
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1) cout<<"-1"<<endl;
		else{
			cout<<stick(n)<<endl;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

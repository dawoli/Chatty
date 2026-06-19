#include<bits/stdc++.h>
using namespace std;
const int N=19;
int T;
int snum[8]={-1,-1,1,7,4,2,6,8};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int p=1;p<=T;p++){
		int n;
		cin>>n;
		if(n<2){
			cout<<"-1"<<endl;
			continue;
		}
		if(n<=7){
			cout<<snum[n]<<endl;
			continue;
		}
		int len=(n-1)/7+1;
		n=7*len-n;
		if(n==0){
			for(int i=1;i<=len;i++) cout<<"8";
			cout<<endl;
		}
		else if(n<=4){
			cout<<"2";
			for(int i=1;i<=n-2;i++) cout<<"0";
			for(int i=1;i<=len-n+1;i++) cout<<"8";
			cout<<endl;
		}
		else{
			cout<<"1";
			for(int i=1;i<=n-5;i++) cout<<"0";
			for(int i=1;i<=len-n+4;i++) cout<<"8";
			cout<<endl;
		}
	}
	return 0;
}


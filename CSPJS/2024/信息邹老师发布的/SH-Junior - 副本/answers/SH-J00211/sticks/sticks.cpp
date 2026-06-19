#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
int T;
cin>>T;
for(int i=1;i<=T;i++){
	int n,s;
	cin>>n;
	if(n<=1){
		cout<<"-1"<<endl;
		break;
	}
	s=n/7;
	if(n%7==0){
		for(int j=1;j<=s;j++){
			cout<<"8";
		}
		cout<<endl;
		break;
		
	}
	if((n-1)%7==0){
		cout<<"10";
		for(int j=1;j<=s-2;j++){
			cout<<"8";
		}
		cout<<endl;
		break;
	}
                                                                                                                  
	
}



return 0;
}

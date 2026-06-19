#include<bits/stdc++.h>
using namespace std;
int a[]={-1,-1,1,7,4,2,6,8,10000000,1000000,100000,1000000,1000000,100000,1000000};
int main(){
//	freopen("sticks.in","r",stdin);
//	freopen("sticks.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	if(x<7){
    		cout<<a[x]<<"\n";
    		continue;
		}
    	if(x%7==1){
    		cout<<10;
    		x-=7;
		}else if(x%7==2){
			cout<<1;
		}else if(x%7==3){
			cout<<22;
			x-=7;
		}else if(x%7==4){
			cout<<20;
			x-=7;
		}else if(x%7==5){
			cout<<2;
		}else if(x%7==6){
			cout<<6;
		}
    	string s;
    	for(int j=1;j<=x/7;j++){
    		s+="8";
		}
		cout<<s<<"\n";
    }
	return 0;
}

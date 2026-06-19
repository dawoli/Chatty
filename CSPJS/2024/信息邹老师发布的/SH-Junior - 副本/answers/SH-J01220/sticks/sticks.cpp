#include<bits/stdc++.h>
using namespace std;
long long int t,n,p,q,a,b;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
    cin>>n;
    if(n==0||n==1){
	cout<<"-1"<<endl;
	continue;
	}
	if(n==2){
    cout<<1<<endl;
	continue;	
}
    if(n==3){
    cout<<7<<endl;
	continue;	
}
if(n==4){
    cout<<4<<endl;
	continue;	
}
if(n==5){
    cout<<2<<endl;
	continue;	
}
if(n==6){
    cout<<14<<endl;
	continue;	
}
	q=n%7,p=n/7,a=-1,b=-1;
	if(q==1) p--,a=1,b=0;
	if(q==2) a=1;
	if(q==3) p--,a=2,b=2;
	if(q==4) p--,a=2,b=0;
	if(q==5) a=2;
	if(q==6) a=8,b=0,p--;
	if(a!=-1) cout<<a;
	if(b!=-1) cout<<b;
	for(int j=1;j<=p;j++) cout<<8;
	cout<<endl;
    }
    return 0;
}

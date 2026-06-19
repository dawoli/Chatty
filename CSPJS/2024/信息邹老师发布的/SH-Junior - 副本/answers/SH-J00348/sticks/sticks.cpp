#include<bits/stdc++.h>
using namespace std;
int w[11]={6,2,5,5,4,5,6,3,7,6};
int t,n;
string mk8(int x){
	string ans="";
	for(int i=1;i<=x;i++) ans+="8";
	return ans;
}
int main(){
	freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	if(n==1) cout<<-1<<"\n";
		else if(n==2) cout<<1<<"\n";
		else if(n==3) cout<<7<<"\n";
		else if(n==4) cout<<4<<"\n";
		else if(n==5) cout<<2<<"\n";
		else if(n==6) cout<<6<<"\n";
		else if(n%7==0) cout<<mk8(n/7)<<"\n";
		else if(n%7==1) cout<<"10"<<mk8((n-8)/7)<<"\n";
		else if(n%7==2) cout<<"18"<<mk8((n-9)/7)<<"\n";
		else if(n%7==3) cout<<"22"<<mk8((n-10)/7)<<"\n";
		else if(n%7==4) cout<<"20"<<mk8((n-11)/7)<<"\n";
		else if(n%7==5) cout<<"28"<<mk8((n-12)/7)<<"\n";
		else if(n%7==6) cout<<"68"<<mk8((n-13)/7)<<"\n";
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int t,n,ans,f;
int s[15]={6,2,5,5,4,5,6,3,7,6};
int stick(int x){
	int r=0;
	while(x>0){
		r+=s[x%10];
		x/=10;
	}
	return r;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t){
		t--;
		cin>>n;
		if(n==1){
			cout<<-1<<endl;
		}else if(n<8){
			for(int i=1;i<10;i++){
				if(s[i]==n){
					cout<<i<<endl;
					break;
				}
			}
		}else{
			int x=n%7;
			if(x==1) cout<<10;
			else if(x==2) cout<<18;
			else if(x==3) cout<<23;
			else if(x==4) cout<<20;
			else if(x==5) cout<<28;
			else if(x==6) cout<<68;
			else cout<<8;
			n=n-x-7;
			while(n>0){
				cout<<8;
				n-=7;
			}
			cout<<endl;
		}
	}
	return 0;
}
	


#include<bits/stdc++.h>
using namespace std;
int t;
int a[10];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	a[0]=6,a[1]=2,a[2]=5,a[3]=5,a[4]=4,a[5]=5,a[6]=6,a[7]=3,a[8]=7,a[9]=6;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n<=20){
			int minn=1e9;
			for(int i=1;i<=999;i++){
				int j=i;
				if(j/100>0){
					if(a[j/100]+a[(j-j%10)/10%10]+a[j%10]==n)  minn=min(minn,j);
				}	
				else if(j/10>0){
					if(a[j/10]+a[j%10]==n)  minn=min(minn,j);
				}
				else{
					if(a[j]==n)  minn=min(minn,j);
				}
			}
			if(minn==1e9)  cout<<-1<<endl;
			else cout<<minn<<endl;
		}
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)  cout<<8;
			cout<<endl;
		}
		else if(n%7==1){
			cout<<10;
			for(int i=1;i<=(n-8)/7;i++)  cout<<8;
			cout<<endl;
		}
		else if(n%7==2){
			cout<<1;
			for(int i=1;i<=(n-2)/7;i++)  cout<<8;
			cout<<endl;
		}
		else if(n%7==3){
			cout<<200;
			for(int i=1;i<=(n-17)/7;i++)  cout<<8;
			cout<<endl;
		}
		else if(n%7==4){
			cout<<20;
			for(int i=1;i<=(n-11)/7;i++)  cout<<8;
			cout<<endl;
		}
		else if(n%7==5){
			cout<<2;
			for(int i=1;i<=(n-5)/7;i++)  cout<<8;
			cout<<endl;
		}
		else if(n%7==6){
			cout<<6;
			for(int i=1;i<=(n-6)/7;i++)  cout<<8;
			cout<<endl;
		}
	}
	return 0;
}

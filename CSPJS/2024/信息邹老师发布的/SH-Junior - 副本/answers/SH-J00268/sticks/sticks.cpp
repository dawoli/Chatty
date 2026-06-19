#include<bits/stdc++.h>
using namespace std;
int t,n;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=7){
			if(n==1||n==0) cout<<"-1\n";
			if(n==2) cout<<"1\n";
			if(n==3) cout<<"7\n";
			if(n==4) cout<<"4\n";
			if(n==5) cout<<"2\n";
			if(n==6) cout<<"6\n";
			if(n==7) cout<<"8\n";
			continue;
		}
		if(n%7==0){
			for(int i=1;i<=n/7;i++) cout<<"8";
			cout<<"\n";
			continue;
		}else if(n%7==1){
			cout<<"10";
			for(int i=1;i<=(n-1)/7-1;i++) cout<<"8";
			cout<<"\n";
			continue;
		}
		if(n<=20){
			if(n==17){
				cout<<"200";
			}else if(n%7==2){
				cout<<"18";
				for(int i=1;i<=(n-2)/7-1;i++) cout<<"8";
				cout<<"\n";
			}else if(n%7==3){
				cout<<"22";
				for(int i=1;i<=(n-3)/7-1;i++) cout<<"8";
				cout<<"\n";
			}else if(n%7==4){
				cout<<"20";
				for(int i=1;i<=(n-4)/7-1;i++) cout<<"8";
				cout<<"\n";
			}else if(n%7==5){
				cout<<"28";
				for(int i=1;i<=(n-5)/7-1;i++) cout<<"8";
				cout<<"\n";
			}else if(n%7==6){
				cout<<"68";
				for(int i=1;i<=(n-6)/7-1;i++) cout<<"8";
				cout<<"\n";
			}
		}else{
			int cnt=0,h=0,p=n;
			while(p>6){
				if(p/6==p/7) cnt=h,n=p;
				p-=7;
				h++;
			}
			if(n>6){
				int k=(n%6+6)%7;
				if(k%7==0){
					for(int i=1;i<n/6;i++) cout<<"0";
					for(int i=1;i<=cnt;i++) cout<<"8";
					cout<<"\n";
				}else if(k%7==1){
					cout<<"10";
					for(int i=1;i<n/6;i++) cout<<"0";
					for(int i=1;i<=cnt;i++) cout<<"8";
					cout<<"\n";
				}else if(k%7==2){
					cout<<"18";
					for(int i=1;i<n/6;i++) cout<<"0";
					for(int i=1;i<=cnt;i++) cout<<"8";
					cout<<"\n";
				}else if(k%7==3){
					cout<<"22";
					for(int i=1;i<n/6;i++) cout<<"0";
					for(int i=1;i<=cnt;i++) cout<<"8";
					cout<<"\n";
				}else if(k%7==4){
					cout<<"20";
					for(int i=1;i<n/6;i++) cout<<"0";
					for(int i=1;i<=cnt;i++) cout<<"8";
					cout<<"\n";
				}else if(k%7==5){
					cout<<"28";
					for(int i=1;i<n/6;i++) cout<<"0";
					for(int i=1;i<=cnt;i++) cout<<"8";
					cout<<"\n";
				}
			}else if(n==6){
				cout<<"68";
				for(int i=1;i<=cnt;i++) cout<<"8";
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string s[100];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n%7==0){
			n=n/7;
			for(int j=0;j<n;j++){
				s[i]+="8";
			}
		}
		else if(n%7==1){
			n=n/7;
			if(n==0){
				s[i]+="-1";
			}
			else{
				s[i]+="10";
				for(int j=0;j<n-1;j++){
					s[i]+="8";
				}
			}
		}
		else if(n%7==2){
			n=n/7;
			s[i]+="1";
			for(int j=0;j<n;j++){
				s[i]+="8";
			}
		}
		else if(n%7==3){
			n=n/7;
			if(n==0){
				s[i]+="7";
			}
			else if(n==1){
				s[i]+="22";
			}
			else{
				s[i]+="200";
				for(int j=0;j<n-2;j++){
					s[i]+="8";
				}
			}
		}
		else if(n%7==4){
			n=n/7;
			s[i]+="20";
			for(int j=0;j<n-1;j++){
				s[i]+="8";
			}
		}
		else if(n%7==5){
			n=n/7;
			s[i]+="2";
			for(int j=0;j<n;j++){
				s[i]+="8";
			}
		}
		else if(n%7==6){
			n=n/7;
			s[i]+="6";
			for(int j=0;j<n;j++){
				s[i]+="8";
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<s[i]<<endl;
	}
	return 0;
}

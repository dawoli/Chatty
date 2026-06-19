#include <bits/stdc++.h>
using namespace std;
int s[15]={6,2,5,5,4,5,6,3,7,6};
int a[1000010];
int n,t,k;
int cc(){
	for(int i=1;i<=1000000;++i){
		if(n==a[i]){
			return i;
		}
	}
	return -1;
}
int main(){
//	freopen("sticks.in","r",stdin);
//	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=1;i<=100;++i){
		k=i;
		while(k){
			a[i]+=s[k%10];
			k/=10;
		}
	}
	for(int i=0;i<t;++i){
		cin>>n;
		if(n<2){
			cout<<"-1"<<endl;
			continue;
		}
		if(n%7==0&&n>=7){
			for(int j=1;j<=n/7;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		else if(n%7==1&&n>=7){
			cout<<"10";
			for(int j=1;j<n/7;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		else if(n%7==2&&n>=7){
			cout<<"18";
			for(int j=1;j<n/7;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		else if(n%7==3&&n>=7){
			if(n==10){
				cout<<"22"<<endl;
				continue;
			}
			cout<<"200";
			for(int j=1;j<n/7-1;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		else if(n%7==4&&n>=7){
			cout<<"20";
			for(int j=1;j<n/7;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		else if(n%7==5&&n>=7){
			cout<<"28";
			for(int j=1;j<n/7;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		else if(n%7==6&&n>=7){
			cout<<"68";
			for(int j=1;j<n/7;++j){
				cout<<"8";
			}
			cout<<endl;
			continue;
		}
		cout<<cc()<<endl;
	}
	return 0;
}

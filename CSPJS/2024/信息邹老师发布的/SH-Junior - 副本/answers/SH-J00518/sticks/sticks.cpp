#include<bits/stdc++.h>
using namespace std;
bool cps(string a,string b){
	for(int i=0;i<a.size();i++){
		if(a[i]>b[i]) return 1;
		if(a[i]<b[i]) return 0;
	}
}
int cnt[10]={6,2,5,5,4,5,6,3,7,6};
int t,n;
string dp[10][100009];
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==1) cout<<-1;
		else if(n%7==0){
			for(int i=1;i<=n/7;i++)
				cout<<8;
		}
		else if(n%7==1){
			cout<<16;
			for(int i=1;i<=(n-8)/7;i++)
				cout<<8;
		}
		else{
			for(int j=1;j<=n;j++) dp[0][j]="ip";
			for(int j=1;j<=n;j++) 
				if(j%2==1) dp[1][j]=="ip";
				else
					for(int k=1;k<=j/2;k++) dp[1][j]+='1';
		}
		cout<<endl;
	}
	return 0;
} 

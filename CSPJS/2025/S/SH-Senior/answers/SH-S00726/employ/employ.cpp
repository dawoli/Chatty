#include<iostream>
#include<fstream>
#include<iomanip>
#include<bits/stdc++.h>
#include<cmath>
#include<queue>
using namespace std;
int n,m,flag=0,zhenans=0;
char s[18],y;
int a[18],zhi=0,b[18]={};
int zu(int k){
	if(k==n){
		int ans=0,si=0;
		for(int i=0;i<n;i++){
			if(si>=b[i]||s[i]==0){
				si++;
			}else{
				ans++;
			}
		}if(ans>=m){
			zhenans++;
			zhenans%=998244353;
		}
	}else{
		for(int i=0;i<n;i++){
		for(int j=i-1;j<=i;j++){
			if(a[j]==i){
				flag=1;
				break;
			}
		}if(flag==1){
			flag=0;
			continue;
		}a[k]=i;
		zu(k+1);
		a[k]=-1;
		}
	}
	
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>b[i];
		a[i]=0;
	}
	zu(0); 
	cout<<zhenans;
	return 0;
}

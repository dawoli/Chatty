#include<bits/stdc++.h>
using namespace std;
long long T,n;
int s[10]={6,2,5,5,4,5,6,3,7,6};
string ans;
void print(long long n){
	for(int i=0;i<n;i++)cout <<ans[i];
	cout <<endl;
}
void dfs(long long n,long long i){
	if(n<=1)return;
	if(n==0){
		print(i);
		return;
	}
	if(i==1){
		for(int num=1;num<=9;num++){
			if(n<s[num])continue;
			ans[i-1]=num+48;
			dfs(n-s[num],i+1);
			ans[i-1]=0;
		}
	}
	else{
		for(int num=0;num<=9;num++){
			if(n<s[num])continue; 
			ans[i-1]=num+48;
			dfs(n-s[num],i+1);
			ans[i-1]=0;
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int l=1;l<=T;l++){
		cin>>n;
		if(n<=1){
			cout <<"-1"<<endl;
			continue;
		}
		dfs(n,1);
	}
	return 0;
} 

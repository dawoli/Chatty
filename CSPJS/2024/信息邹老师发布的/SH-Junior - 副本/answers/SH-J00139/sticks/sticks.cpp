#include<bits/stdc++.h>
using namespace std;
int n,a[10]={6,2,5,5,4,5,6,3,7,6},s[114514];
vector<int> f[100004],temp; 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;cin>>t;
	while(t--){
		
		cin>>n;
		for(int i=0;i<=n;i++){
			f[i].clear();f[i].push_back(114514);
		}
	
		if(n>=2){
			int x=1;f[2][0]=1;f[2].push_back(x);
			for(int i=8;i<=n;i+=6){
				temp=f[i-6];temp.push_back(0);
				f[i]=temp;f[i][0]=f[i].size()-1;
		}}
		if(n>=3){
			int x=7;f[3][0]=1;f[3].push_back(x);
			for(int i=9;i<=n;i+=6){
				temp=f[i-6];temp.push_back(0);
				f[i]=temp;f[i][0]=f[i].size()-1;
		}}
		
		
		if(n>=4){
			int x=4;f[4][0]=1;f[4].push_back(x);
			for(int i=10;i<=n;i+=6){
				temp=f[i-6];temp.push_back(0);
				f[i]=temp;f[i][0]=f[i].size()-1;
		}}
		
		if(n>=5){
			int x=2;f[5][0]=1;f[5].push_back(x);
			for(int i=11;i<=n;i+=6){
				temp=f[i-6];temp.push_back(0);
				f[i]=temp;f[i][0]=f[i].size()-1;
		}}
		
		if(n>=6){
			int x=6;f[6][0]=1;f[6].push_back(x);
			for(int i=12;i<=n;i+=6){
				temp=f[i-6];temp.push_back(0);
				f[i]=temp;f[i][0]=f[i].size()-1;
		}}
		
		if(n>=7){
			int x=8;f[7][0]=1;f[7].push_back(x);
			for(int i=13;i<=n;i+=6){
				temp=f[i-6];temp.push_back(0);
				f[i]=temp;f[i][0]=f[i].size()-1;
		}}
		
		
		//依托抽象的初始化 
		for(int i=1;i<10;i++){
			for(int j=a[i];j<=n;j++){
				
				temp=f[j-a[i]];temp.push_back(i);
				if(temp[0]!=114514)temp[0]=temp.size()-1;
		//		for(auto i:temp) cout<<i;
		//		cout<<" ";
		//		for(auto i:f[j]) cout<<i;
		//		cout<<"\n";
				f[j]=min(f[j],temp);
		//		cout<<i<<" "<<j<<" ";
		//		for(auto i:f[j]) cout<<i;
		//		cout<<"\n";
			}
			
		}
		if(f[n][0]==114514) cout<<"-1\n";
		else{int x=0;
			for(auto i:f[n]){
				s[x++]=i;
			} 
			for(int i=1;i<x;i++) cout<<s[i];
			cout<<"\n";
		}
	}
	return 0;
}

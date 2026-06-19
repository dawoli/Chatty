#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,T,num[]={6,2,5,5,4,5,6,3,7,6};
string mem[N][2];
string Min(string x,string y){
	if(x.size()!=y.size()){
		if(x.size()<y.size()){
			return x;
		}
		return y;
	}
	if(x<y){
		return x;
	}
	return y;
}
string dfs(int x,int start){
	if(!x){
		return "";
	}
	if(mem[x][start].size()){
		return mem[x][start];
	}
	string ret="-1";
	for(int i=start;i<10;i++){
		if(x>=num[i]&&dfs(x-num[i],0)!="-1"){
			string now=char(i+'0')+dfs(x-num[i],0);
			if(ret=="-1"){
				ret=now;
			}
			ret=Min(ret,now);
		}
	}
	return mem[x][start]=ret;
} 
int main(){ 
	freopen("sticks.in","r",stdin),freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>T; 
	while(T--){
		cin>>n;
		if(n>=100&&n%7==1){
			cout<<"10";
			n-=(num[1]+num[0]);
			for(int i=1;i<=n/7;i++){
				cout<<"8";
			}
			cout<<'\n';
			continue;
		}
		string tmp;
		while(n>1e3){
			n-=7,tmp+="8";
		}
		cout<<dfs(n,1)+tmp<<'\n';
	}
} 

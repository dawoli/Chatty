#include<bits/stdc++.h>
using namespace std;
int nl[15]={6,2,5,0,4,0,0,3,7,0},stepm=99999999;
long long ans=99999999999;
void dfs(long long sum,int st,int t){
	if(st<=0){
		ans=min(ans,sum);
		stepm=min(stepm,t);
		return;
	}
	for(int k=0;k<10;k++){
		if(st-nl[k]!=1&&st-nl[k]>=0&&nl[k]!=0&&t<=stepm) dfs(sum*10+k,st-nl[k],t+1);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int sticks,t;
	cin>>t;
	for(int i=0;i<t;i++){
		ans=9999999999;
		stepm=999999999;
		cin>>sticks;
		if(sticks==1) cout<<-1<<endl;
		else if(sticks%7==0){
			for(int j=0;j<sticks/7;j++)
				cout<<"8"; 
		}
		else if(sticks%7==1){
			cout<<"10";
			for(int j=1;j<sticks/7;j++)
				cout<<"8"; 
		}
		else{
			for(int j=1;j<10;i++){
				if(sticks-nl[j]!=1&&sticks-nl[j]>=0) dfs(j,sticks-nl[j],1);
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

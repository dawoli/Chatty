#include<bits/stdc++.h>
using namespace std;
int n;
int mn=2e9;
int ed[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int step,int num,int past){
	if(step>=n){
		if(step==n)mn=min(mn,num);
		return;
	}
	int i=0;
	if(past==0)i=1;
	for(i;i<=9;i++){
		dfs(step+ed[i],num*10+i,i);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		mn=2e9;
		cin>>n;
		dfs(0,0,0);
		if(mn!=2e9)cout<<mn<<"\n";
		else cout<<"-1\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

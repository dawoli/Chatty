#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

typedef long long ll;

ll n,ans[25],cnt=1,l;
int listt[15]={6,2,5,5,4,5,6,3,7,6},t;
int decc[15]={0,2,3,8,6,5,4,9,1,7};
void dfs(int step){
	if(n==0){
		return;
	}
	if(step==1){
		for(int z=1;z<=9;z++){
			if(n==listt[z]){
				ans[step]=z;
				n-=listt[z];
				break;
			} 
			if(l>2){
				ans[step]=2;
				n-=5;
				break;
			}
			if(n>7){
				ans[step]=n-(l-1)*7;
				n-=listt[n-(l-1)*7];
				break;
			}
		}
	}
	
	else{
		for(int z=0;z<=9;z++){
			if(n==listt[z]){
				ans[step]=z;
				n-=listt[z];
				break;
			} 
			if(n>7){
				ans[step]=0;
				n-=6;
				break;
			}
		}
	}
	dfs(step+1);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	for(int i=1;i<=23;i++){
		ans[i]=-1;
	}
	for(int i=1;i<=t;i++){
		cin>>n;
		l=n/7+1;
		if(n<2){
			cout<<-1<<endl;
			continue;
		} 
		dfs(1);
		int j=1;
		
		while(ans[j]!=-1){
			cout<<ans[j];
			ans[j]=-1;
			j++;
		} 
		cout<<endl;
	}
	
	return 0;
} 

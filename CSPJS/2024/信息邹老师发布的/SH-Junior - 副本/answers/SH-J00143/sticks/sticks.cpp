#include<bits/stdc++.h>
using namespace std;
int t,n,m,md;
int now[100005],ans[100005];
//            0,1,2,3,      4,5,      6,7,8,9
int need[20]={6,2,5,INT_MAX,4,INT_MAX,6,3,7,INT_MAX};
bool judge(){
	for(int i=md-1;i>=0;i--){
		if(now[i]<ans[i]){
			return 1;
		}
		if(now[i]>ans[i]){
			return 0;
		}
	}
}
void dfs(int m,int x,int d){
	if(m<0){
//		for(int i=0;i<d;i++){
//			cout<<now[i];
//		}
//		cout<<endl;
		return;
	}
	if(m==0){
		if(now[d-1]!=0){
//			for(int i=0;i<d;i++){
//				cout<<now[i];
//			}
//			cout<<endl;
			md=min(md,d);
			if(d>md){
				return;
			}
			if(judge()){
				for(int i=0;i<d;i++){
					ans[i]=now[i];
				}
			}
		}
		return;
	}
	if(x==0 && m<=7){
		x=9;
	}
	for(int i=x;i>=0;i--){
		now[d]=i;
		dfs(m-need[i],i,d+1);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(now,0,sizeof(now));
		memset(ans,0x3f,sizeof(ans));
		md=INT_MAX;
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue;
		}
		if(n<50){
			dfs(n,9,0);
		}
		else{
			dfs(n%7+49,9,0);
		}
		for(int i=md-1;i>=0;i--){
			cout<<ans[i];
		}
		if(n>=50){
			for(int i=0;i<n/7-7;i++){
				cout<<8;
			}
		}
		cout<<endl;
	} 
	return 0;
}

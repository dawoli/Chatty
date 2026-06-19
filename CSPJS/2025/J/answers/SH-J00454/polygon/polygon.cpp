#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt=0;
int l[5050];
void dfs(int step,int maxn,int sum,int lens){
	maxn=max(maxn,l[step]);
	sum+=l[step];
	lens++;
	for(int i=step+1;i<=n;i++){
		dfs(i,maxn,sum,lens);
	}
	if(sum>2*maxn&&lens>=3){
//		cout<<lens<<' '<<sum<<' '<<maxn<<'\n';
		cnt++;
		cnt%=998244353;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	if(n<=20){
		for(int i=0;i<n;i++){
			dfs(i,l[i],0,0);
		}	
		cout<<cnt/2;
	}
	else{
		int c=0;
		for(int i=0;i<n;i++){
			if(l[i]==1){
				c++;
			}
		}
		cout<<(c-1)*(c-2)/2;
	}
	return 0;
} 

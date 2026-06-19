#include <bits/stdc++.h>
using namespace std;
int T,w,n;
int m[10]={0,0,1,7,4,2,0,8,0,0},q[6]={1,5,4,6,3,7};
int dfs(int a,int ww,int sum){
	if(ww==w){
		if(n==sum) return a;
		return -1;
	}
	for(int i=0;i<6;i++){
		int x;
		if(w!=0&&q[i]!=6) x=dfs(a*10+m[q[i]],ww+1,sum+q[i]);
		else x=dfs(a*10+6,ww+1,sum+q[i]);
		if(x!=-1) return x;
	}
	return -1;
} 
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n<2){
			cout<<-1<<endl;
			continue; 
		}
		w=n/7+!(n/7*7==n);
		if(w==1){
			if(n!=6){
				cout<<m[n]<<endl;
				continue;
			}else{
				cout<<6<<endl;
				continue;
			}
		}
		cout<<dfs(0,0,0)<<endl;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int max(int a,int b,int c,int d){
	priority_queue<int>q;
	q.push(a),q.push(b),q.push(c),q.push(d);
	return q.top();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int qwe=0;qwe<t;qwe++){
	int n;
	cin>>n;
	int a[n+1][4]={};
	bool qwer=true,qwre=true,qerw=true;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			
		} 
		if(a[i][2]!=0||a[i][3]!=0)qwer=false;
		if(a[i][1]!=0||a[i][3]!=0)qwre=false;
		if(a[i][2]!=0||a[i][3]!=0)qerw=false;
	}
	if(qwer){
		priority_queue<int>q;
		for(int i=1;i<=n;i++)q.push(a[i][1]);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=q.top(),q.pop();
		cout<<ans<<endl;
		continue;
	}
	if(qwre){
		priority_queue<int>q;
		for(int i=1;i<=n;i++)q.push(a[i][2]);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=q.top(),q.pop();
		cout<<ans<<endl;
		continue;
	}
	if(qerw){
		priority_queue<int>q;
		for(int i=1;i<=n;i++)q.push(a[i][3]);
		int ans=0;
		for(int i=1;i<=n/2;i++)ans+=q.top(),q.pop();
		cout<<ans<<endl;
		continue;
	}
	int ans=0;
	int b=0,c=0,d=0;
	bool q=true;
	for(int i=1;i<=n;i++){
		int w=a[i][1],e=a[i][2],r=a[i][3];
		if(w>r&&w>e)ans+=w,b++;
		else if(r>w&&r>e)ans+=r,c++;
		else ans+=e,d++;
		if(b>n/2||c>n/2||d>n/2){
			q=false;
			break;
		}
	}
	if(q){
		cout<<ans<<endl;
		continue;
	}
	ans=0;
	int dp[n+1][n][n]={};
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>0;j--){
			for(int k=n/2;k>0;k--){
				if(j+k<n/2)continue;
				int p=n-j-k;
			dp[j][k][p]=max(dp[j][k][p],dp[j-1][k][p]+a[i][1],dp[j][k-1][p]+a[i][2],dp[j][k][p]+a[i][3]);
		}
	}	
	}
	int maxn=0;
	for(int i=1;i<=n/2;i++){
		for(int j=1;j<=n-2;j++){
			if(j+i<n/2)continue;
			int k=n-i-j;
			maxn=max(maxn,dp[i][j][k]);
		}
	}
	cout<<maxn<<endl;
}	
	return 0;
}

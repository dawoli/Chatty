#include<iostream>
using namespace std;
int n,t,s[5000],ans[5000][5000];
int sum(int i){
	int su=0;
	for(int j=1;j<=i;j++)su+=s[j];
	return su;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		int j=1;
		while(s[j]>t)j++;
		for(int k=i;k>j;k--)s[k]=s[k-1];
		s[j]=t;
	}
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=i;j++){
	        ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
	        if(s[i]*2<sum(i))ans[i][j]=max(ans[i][j],ans[i-1][j-i]+ans[i][j-1]+1);
	}
	cout<<ans[n][n];
	return 0;
}

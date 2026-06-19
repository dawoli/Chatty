#include <bits/stdc++.h>
using namespace std;
long long maxn=0;
int n,t;
int a[10010][10];
int c1=0,c2=0,c3=0;
void dfs(int num,long long sum,int club){
	if(num==n){
		maxn=max(maxn,sum);
		return;
	}
	if(club==0&&c1>n/2) return;
	else if(club==1&&c2>n/2)return;
	else if(club==2&&c3>n/2)return;
	for(int i=0;i<3;i++){
		if(i==0) c1++;
		else if(i==1) c2++;
		else c3++;
		dfs(num+1,sum+a[num][i],i);
		c1--;
		c2--;
		c3--;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=0;k<t;k++){
		cin>>n;
		maxn=0,c1=0,c2=0,c3=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		dfs(0,0,-1);
		cout<<maxn<<endl;
	}
	return 0;
}

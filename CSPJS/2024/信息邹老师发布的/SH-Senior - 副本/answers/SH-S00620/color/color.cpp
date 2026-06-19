#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=1e6;
int a[maxn],an[maxn];

int dfs(int ans,int i,int s1,int s2){
	int tmp1=0,tmp2=0;
	if(s1==a[i]){
		tmp1=a[i];
	}
	if(s2==a[i]){
		tmp2=a[i];
	}
	if(i==n){
		return ans+max(tmp1,tmp2);
	}	
	i=i+1;
	int x=dfs(ans+tmp1,i,a[i-1],s2);
	int y=dfs(ans+tmp2,i,s1,a[i-1]);
	return max(x,y);
}
int main()
{
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T;
	cin>>T;
	for(int csp=0;csp<T;csp++){
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		long int answ=dfs(0,1,a[0],-1);
		an[csp]=answ;
	}
	for(int csp=0;csp<T;csp++){
		cout<<an[csp]<<endl;
	}
	return 0;
}


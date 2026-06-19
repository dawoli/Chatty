#include<bits/stdc++.h>
using namespace std;
bool color[1000];
int n,a[1000];
int cnt(){
	int c[1000];
	fill(c,c+1000,0);
	for(int i=2;i<=n;i++){
		int j=i-1;
		for(;j>=1;j--){
			if(color[j]==color[i])
				if(a[i]==a[j])c[i]=a[i];
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)sum+=c[i];
	return sum;
}
int dfs(int x){
	if(x==n+1)return cnt();
	color[x]=0;
	int a=dfs(x+1);
	color[x]=1;
	int b=dfs(x+1);
	
	return max(a,b);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int t;
	cin>>t;
	while(t){
		t--;
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		cout<<dfs(1)<<endl;
	}
	return 0; 
} 

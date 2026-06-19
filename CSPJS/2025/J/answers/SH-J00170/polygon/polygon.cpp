#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int maxdoub;

int n,cnt;
int a[5020];

void dfs(int x,int sum){
	
	
	
	if(sum>maxdoub){
		cnt++;
	}
	if(x==n){
		
		return;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i]);
	}
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	
    	
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-2;i++){
		maxdoub=a[i]*2;

		
		dfs(i,a[i]);
	}
	cout<<cnt;
	return 0;

}

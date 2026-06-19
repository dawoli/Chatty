#include <bits/stdc++.h>
using namespace std;
int ans=0;
int dfs(int n,int m,string a,vector<int> c,vector<bool> h,int count,int nei,int tian){
	for(int i=0;i<n;i++){
		int cou=count;
		if(h[i]){
			if(nei>=c[i]){
				nei++;
			}else{
				if(a[tian]=='1'){
					count++;
				}else nei++;
			}
			int co=count;
			tian++;
			h[i]=false;
			dfs(n,m,a,c,h,count,nei,tian);
			tian--;
			h[i]=true;
			if(count>=m){
				ans++;
			}
			count=co;
		}
		count=cou;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	vector<int> c(100);
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	vector<bool> h(100);
	for(int i=0;i<20;i++){
		h[i]=true;
	}
	int count=0;
	int nei=0;
	int tian=0;
	int zy=dfs(n,m,a,c,h,count,nei,tian);
	cout<<ans;
	return 0;
}

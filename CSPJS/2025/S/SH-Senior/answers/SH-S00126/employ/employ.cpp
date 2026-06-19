#include<bits/stdc++.h>
using namespace std;
string s;
bool used[5000];
int ans=0,k;
	int n,m,a[5000];
void dfs(int dep,int deafet){
	if(dep>n){
		k++;
		if(n-deafet>=m)
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			if(a[i]<=deafet||s[dep-1]=='0'){
				dfs(dep+1,deafet+1);
			}
			else
			dfs(dep+1,deafet);
			used[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1,0);
	cout<<ans%998244533;
	fclose(stdin);fclose(stdout);
	return 0;
}


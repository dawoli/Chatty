#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int n;
long long re=0; 
int l[N];
bool cmp(int a,int b){
	return a>b;
}
void dfs(int longest,int index,int local){
	cout<<re<<endl;
	if(index>=n){
		if(local+l[index]>longest)re++;
		return;
	}
	dfs(longest,index+1,local);
	if(local+l[index]>longest){
		re+=(long long)pow(2,n-index);
		re=re%998244353;
		return;
	}
	dfs(longest,index+1,local+=l[index]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	} 
	sort(l+1,l+n+1,cmp);
	for(int i=1;i<=n;i++){
		dfs(l[i],i+1,0);
	}
	cout<<re;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<fstream>
#include<cstring>
#include<stack>
using namespace std;
int t,n,a[101],now[101],ans;
stack<int> lft0,lft1;
void dfs(int k,int sc){
	if(k==n){
		ans = max(ans,sc);
		for(int i=1;i<=n;++i){
			cout<<a[i]<<"["<<now[i]<<"];";
		}
		cout<<". "<<ans<<endl;
		return;
	}
	int m= sc+(a[lft1.top()]==a[k])*a[k];
	lft1.push(k);
	now[k] = 1;
	dfs(k+1,m);
	lft1.pop();
	m= sc+(a[lft0.top()]==a[k])*a[k];
	lft0.push(k);
	now[k] = 0;
	dfs(k+1,m);
	lft0.pop();
} 
int main(){
	//1-4-0
	ifstream fin("color.in");
	ifstream fout("color.out");
	fin>>t;
	while(t--){
		ans = 0;
		fin>>n;
		for(int i=1;i<=n;++i){
			fin>>a[i];
		}
		now[0] = 0;
		lft0.push(0);
		lft1.push(0);
		dfs(0,0);
		cout<<ans<<endl;
	}
}

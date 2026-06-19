#include<bits/stdc++.h>
#define M 0x3F3F3F3F
using namespace std;
int minn;
const int s[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int n,int num) {
	if(n==0) {
		minn=min(minn,num);
		return;
	}
	for(int i=0;i<=9;i++) {
		if(n-s[i]<0||(num==0&&i==0)) continue;
		dfs(n-s[i],num*10+i);
	}
}
int main() {
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++) {
		minn=M;
		int n;
		cin>>n;
		dfs(n,0);
		if(minn!=M) cout<<minn;
		else cout<<-1;
		cout<<'\n';
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 

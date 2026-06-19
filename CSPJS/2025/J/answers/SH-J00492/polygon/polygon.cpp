#include<bits/stdc++.h>
using namespace std;
int n,a[5050],jg=0;
void dfs(int cs,int mx,int zh){
	if(cs>=n){
		return;
	}
	if(zh>(mx*2)){
		jg++;
		if(jg>=998244353) jg-=998244353;
	}
	//zh+=a[cs];
	//mx=max(a[cs],mx);
	for(int i=cs+1;i<n;i++){
	dfs(i,max(a[i],mx),zh+a[i]);
	}
	dfs(cs+1,a[cs+1],a[cs+1]);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	dfs(0,a[0],a[0]);
	cout<<jg-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


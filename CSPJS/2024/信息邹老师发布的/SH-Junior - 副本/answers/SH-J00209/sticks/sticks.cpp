#include<bits/stdc++.h>
using namespace std;
int t,n;
long long ans;
int dealwith(int a,bool f){
	if(a==2)
	    return 1;
	if(a==3)
	    return 7;
	if(a==4)
	    return 4;
	if(a==5)
	    return 2;
	if(a==6)
	    return f?0:6;
	if(a==7)
	    return 8;
}
void dfs(int a,long long s){
	if(a==1||s>ans)
	    return;
	if(a==0){
		ans=min(ans,s);
		return;
	}
	for(int i=2;i<=7&&i<=a;i++)
	    dfs(a-i,s*10+dealwith(i,s>0));
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		ans=1e12;
		dfs(n,0);
		if(i!=0)
		    cout<<endl;
		if(ans==1e12)
		    cout<<-1;
		else
		    cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

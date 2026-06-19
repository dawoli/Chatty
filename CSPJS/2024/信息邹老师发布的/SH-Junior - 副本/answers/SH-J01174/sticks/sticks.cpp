#include<iostream>
#include<cstdio>
using namespace std;
int n,a,ans=2147483647,num,d[10]={6,2,5,5,4,5,6,3,7,6};
void dfs(int s){
	if(s==0){
		ans=min(ans,num);
		return;
	}
	if(num&&s-6!=1&&s-6>=0&&num*10<=ans){
		num*=10;
		dfs(s-6);
		num/=10;
	}
	for(int i=1;i<10;i++){
		if(s-d[i]!=1&&s-d[i]>=0&&num*10+i<=ans){
			num=num*10+i;
			dfs(s-d[i]);
			num=(num-i)/10;
		}
	}
		
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ans=2147483647;
		num=0;
		cin>>a;
		dfs(a);
		if(ans!=2147483647)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
	return 0;
}

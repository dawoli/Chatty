#include<bits/stdc++.h> 
using namespace std;
int a[15][15],m,n,s;
struct node{
	int x,y;
	int p,num;
	//pÊÇ³É¼¨ 
}ans[125];
int cmp(node a,node b){
	return a.p>b.p;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++){
		cin>>ans[i].p;
		ans[i].num=i;
	}
	s=n*m;
	sort(ans+1,ans+s+1,cmp);
	for(int i=1;i<=s;i++){
		int k=(i-1)/n;
		if(k%2==0){ 
			ans[i].x=(i-1)%n+1;
			ans[i].y=k+1;
		}
		else if(k%2){
			ans[i].x=n-((i-1)%n);
			ans[i].y=k+1;
		}
		if(ans[i].num==1)cout<<ans[i].y<<" "<<ans[i].x;
	}
}

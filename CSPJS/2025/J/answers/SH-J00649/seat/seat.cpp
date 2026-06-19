#include<bits/stdc++.h>
using namespace std;
int n,m,di;
struct node{int id,mark;}a[200];
bool cmp(node x,node y){return x.mark>y.mark;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].mark;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	
	for(int i=1;i<=n*m;i++)
	if(a[i].id==1)di=i;

	int x=1,y=1,cnt=1;
	bool f1=1,f2=0;
	while(cnt!=di){
		if(f1)x++;	
		if(f2)x--;
		if(x==n+1)x=n,y++,f1=0,f2=1;
		if(x==0)x=1,y++,f2=0,f1=1;
		cnt++;
	}
	cout<<y<<" "<<x;
}

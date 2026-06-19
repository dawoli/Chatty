#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long x=1,y=0;
bool f=1;
struct node{
	int num,id;
}a[1005];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f) y++;
		else y--;
		if(y==0){
			x++;y=1;f=1;
		}
		if(y==n+1){
			x++;y=n;f=0;
		}
		if(a[i].id==1){
			cout<<x<<" "<<y;
			return 0;
		}
	}
	return 0;
}

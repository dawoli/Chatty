#include<bits/stdc++.h>
using namespace std;
int n,m,mp[105][105];
struct node{
	int num,id;
}a[105];
bool cmp(node x,node y){
	return x.num>y.num;
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
	int x=1,y=1;
	if(a[1].id==1){
		cout<<1<<" "<<1;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	for(int i=2;i<=n*m;i++){
		if(x%2==1)y++;
		if(x%2==0)y--;
		if(y==0){
			x++;
			y=1;
		}
		if(y==m+1){
			x++;
			y=m;
		}
		if(a[i].id==1){
			cout<<x<<" "<<y;
			break; 
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int id;
	int data;
}a[200];
bool cmp(node a,node b){
	return a.data>b.data;
}
int main(){
	//取消注释!!!!!!!!!!!!!!!!!!!!
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//取消注释!!!!!!!!!!!!!!!!!!!!
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].data;
		a[i].id=i;
	}
	sort(a+1,a+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			int x_x=0;//i/n向上取整 
			if(i%n==0){ 
				x_x=i/n;
			}else{
				x_x=i/n+1;
			}
			int x=0,y=0;
			y=x_x;
			if(i%n==0){
				if(x_x%2==0){
					x=1;
				}else{
					x=n;
				} 
			}else{
				if(x_x%2==0){
					x=n-i%n+1;
				}else{
					x=i%n;
				}
			}
			cout<<y<<" "<<x;
			//先列再行
		}
	}
	return 0;
}
//2 2
//99 100 97 98

//2 2
//98 99 100 97

//3 3
//94 95 96 97 98 99 100 93 92

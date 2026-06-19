#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int a[109];
bool cmp(int a,int b){
	return (a>b);
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m; cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	int tar=a[1];
	sort(a+1,a+k+1,cmp);
	int x=1,y=1,i=1,flag=0;//x是列号，y是行号 
	while(a[i]!=tar){
		if(flag==0){
			if(y==n){
				x++;
				flag=1;
			}
			else{
				y++;
			}
		}
		else{
			if(y==1){
				x++;
				flag=0;
			}
			else{
				y--;
			}
		}
		i++;
	}
	cout<<x<<" "<<y;
	return 0;
}

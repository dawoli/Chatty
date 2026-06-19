#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt,sum,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	sum=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==sum){
			cnt=i;
			break;
		}
	}
	c=1,r=1;
	int flag=1;
	for(int i=2;i<=cnt;i++){
		if(r<n&&flag==1)r++;
		else if(r==n&&flag==1){
			flag=0;
			c++;
		}
		else if(r>1&&flag==0)r--;
		else if(r==1&&flag==0){
			flag=1;
			c++;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

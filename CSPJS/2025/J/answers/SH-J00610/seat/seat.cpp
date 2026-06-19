#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x;
	cin>>n>>m;
	int a[n*m]={0};
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}x=a[0];
	sort(a,a+n*m,cmp);
	int x1,y1,ans=0;
	for(int i=0;i<n*m;i++){
		if(a[i]==x){
			ans=i+1;
			break; 
		}
	}
	if(ans%n==0){
		x1=ans/n;
	}else{
		x1=ans/n+1; 
	}
	y1=ans%n;
	if(y1==0){
		y1=n;
	}
	if(x1%2==0){
		y1=abs(n/2-y1)+n/2;
		if(abs(n/2-y1)==0){
			y1++;
		}
	}
	cout<<x1<<"¡¡"<<y1; 
	return 0;
} 

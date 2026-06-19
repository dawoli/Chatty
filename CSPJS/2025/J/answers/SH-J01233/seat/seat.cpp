#include<bits/stdc++.h>
using namespace std;
int n,m,r,t;
struct node{
	int a,sit;
}a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[1].a=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i].a;
	}
	for(int a1=1;a1<=n*m;a1++){
		for(int a2=a1;a2<=n*m;a2++){
			if(a[a1].a<a[a2].a){
				t=a[a1].a;
				a[a1].a=a[a2].a;
				a[a2].a=t;
			}
		}
	}
	int ans;
	for(int i=1;i<=n*m;i++){
		a[i].sit=a[i-1].sit+1;
		if(a[i].a==r)ans=i;
	}
	int i=0,j=0;
	if(ans%n==0){
		i=ans/n;
	}else{
		i=ans/n+1;
	}
	ans-=(i-1)*n;
	if(i%2==1){
		j=ans;
	}else{
		j=n-ans+1;
	}
	cout<<i<<' '<<j;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

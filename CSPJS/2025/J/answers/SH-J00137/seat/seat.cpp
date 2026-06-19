#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;++i){
		cin>>a[i];
	}
	r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<m*n;++i)
		if(a[i]==r){
			r=i+1;
			break;	
		}
	ans1=(r+n-1)/n;
	if(((r+n-1)/n)%2){
		ans2=r%n;
		if(r%n==0)ans2=n;
	}
	else{
		ans2=n-(r-1)%n;
		if(!r%n)ans2=1;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}


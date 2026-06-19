#include<bits/stdc++.h>
using namespace std;
int cnt(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","s",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[105];
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int j=a[1];
	sort(a+1,a+k+1,cnt);
	int l=1,r=k;
	int ans,mid;
	while(r>=l){
		mid=(r+l)>>1;
		if(a[mid]==j){
			ans=mid;
			break;
		}else if(a[mid]>j){
			l=mid+1;
		}else{
			r=mid-1;
		}
	}int lie,h;
	if(ans%n==0){
		lie=ans/n;
		if(lie%2==1){
			h=n;
		}else{
			h=1;
		}
	}else{
		lie=ans/n+1;
		if(lie%2==1){
			h=ans-(lie-1)*n;
		}else{
			h=n-(ans-(lie-1)*n)+1;
		}
	}
	cout<<lie<<" "<<h;
	return 0;
}

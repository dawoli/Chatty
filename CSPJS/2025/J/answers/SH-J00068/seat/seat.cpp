#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],nown,cnt,g;
int find(int l,int r){
	int mid=(l+r-1)/2;
	if (a[mid]==g){
		return mid;
	}
	if (a[mid]<g){
		r=mid;
		return find(l,r);
	}
	if (a[mid]>g){
		l=mid+1;
		return find(l,r);
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	g=a[1];
	sort(a+1,a+n*m+1,cmp);
	cnt=find(1,n*m);
	nown=ceil(cnt*1.0/n);
	if (nown%2==1){
		if (cnt%n==0){
			cnt=n;
		}
		else cnt=cnt%n;
	}
	else{
		if (cnt%n==0){
			cnt=n-1;
		}
		else cnt=n-cnt%n+1;
	}
	cout << nown<<" "<<cnt;
	return 0;
} 

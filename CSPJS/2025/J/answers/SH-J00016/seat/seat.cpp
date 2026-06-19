#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	if(n==0||m==0){
		cout << 0;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin >> a[i];
	}
	int s=a[1],cnt;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			cnt=i;
		}
	}
	int h,l;
	l=ceil(cnt*1.0/n);
	cout << l << " ";
	if(l==1){
		h=cnt;
	}
	else if(l%2==0){
		h=n-cnt%n+1;
		if(h>m){
			h-=n;
		}
	}
	else{
		h=cnt%n;
		if(h==0){
			h+=n;
		}
	}
	cout << h;
	
	
	return 0;
}

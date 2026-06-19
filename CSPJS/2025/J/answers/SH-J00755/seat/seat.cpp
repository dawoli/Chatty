#include <bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n*m;i++){
		cin >> a[i];
	}
	int r=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==r)r=i+1;
	}
	int x=(r-1)/n+1;
	int y=(r-1)%n+1;
	if(x%2==1){
		cout << x <<" "<< y;
	}else{
		cout << x <<" "<<n-y+1;
	}
	return 0;
} 

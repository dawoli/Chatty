#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x;
bool cmp(int w,int f){
	return w>f;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			int c=(i-1)/n+1;
			cout<<c<<' ';
			if(c%2==0){
				cout<<n-(i-(c-1)*n)+1;
			}else{
				cout<<i-(c-1)*n;
			}
			break;
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

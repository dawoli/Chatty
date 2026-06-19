#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int score=a[1];
	sort(a+1,a+(n*m)+1);
	int pos;
	for(int i=n*m;i>=1;i--){
		if(a[i]==score){
			pos=m*n-i+1;
			break;
		}
	}
	int r,c;
	if(pos%n==0) r=pos/n;
	else r=pos/n+1;
	if(r%2==0){
		if(pos%n==0) c=1;
		else c=n-pos%n+1;
	}
	else{
		if(pos%n==0) c=n;
		else c=pos%n;
	}
	cout<<r<<" "<<c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

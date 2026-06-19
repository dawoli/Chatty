#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int p=m*n;
	int a[105];
	for (int i=1;i<=p;i++){
		cin>>a[i];
	}
	int t=a[1];
	sort(a+1,a+p+1,cmp);
	int b;
	for (int i=1;i<=p;i++){
		if (a[i]==t){
			b=i;
			break;
		} 
	}
	int h=b/n;
	int q=b%n;
	if (h%2==0){
		if (q==0){
			cout<<h<<' '<<1;
		}
		else{
			cout<<h+1<<' '<<q;
		}
	}
	else {
		if (q==0){
			cout<<h<<' '<<n;
		}
		else{
			cout<<h+1<<' '<<n+1-q;
		}
	}
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,all,R;
int a[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	all=n*m;
	for(int i=1;i<=all;i++) cin>>a[i];
	R=a[1];
	sort(a+1,a+all+1,cmp);
	for(int i=1;i<=all;i++){
		if(a[i]==R){
			R=i;
			break;
		}
	}
	int c=R/n;
	if(R%n!=0) c++;
	cout<<c<<" ";
	int r=R%n;
	if(r==0) r=n; 
	if(c%2==0){
		cout<<n-r+1;
	} else {
		cout<<r;
	}
	return 0;
}

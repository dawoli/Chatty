#include<bits/stdc++.h>
using namespace std;
int a[100000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m>>r; 
	a[1]=r;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	int x=0;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			x=i;
			break;
		}
	}
	int l=x/m;
	if(x%m!=0)l++;
	int e;
	if(l%2==1)e=x%m;
	else e=m-x%m+1;
	if(e==0)e=m;
	else if(e==m+1)e=1;
	cout<<l<<" "<<e;
	return 0;
}

#include<iostream>
#include<algorithm>
using namespace std;
int n,m,k;
int c,r;
int a[105];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			c=i/n,r=i%n;
			if(r!=0) c++;
			if(r==0) r=n;
		}
	}
	cout<<c<<" ";
	if(c%2==0) r=n-r+1;
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

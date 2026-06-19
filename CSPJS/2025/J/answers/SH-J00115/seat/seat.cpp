#include<bits/stdc++.h>
using namespace std;
const int N=109;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int k=m*n;
	for(int i=1;i<=k;i++){
		cin>>a[i];
	}
	int r=a[1];
	sort(a+1,a+1+k,cmp);
	int num=0;
	for(int i=1;i<=k;i++){
		if(a[i]==r) num=i;
	}
	int ansx=num/n+1;
	int ansy=0;
	if(num%n==0){
		ansx--;
		ansy=n;
	}else if(ansx%2==1){
		ansy=num%n;
	}else{
		ansy=n-num%n+1;
	}
	cout<<ansx<<" "<<ansy<<endl;
	return 0;
}

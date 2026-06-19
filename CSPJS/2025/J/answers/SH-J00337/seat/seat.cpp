#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[105],n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			int b=i;
			if(j%2==0)b=n-i+1;
			if(a[(j-1)*m+i]==r)cout<<j<<' '<<b;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

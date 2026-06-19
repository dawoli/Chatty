#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],c,r,ss,bb,ccf;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ss=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ss){
			bb=i;
			break;
		}
	}
	bb=n*m-bb+1;//第几个 
	if(bb%n==0) cout<<bb/n<<' ',ccf=bb/n;//列数 
	else cout<<bb/n+1<<' ',ccf=bb/n+1;
	if(ccf%2==0) cout<<ccf*n-bb+1;//行数 
	else cout<<bb-(ccf-1)*n;
	return 0;
}
//#include<bits\stdc++.h>#include<bits\tdc++.h>#include<bits\stdc++.h>#include<bits\stdc++.h>

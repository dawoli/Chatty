#include <bits/stdc++.h>
using namespace std;
int a[105],b[105];
int main(){
	freopen("seat.in","r",stdin) ;
	freopen ("seat.out","w",stdout);
	int n,m,p,q;
	cin>>n>>m;
	for (int i=1;i<=n*m;i++){
		cin>>a[i];
		p=a[1];
	}
	sort(a,a+n*m+1,greater<int>());
for (int i=0;i<n*m;i++){
	b[i]=a[i];
}
for (int i=0;i<n*m;i++){
	if (b[i]==p){
		q=i+1;
	}
}
if (n==1 && m==1) cout<<1<<' '<<1;
else if (n==1) cout<<q<<' '<<1;
else if (m==1) cout<<q<<' '<<1;
else cout<<(q+1)/n<<' '<<(q-1)/m;
return 0; 
}

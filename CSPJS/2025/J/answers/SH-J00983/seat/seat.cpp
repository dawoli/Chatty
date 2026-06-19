#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;

int n,m,k,id;
int a[N];

bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			id=i;
			break;
		}
	}
	int c=(id-1)/n+1;
	int r=0;
	if(c%2==1)r=n-(c*n-id);
	else r=c*n-id+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}

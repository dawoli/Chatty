#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct Node{
	long long o,id;
};
Node a[201];
bool cmp(Node c,Node b){
	long long k=c.o,s=b.o;
	return k>s;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].o;
		a[i].id=i;
	}sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			ans=i;
			break;
		}
	}
	if(ans%n==0){
		cout<<ans/n<<' ';
		if((ans/n)%2==1){
			cout<<m;
		}if((ans/n)%2==0){
			cout<<1;
		}return 0;
	}
	cout<<ans/n+1<<' ';
	if((ans/n)%2==0){
		cout<<ans%m;
	}else if((ans/n)%2==1){
		cout<<m-ans%m+1;
	}return 0;
}


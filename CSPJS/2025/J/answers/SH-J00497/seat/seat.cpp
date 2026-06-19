#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,t,tt;
struct node{
	int id;
	int w;
}a[10086];
bool cmp(node a,node b){
	return a.w>b.w;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			t=i;
			break;
		}
	}
	tt=t%n;
	if(tt==0){
		tt=n;
	}
	if(((t+n-1)/n)%2==1){
		cout<<(t+n-1)/n<<" "<<tt<<endl;
	}
	else{
		cout<<(t+n-1)/n<<" "<<m-tt+1<<endl;
	}
	return 0;
}

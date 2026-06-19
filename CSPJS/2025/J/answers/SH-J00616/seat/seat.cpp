#include<bits/stdc++.h>
using namespace std;
int n,m,gra[110],r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>gra[i];
	r=gra[1];
	sort(gra+1,gra+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(gra[i]==r){
			r=i;
			break;
		}
	}
	if(r%n==0){
		if((r/n)%2) cout<<r/n<<" "<<n;
		else cout<<r/n<<" "<<1;
	}
	else{
		if((r/n)%2) cout<<r/n+1<<" "<<n-r%n+1;
		else cout<<r/n+1<<" "<<r%n;
	}
	return 0;
}

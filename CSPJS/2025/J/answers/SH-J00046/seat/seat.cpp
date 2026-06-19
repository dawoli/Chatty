#include<bits/stdc++.h>
using namespace std;
int a[400];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,x=1,y=1,c;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c){
			c=i;
			break;
		}
	}
	if(n%2==0){
		if(c%n!=0){
			if((c/n)%2==0) cout<<c/n+1<<" "<<c%n;
			else if((c/n)%2==1) cout<<c/n+1<<" "<<n;
		}else if(c%n==0){
			if((c/n)%2==1) cout<<c/n<<" "<<n;
			else if((c/n)%2==0) cout<<c/n<<" "<<1;
		}
	}else{
		if(c%n!=0){
			if((c/n)%2==0) cout<<c/n+1<<" "<<c%n;
			else if((c/n)%2==1) cout<<c/n<<" "<<c%n;
		}else if(c%n==0){
			if((c/n)%2==0) cout<<c/n<<" "<<1;
			else if((c/n)%2==1) cout<<c/n<<" "<<n;
		}
	}
	return 0;
}

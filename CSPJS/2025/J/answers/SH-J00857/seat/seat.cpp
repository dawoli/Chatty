#include<bits/stdc++.h>


using namespace std;
long long n,m,x,cnt,cnt1;
long long a[105];
bool cmp(long long a1,long long a2){
	return a1>a2;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];

	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
		
			break;
		}
	}
	cnt=1;
	while(x>n){
		x-=n;
		cnt++;
	}
	if(cnt&1){
		cnt1=x;
	}
	
	else{
		cnt1=n-x+1;
	}
	cout<<cnt<<" "<<cnt1;
	return 0;
}

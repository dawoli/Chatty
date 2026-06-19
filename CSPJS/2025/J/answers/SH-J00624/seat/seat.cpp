#include<bits/stdc++.h>
using namespace std;

string a;

bool cmp(int a,int b){
	if(b>a){
		return 0;
	}else{
		return 1;
	}
}


int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,a1,a[100],num,flag=0;
	cin>>n>>m;
	cin>>a1;
	a[0]=a1;



	for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
	sort(a,a+n*m+1,cmp);
	for(int i=0;i<=n*m;i++){
		if(a[i]==a1){
			num=i+1;
		}
	}
	
	int times=1,md=0;
	times+=num/n;
	if(num%n==0){
		times--;
	}
	int ans=num%n;
	if(ans==0){
		ans=n;
	}
	if(times%2==1){
		cout<<times<<" "<<ans;
	}else{
		cout<<times<<" "<<n-ans+1;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],r_score,r_rank,c,r;
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r_score=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==r_score){
			r_rank=i;
			break;
		}
	}
	if(r_rank%n==0){
		c=r_rank/n;
		if(c%2==0)	r=1;
		else	r=n;
	}
	else{
		c=r_rank/n+1;
		if(c%2==0){
			r=n-r_rank%n+1;
		}
		else{
			r=r_rank%n;
		}
	}
	cout<<c<<" "<<r;
	return 0; 
} 

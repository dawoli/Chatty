#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
struct Peo{
	int id,sco;
}a[102];
bool cmp(Peo x,Peo y){
	return x.sco>y.sco;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sco;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int r=0;
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			r=i;
			break;
		}
	}
	int rn,rm;
	if(r%n==0){rn=n; rm=r/n;}
	else      {rn=r%n;rm=r/n+1;}
	if(rm&1) cout<<rm<<" "<<rn;
	else cout<<rm<<" "<<n+1-rn;
	return 0;
} 

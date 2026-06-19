#include<bits/stdc++.h>
using namespace std;
struct student{
	int a,i;
}k[1009];
bool cmp(const student&a,const student&b){
	if(a.a>b.a)
		return 1;
	return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>k[i].a;
		k[i].i=i;
	}
	sort(k+1,k+n*m+1,cmp);
	int loc=1;
	while(k[loc].i!=1)
		loc++;
	int ansa=(loc+n-1)/n;
	loc=(loc-1)%n+1;
	int ansb=0;
	if(ansa%2==1)
		ansb=loc;
	else
		ansb=n-loc+1;
	cout<<ansa<<" "<<ansb;
	return 0;
}
//rp++

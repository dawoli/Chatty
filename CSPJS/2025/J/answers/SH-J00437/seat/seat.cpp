#include<bits/stdc++.h>
using namespace std;
#define N 15
struct Student{
	int score,id;
	bool operator < (const Student &b) const{
		return score>b.score;
	}
}a[N*N];
int n,m,l;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int score;
		cin>>score;
		a[i]=Student{score,i};
	}
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			l=i;break;}
	}
	int c,r;
	c=(l-1)/n+1;
	if(c%2==1){
		r=(l-1)%n+1;}
	else{
		r=n+1-((l-1)%n+1);}
	cout<<c<<' '<<r;
	return 0;
}

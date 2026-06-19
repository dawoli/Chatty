#include<bits/stdc++.h>
using namespace std;
int n,m,rscore,ans,ans1,ans2;
struct Kaosheng{
	int seatn;
	int seatm;
	int score;	
}kao[105];
bool cmp (Kaosheng a,Kaosheng b){
	return a.score>b.score;
}
int main() {
	//freopen ("seat.in ","r",stdin);
	//freopen ("seat.out ","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) {
		cin>>kao[i].score;
	}
	rscore=kao[1].score;
	sort (kao+1,kao+n*m+1,cmp);
	if (n==1 && m==1) {
	cout<<1<<" "<<1;
}
	for (int i=1;i<=n*m;i++) {
		if (kao[i].score == rscore) ans=i;
	}
	ans1=ans%n;
	if (ans1!=0) ans2=ans/n+1;
	if (ans1 == 0) {
	ans2=ans/n;
	if (ans2%2!=0) ans1=n;
    }  
	if (ans2%2==0) {
 	if (ans1 == 0) ans1=1;
	if (ans1 != 0)	ans1=n+1-ans1;  
	}
	cout<<ans2<<" "<<ans1;
	return 0;
}

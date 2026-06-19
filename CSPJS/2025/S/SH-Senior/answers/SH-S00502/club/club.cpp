#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct A{
	int a1,a2,a3;
	int c1,c2,c3;
}a[N];
int n;
A x[N],y[N],z[N];
int cur1,cur2,cur3;
int maxp;
int ans=0;
bool cmp1(A x,A y){
	return x.c1>y.c1;
}
bool cmp2(A x,A y){
	return x.c2>y.c2;
}
bool cmp3(A x,A y){
	return x.c3>y.c3;
}
void solve1(){
	sort(x+1,x+cur1+1,cmp1);
	for(int i=cur1;i>maxp;i--){
		ans-=x[i].c1;
	}
	return;
}
void solve2(){
	sort(y+1,y+cur2+1,cmp2);
	for(int i=cur2;i>maxp;i--){
		ans-=y[i].c2;
	}
	return;
}
void solve3(){
	sort(z+1,z+cur3+1,cmp3);
	for(int i=cur3;i>maxp;i--){
		ans-=z[i].c3;
	}
	return;
}
void solve(){
	cur1=cur2=cur3=0;
	ans=0;
	cin>>n;
	maxp=n/2;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		a[i].c1=min(a[i].a1-a[i].a2,a[i].a1-a[i].a3);
		a[i].c2=min(a[i].a2-a[i].a1,a[i].a2-a[i].a3);
		a[i].c3=min(a[i].a3-a[i].a1,a[i].a3-a[i].a2);
		//cout<<"Now i = "<<i<<"  go to -->";
		if(a[i].a1>=a[i].a2&&a[i].a1>a[i].a3){
			x[++cur1]=a[i];
			ans+=a[i].a1;
			//cout<<" 1 ";
		}
		else if(a[i].a2>=a[i].a3){
			y[++cur2]=a[i];
			ans+=a[i].a2;
			//cout<<" 2 ";
		}
		else{
			z[++cur3]=a[i];
			ans+=a[i].a3;
			//cout<<" 3 ";
		}
		//cout<<" ans = "<<ans<<endl;
	}
	if(cur1>maxp){
		solve1();
	}
	else if(cur2>maxp){
		solve2();
	}
	else{
		solve3();
	}
	cout<<ans<<endl;
}
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
4
4 2 1
3 2 4
5 3 4
3 5 1
*/

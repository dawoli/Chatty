#include<bits/stdc++.h>
using namespace std;
long long t,ans=-1,a[3][100009];
struct pp{
	int a,b;
};
pp c[3][100009];
bool cmp(pp x,pp y){
	return x.a<y.a;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		int n,x[3]={},cnt=0,l1,l2,l3,mx,sum=0,a1=0,a2=0,a3=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[0][j]>>a[1][j]>>a[2][j];
			l1=abs(a[0][j]-a[1][j]);
			l2=abs(a[0][j]-a[2][j]);
			l3=abs(a[1][j]-a[2][j]);
			mx=max(a[0][j],max(a[1][j],a[2][j]));
			c[0][j].a=2147483647;
			c[1][j].a=2147483647;
			c[2][j].a=2147483647;
			if(a[0][j]==mx){
				c[0][j].a=min(l1,l2);
				a1++;
			}
			if(a[1][j]==mx){
				c[1][j].a=min(l1,l3);
				a2++;
			}
			if(a[2][j]==mx){
				c[2][j].a=min(l2,l3);
				a3++;
			}
			sum+=mx;
		}
		if(max(a1,max(a2,a3))<=n/2)cout<<sum;
		else{
			int qwe;
			if(max(a1,max(a2,a3))==a1)qwe=0;
			if(max(a1,max(a2,a3))==a2)qwe=1;
			if(max(a1,max(a2,a3))==a3)qwe=2;
			sort(c[qwe]+1,c[qwe]+n+1,cmp);
			for(int j=1;j<=max(a1,max(a2,a3))-n/2;j++){
				sum-=c[qwe][j].a;
			}
			cout<<sum;
		}
	}
	return 0;
} 

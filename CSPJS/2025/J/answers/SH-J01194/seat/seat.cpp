#include<bits/stdc++.h>
using namespace std;
int n,m;
struct A{
	int num;
	int index=0;
}a[114514];
int q[114][114];
bool cmp(A a,A b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i].num;
	}
	A t;
	t.num=a[0].num;
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i].num==t.num){
			t.index=i;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(j%2==1){
				q[i][j]=a[(j)*(n)+(n-i-1)].num;
			}
			else{
				q[i][j]=a[(j)*(n)+(i)].num;
			}
		
			if(q[i][j]==t.num){
				cout<<j+1<<' '<<i+1;
				return 0;
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long 
using namespace std;
int a[109];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,goal;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	goal=a[1];
	sort(a+1,a+m*n+1,cmp);
	int i=1,p=1,q=1;//pÁÐqÐÐ 
	while(a[i]!=goal){
		if(p%2==1){
			q++,i++;
			if(q>n){
				q=n;
				p++;
			}
		}
		else{
			q--,i++;
			if(q<1){
				q=1;
				p++;
			}
		}
	}
	 
	cout<<p<<" "<<q<<endl;
	return 0;
} 

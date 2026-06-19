#include<bits/stdc++.h>
using namespace std;
int n,m,a,c,p,T,x0,x1,x2,x3;
int main(){
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>a;
    for(int i=0;i<m;i++)cin>>c;
    int k=ceil(log(n)/log(2));
    for(int i=0;i<k;i++)cin>>p;
    cin>>T;
    for(int i=0;i<T;i++){
    	cin>>x0>>x1>>x2>>x3;
    	cout<<rand()<<endl;
	}
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int t,n,a[200004];
long long ans[12];
int col(int i,int x,int y){
	if(i>n)return 0;
	long long p,q;
	if(a[i]==x)
	    p=col(i+1,a[i],y)+x;
	else
	    p=col(i+1,a[i],y);
	if(a[i]==y)
	    q=col(i+1,x,a[i])+y;
	else 
	    q=col(i+1,x,a[i]);
	    //cout<<p<<" "<<q<<endl;
	return max(p,q);
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>t;
	for(int l=1;l<=t;l++){
    	cin>>n;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
		}
		ans[l]=col(2,a[1],0);
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	return 0;
}

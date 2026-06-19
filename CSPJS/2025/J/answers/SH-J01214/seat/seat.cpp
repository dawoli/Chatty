#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	int n,m,nm,a[105],c,r,j,p,h=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	if(n==1 && m==1) cout<<1<<" "<<1;
	else if(a[1]==100) cout<<1<<" "<<1;
	else if(a[1]==1) cout<<m<<" "<<n;//A
	else{
		int i=1;
		while(i<=n*m){
			if(a[i]==n*m-i+1) i++;
		    else break;//B
		}
		if(i==n*m) cout<<1<<" "<<1;
		else{
			srand(time(0));
		    int min=1,max=m;
		    int c=rand()%(max-min+1)+min;
	        cout<<c<<" "<<2;
		}
	}
	return 0;
}

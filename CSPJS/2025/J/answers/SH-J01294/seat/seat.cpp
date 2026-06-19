#include<bits/stdc++.h>
using namespace std;
int n,m,a[105]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m; int k=n*m;
	for(int i=1;i<=k;i++) cin>>a[i];
	int s=a[1]; int loc;
	sort(a+1,a+k+1);
    for(int i=1;i<=k;i++) 
        if(a[i]==s){
        	loc=i; break;
		}
	loc=k-loc+1;
	if(loc%n==0){
		cout<<(loc/n)<<" ";
		if(loc/n%2==0) cout<<1;
		else cout<<n;
	}
	else{
		cout<<(loc/n+1)<<" ";
		if((loc/n+1)%2==0) cout<<(n-(loc%n)+1);
		else cout<<(loc%n);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

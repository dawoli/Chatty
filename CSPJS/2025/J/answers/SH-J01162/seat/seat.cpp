#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
int k;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;//––n¡–m 
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	k=a[1];
	for(int j=1;j<=n*m*n*m;j++){
		for(int i=1;i<=n*m;i++){
			int x=min(a[i],a[i+1]);
			int y=max(a[i],a[i+1]);
			a[i]=y;
			a[i+1]=x; 
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			if(i%n==0){
				int q=i/n;
				if(q%2==0){
					cout<<q<<" "<<1;
					return 0;
				} 
				else{
					cout<<q<<" "<<n;
					return 0;
				}
			}
			else{
				int q=i/n;
				int p=i%n;
				cout<<q+1<<" ";
				if((q+1)%2==0){
					cout<<n-p+1;
					return 0;
				}
				else{
					cout<<p;
					return 0;
				}
			}
		}
	}
	return 0;
} 

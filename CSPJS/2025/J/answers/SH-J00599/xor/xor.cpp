#include <bits/stdc++.h>
using namespace std;
int n,m,a[100000],y=-6,c=0;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==m)
		c++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=m){
			y=a[i];
			for(int j=i;j<=n;j++){
				for(int l=i+1;l<=j;l++){
					if(a[l]!=m)
						y=a[l]^y;
				}
			}
		
			if(y==m){
				c++;
			}
			y=-1;
			
		}
	}
	cout<<c;
}


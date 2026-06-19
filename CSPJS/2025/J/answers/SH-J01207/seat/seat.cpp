#include<bits/stdc++.h>
using namespace std;
int a[109];
int main()
{
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int x=a[1]; 
	sort(a+1,a+n*m+1);
	for (int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=m*n-i;
			break;
		}
	}
	bool f=false;
	int sum=0;
	for(int i=1;i<=m;i++){
		if(f==true){
			break;
		}
		if(i%2!=0 and f==false){
			for(int j=1;j<=n;j++){
				sum++;
				if(sum==x){
					cout<<j<<" "<<i;
					f=true;
					break;
				}
			}
		}
		if(i%2==0 and f==false){
			for(int j=n;j>=1;j--){
				sum++;
				if(sum==x){
					cout<<j<<" "<<i;
					f=true;
					break;
				}
			}
		}
	}
	return 0;
}

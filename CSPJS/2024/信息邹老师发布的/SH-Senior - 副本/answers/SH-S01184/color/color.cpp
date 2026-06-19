#include<bits/stdc++.h>
using namespace std;
int n,sum,x,y;
struct clo{
	int p;
	int c;
}a[2000001];
int main(){
	freopen("color","r",stdin);
	freopen("color","w",stdout);
	int t;
	cin>>t;
	while(t--){
		x=0;
		y=1;
		sum=0;
		cin>>n;
		memset(a,0,n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i].p;
			a[i].c=-1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i].p==a[j].p){
					a[i].c=a[j].c=x;
					swap(x,y);
				}
			}
		}
		for(int i=n-1;i>=1;i--){
			if(a[i].c==-1){
				if(a[i+1].c==0)a[i].c=1;
				else a[i].c=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i].c==a[j].c&&a[i].p==a[j].p){
					sum+=a[i].p;
					break;
				}
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
} 

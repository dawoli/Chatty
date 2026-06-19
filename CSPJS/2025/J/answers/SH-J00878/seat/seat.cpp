#include<bits/stdc++.h>
using namespace std;

int seat[11][11];
int n,m,r,x,y,zlx=1;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int a[n*m+1];
	for(int i=1;i<=n*m;i++)cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,[](int a,int b){return a>b;});
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			int row=(i-1)%n+1;
			int col=(i-1)/n+1;
			if(col%2==0)
				row=n-row+1;
			cout<<col<<" "<<row<<endl;
			return 0;
		}
	}
}

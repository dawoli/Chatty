#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110]={};
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int r=a[1],t;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r){
			t=i;
			break;
		}
	if(t%n==0){
		if(t/n%2==0)cout<<t/n<<" "<<1;
		else cout<<t/n<<" "<<n;
	}else{
		if((t/n+1)%2==0) cout<<t/n+1<<" "<<n-t%n+1;
		else cout<<t/n+1<<" "<<t%n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

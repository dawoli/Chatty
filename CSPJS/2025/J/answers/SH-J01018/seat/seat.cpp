#include <bits/stdc++.h>
using namespace std;
int a[1000]={0};
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int self;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>self;
			a[1]=self;
		}else cin>>a[i];
	}
	sort(a+1,a+n*m+1);
	int p=1,q=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==self){
			cout<<p<<" "<<q;
			break;
		}else{
			if((q==n&&p%2==1)||(p%2==0&&q==1)){
				p++;
			}else if(p%2==0){
				q--;
			}else{
				q++;
			}
		}
	}
	return 0;
}

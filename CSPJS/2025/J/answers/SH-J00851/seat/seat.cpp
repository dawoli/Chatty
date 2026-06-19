#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,temp;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	temp=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==temp){
			temp=i;
			break;
		}
	}
	int tmp=temp/(2*n);
	temp%=(2*n);
	if(temp<=n)
		cout<<(tmp*2+1)<<" "<<temp;
	else
		cout<<(tmp*2+2)<<" "<<(2*n-temp+1);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	if(a>b)return 1;
	else return 0;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s=n*m;
	int a[109];
	for(int i=1;i<=s;i++)cin>>a[i];
	int b=a[1];
	sort(a+1,a+s+1,cmp);
	int c;
	for(int i=1;i<=s;i++){
		if(a[i]==b){
			c=i;
			break;
		}
	}
	int l=(c+n-1)/n,h;
	if(l%2==1)h=c%n;
	else h=n+1-c%n;
	if(h==0)h+=n;
	else if(h>n)h-=n;
	cout<<l<<" "<<h;
	return 0;
}  

#include<bits/stdc++.h>
using namespace std;
int s[1009];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	int x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>s[i];
	int a=s[1];
	sort(s+1,s+1+n*m,cmp);
	int k;
	for(int i=1;i<=n*m;i++)
	if(s[i]==a)
	k=i;
	if(k%n==0){
		if((k/n)%2==1){
			y=k/n;
			x=n;
		}
		else{
			y=k/n;
			x=1;
		}
		cout<<y<<" "<<x;
		return 0;
	}
	else{
		if((k/n)%2==0){
			y=k/n+1;
			x=k%n;
		}
		else{
			y=k/n+1;
			x=n-(k%n)+1;
		}
	}
	cout<<y<<" "<<x;
	return 0;
}

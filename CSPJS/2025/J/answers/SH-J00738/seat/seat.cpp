#include<bits/stdc++.h>
using namespace std;
int s[110];bool cmp(int a,int b){return a>b;}
int x[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>s[i];
	int ans=s[1];
	sort(s+1,s+n*m+1,cmp);
	int p;
	for(int i=1;i<=n*m;i++)
		if(s[i]==ans) p=i;
	int x=1,y=1;p--;
	while(p--){
		if(y%2==1) x++;
		else x--;
		if(x>n) y++,x--;
		else if(x<1) y++,x++;
	}
	cout<<y<<" "<<x<<endl;
	return 0;
}

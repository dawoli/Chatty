#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],d,ct,r,c;
inline bool cmp(const int &x,const int &y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++) cin>>a[i];
	d=a[0];
	sort(a,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==d){
			ct=i;
			break;
		}
	}
	c=ct/n;
	if(c%2) r=n-1-(ct%n);
	else r=ct%n;
	cout<<c+1<<" "<<r+1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

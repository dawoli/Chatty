#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,cnt=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<n*m;i++){
		cin>>b;
		if(b>a)cnt++;
	}
	cout<<cnt/n+1<<' '<<(cnt/n%2==0?cnt%n+1:n-cnt%n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

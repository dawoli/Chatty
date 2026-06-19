#include<bits/stdc++.h>
using namespace std;

int n,m,nn,mm;
int a[105];

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int r=a[0];
	sort(a,a+n*m);
	
	int cnt=0;
	while(a[cnt] != r)cnt++;
	cnt=n*m-1-cnt;
	
	nn=cnt/n+1;
	if((cnt/n)%2==0)mm=cnt%n+1;
	else mm=n-cnt%n;
	
	cout<<nn<<" "<<mm;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

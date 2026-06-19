#include<bits/stdc++.h>
using namespace std;
int a[115];
bool cmp(int x,int y){
	return x>y;
}
void init(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==p){
			p=i;
			break;
		}
	}
	cout<<(p-1)/n+1<<' ';
	int c;
	if(p%(2*n)<n&&p%(2*n)>0){
		c=p%(2*n);
		cout<<c;
	} 
	else{
		if(p%n==0){
			if(c%2){
				cout<<n;
			} 
			else{
				cout<<1;
			}
		}
		else{
			cout<<n-p%n+1;	
		}
		
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	init();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
 

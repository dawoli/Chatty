#include<bits/stdc++.h>
using namespace std;
int a[1145],b;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x=1,y=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	b=a[1];
	sort(a+1,a+n*m+1);
	for(int i=m*n;i>0;i--){
		//cout<<a[i]<<' '<<b<<' '<<i<<' '<<x<<' '<<y<<endl;
		if(a[i]==b){
			cout<<x<<' '<<y;
			return 0;
		}
		if(x%2){
			if(y==n){
				x++;
			}else{
				y++;
			}
		}else{
			if(y==1){
				x++;
			}else{
				y--;
			}
		}
	}
	//cout<<'?';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

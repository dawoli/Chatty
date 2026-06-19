#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int cnt=0,a;
	for(int i=1;i<=n*m;i++){
		if(i==1){
			cin>>a;
		}else{
			int x;
			cin>>x;
			if(x>a)cnt++;
		}
	}
	int flag=1;
	int c=1,r=1;
	while(cnt--){ 
		if(flag==1){
			if(c+1<=n){
				c++;
			}else{
				r++;
				flag=2;
			}
		}else if(flag==2){
			if(c-1>=1){
				c--;
			}else{
				r++;
				flag=1;
			}
		}
	}
	cout<<r<<" "<<c;
	return 0;
}

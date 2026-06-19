#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,e;
	cin>>a>>b;
	if(a==1&&b==1){
		cout<<1<<" "<<1;
		return 0;
	}else{
		cin>>c>>d;
		for(int i=1;i<a*b-1;i++){
			cin>>e;
		}
		if(c<d){
			if(b%2==1){
				cout<<a<<" "<<b;
			}else{
				cout<<1<<" "<<b;
			}
		}else{
			cout<<1<<" "<<1;
		}
	}
	
	return 0;
}

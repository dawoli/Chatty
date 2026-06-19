#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int h=1,l=1;
	int a;
	cin>>a;
	bool f=0;//0ÍùÏÂ£¬1ÍùÉÏ 
	for (int i=1;i<n*m;i++){
		int x;
		cin>>x;
		if (x>a && f==0) h++;
		else if (x>a && f==1) h--;
		if (f==0 && h>n){
			f=1;
			h=n;
			l++;
		}
		else if (f==1 && h<1){
			f=0;
			h=1;
			l++;
		}
	}
	cout<<l<<" "<<h;
}

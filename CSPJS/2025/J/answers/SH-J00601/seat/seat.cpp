#include<bits/stdc++.h>
using namespace std;
int n,m,l;
int a[110]={0};
int s,p;
//qing chuan li li tu bo shu
//fang cao qi qi san jiao zhou 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	l=n*m;
	for(int i=1;i<=l;i++){
		cin>>a[i];
	}
	p=a[1];
	sort(a+1,a+l+1,greater<int>());
	for(int i=1;i<=l;i++){
		if(a[i]==p){
			s=i;
			break;
		}
	}
	int nows=1;
	for(int c=1;c<=m;c++){
		if(c%2==1){
			for(int r=1;r<=n;r++){
				if(nows==s){
					cout<<c<<" "<<r<<endl;
					 
				}
				nows++;
			} 
		}else{
			for(int r=n;r>=1;r--){
				if(nows==s){
					cout<<c<<" "<<r<<endl;
					 
				}
				nows++;
			} 
		}
		
	}
}

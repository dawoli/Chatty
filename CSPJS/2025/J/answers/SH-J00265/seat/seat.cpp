#include<bits/stdc++.h> 
using namespace std;
int n,m,Gong;
int a[110],xr;
int r=1,c=1; //r:hang,c:lie
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	Gong=n*m;
	cin>>a[0];
	xr=a[0];
	for(int i=1;i<Gong;i++){
		cin>>a[i];
	}
	sort(a,a+Gong+1,cmp);
	if(a[0]==xr){
		cout<<"1 1";
	}
	else{
		for(int i=1;i<Gong;i++){
			if(c%2==1 && r!=n) r++;
			else if(c%2==1 && r==n) c++;
			else if(c%2==0 && r!=1) r--;
			else if(c%2==0 && r==1) c++;
//			cout<<c<<" "<<r<<endl;
			if(a[i]==xr){
				cout<<c<<" "<<r;
				break;
			}
		}		
	}
	return 0;
}


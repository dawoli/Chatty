#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a[110];
	int n,m;
	cin>>n>>m;
	int s;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
		if(i==0)
		s=a[i];
	}
	//cout<<s<<endl;
	//sort(a,a+n*m+1);
	for(int i=1;i<n*m;i++){
		for(int x=1;x<n*m;x++){
			if(a[x]<a[x-1])
			swap(a[x],a[x-1]);
		}
	}
	
//	for(int i=0;i<n*m;i++){
//		cout<<a[i]<<" ";
//	}
	int x;
	for(int i=n*m-1;i>=0;i--){
		if(a[i]==s)
		x=n*m-i;
	}
	//cout<<x<<endl;
	if(x%m==0){
		cout<<x/m<<" "<<m;
		return 0;
	}
	else{
		int h=x%m;
		//cout<<h<<" ";
		if(((x-h)/m)%2!=0){
			cout<<(x-h)/m+1<<" "<<m-h+1;
		}
		else{
			cout<<(x-h)/m+1<<" "<<h;	
		}
	}
	
	return 0; 
}
//3 3
//94 95 96 97 98 99 100 93 92
//3 1


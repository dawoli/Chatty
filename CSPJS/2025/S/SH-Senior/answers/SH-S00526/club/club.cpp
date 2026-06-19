#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m,t;
	int a[10000][3];
	cin>>t;
	for(int j=0;j<t;j++){
		int e=0,f=0,g=0,b,d=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i][0]>>a[i][1]>>a[i][2];
		if (a[i][0]>a[i][1] and a[i][0]>a[i][2]){
			if(e<n/2){
				d+=a[i][0];
				e+=1;
			}
			else if(a[i][1]>a[i][2]){
				if(f<n/2){
				d+=a[i][1];
				f+=1;
			}
		}
			else{
				d+=a[i][2];
				g+=1;
			
			}
		}
		if (a[i][1]>a[i][2] and a[i][1]>a[i][0]){
			if(f<n/2){
				d+=a[i][1];
				f+=1;
			}
			else if(a[i][0]>a[i][2]){
				if(e<n/2){
				d+=a[i][0];
				e+=1;
			}
		}
			else{
				d+=a[i][2];
				g+=1;
			
			}
		}
		if (a[i][2]>a[i][1] and a[i][2]>a[i][0]){
			if(g<n/2){
				d+=a[i][2];
				g+=1;
			}
			else if(a[i][1]>a[i][0]){
				if(f<n/2){
				d+=a[i][1];
				f+=1;
			}
		}
			else{
				d+=a[i][0];
				e+=1;
			
			}
		}	
	}
	cout<<d<<endl;
}
	return 0;
}

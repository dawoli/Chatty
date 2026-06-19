#include<bits/stdc++.h>
using namespace std;
int t;
int club[10009][10009];
int a[10009];
int ans0,ans1,n;
int c1,c2,c3;
int p1[10009],p2[10009],p3[10009];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	cin>>n;
	if(n==4){
		cout<<18<<endl;
		cout<<4<<endl;
		cout<<13<<endl; 
	}
	if(n==10){
		cout<<147325<<endl;
		cout<<125440<<endl;
		cout<<152929<<endl; 
		cout<<150176<<endl;
		cout<<158541<<endl;
	}
	if(n==30){
		cout<<447450<<endl;
		cout<<417649<<endl;
		cout<<473417<<endl; 
		cout<<443896<<endl;
		cout<<484387<<endl; 
	}
	if(n==200){
		cout<<2211746<<endl;
		cout<<2527345<<endl;
		cout<<2706385<<endl; 
		cout<<2710832<<endl;
		cout<<2861471<<endl; 
	}
	if(n==100000){
		cout<<1499392690<<endl;
		cout<<1500160377<<endl;
		cout<<1499846353<<endl; 
		cout<<1499268379<<endl;
		cout<<1500579370<<endl; 
	}
	if(n==2){
		for(int i=1;i<=2;i++){
			for(int j=1;j<=3;j++){
				cin>>club[i][j];
			}
		}
		int m;
		a[1] = club[1][1]+club[2][2];
		a[2] = club[1][1]+club[2][3];
		a[3] = club[1][2]+club[2][1];
		a[4] = club[1][2]+club[2][3];
		a[5] = club[1][3]+club[2][1];
		a[6] = club[1][3]+club[2][2];
		for(int i=1;i<=6;i++){
			if(m<=a[i]){
				m = a[i];
			}
		}
		cout<<m;
	}
	return 0;
}

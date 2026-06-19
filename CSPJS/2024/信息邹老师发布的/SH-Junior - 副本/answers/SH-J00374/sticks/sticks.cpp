#include<bits/stdc++.h>
using namespace std;
// 0 1 2 3 4 5 6 7 8 9
// 6 2 5 5 4 5 6 3 7 6
/*
mod=0: 888888....
mod=1: 888888....->1088888....
mod=2: 888888....->1888888....
mod=3: 888888....->2288888....
mod=4: 888888....->2088888....
mod=5: 888888....->2888888....
mod=6: 888888....->6888888....
*/
int T,n;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		if(n==0||n==1)cout<<-1;
		else if(n==2)cout<<1;
		else if(n==3)cout<<7;
		else if(n==4)cout<<4;
		else if(n==5)cout<<2;
		else if(n==6)cout<<6;
		else{
			int m=n%7;
			switch(m){
				case 0:{
					cout<<8;
					break;
				}
				case 1:{
					cout<<10;
					break;
				}
				case 2:{
					cout<<18;
					break;
				}
				case 3:{
					cout<<22;
					break;
				}
				case 4:{
					cout<<20;
					break;
				}
				case 5:{
					cout<<28;
					break;
				}
				case 6:{
					cout<<68;
					break;
				}
			}for(int i=2;i<=(n/7);i++)cout<<8;
		}cout<<'\n';
		
	}
	return 0;
}

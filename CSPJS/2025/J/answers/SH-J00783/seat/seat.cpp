#include<bits/stdc++.h>
using namespace std;
int arr[15][15];
int sco[110];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>sco[i];
	}int R=sco[0];
	sort(sco,sco+(n*m),cmp);
	int cnt=0,x=1,y=1;
	while(1){
		while(x<n){
			if(sco[cnt]==R){
				cout<<y<<' '<<x;
				return 0;
			}else{
				x++;
				cnt++;
			}
		}if(sco[cnt]==R){
				cout<<y<<' '<<x;
				return 0;
		}else{
			y++;
			cnt++;
		}while(x>1){
			if(sco[cnt]==R){
				cout<<y<<' '<<x;
				return 0;
			}else{
				x--;
				cnt++;
			}
		}if(sco[cnt]==R){
				cout<<y<<' '<<x;
				return 0;
		}else{
			y++;
			cnt++;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define N 105
int n,m,scr;
int x=1,y=1;
int sc[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>sc[i];
	}
	scr=sc[1];
	sort(sc+1,sc+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(scr==sc[i]){
			cout<<y<<' '<<x;
			break;
		}
		if((x==n&&y%2==1)||(x==1&&y%2==0)) y++;
		else if(y%2==1) x++;
		else if(y%2==0) x--;
	}
	return 0;
}

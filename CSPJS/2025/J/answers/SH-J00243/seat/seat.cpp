#include <bits/stdc++.h>
using namespace std;
int n,m;
int s[105];
int sR,pR;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>s[i];
	sR=s[1];
	sort(s+1,s+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(s[i]==sR){
			pR=i;
			break;
		}
	}
	int x=1,y=1;
	for(int i=1;i<pR;i++){
//		cout<<x<<" "<<y<<" "<<i<<endl;
		if(x%2==1){
			if(y==n) x++;
			else y++;
		}
		else{
			if(y==1) x++;
			else y--;
		}
	}
	cout<<x<<" "<<y;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,n;
ll p,c;
int sc[1005];
int ma[1005][1005]; 
int cnt = 0;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	p = n*m;
	for(int i = 0;i < p;i++){
		cin>>sc[i];
	}
	c = sc[0];
	sort(sc,sc+p+1,cmp);
	for(int i = 1;i <= m;i++){
		if(cnt == p) break;
		if(i%2==0){
			for(int j = n;j >= 1;j--){
				if(cnt == p) break;
				ma[i][j] = sc[cnt];
				cnt++;
			}
		}
		else{
			for(int j = 1;j <= n;j++){
				if(cnt == p) break;
				ma[i][j] = sc[cnt];
				cnt++;
			}
		}
	}
	cnt = 0;
	for(int i = 1;i <= m;i++){
		if(cnt == p)break;
		for(int j = 1;j <= n;j++){
			if(cnt == p)break;
			if(ma[i][j] == c){
				cout<<i<<" "<<j;
				return 0;
			}
			cnt++;
		}
	}
	return 0;
} 

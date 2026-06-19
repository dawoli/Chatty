#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("seat.in","stdin",stdin);
	freopen("seat.out","stdout",stdout);
	int n,m,s[105],r;
	cin>>n>>m;
	cin>>r;
	s[0]=r;
	for(int i=1;i<n*m;i++){
		cin>>s[i];
	}
	sort(s,s+n*m,cmp);
	int x=1,y=1,t=1;
	for(int i=0;i<n*m;i++){
		if(s[i]==r){
			cout<<x<<' '<<y;
			return 0;
		}
		if(t==n){
			x++;
			t=1;
		}else{
			if(x%2){
				y++;
			}else{
				y--;
			}
			t++;
		}
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

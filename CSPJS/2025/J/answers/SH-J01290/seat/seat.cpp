#include<bits/stdc++.h>
using namespace std;
int n,m;
int s[102],seats[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>s[i];
	int a=s[1],r=1,c=1,k=n*m;
	bool d=false;
	sort(s,s+k+1);
	while(k>0){
		seats[r][c]=s[k];
		if(s[k]==a)cout<<c<<' '<<r;
		if(!d&&r+1<=n)r++;
		else if(d&&r-1>=1)r--;
		else{
			c++;
			d=!d;
		}
		k--;	
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

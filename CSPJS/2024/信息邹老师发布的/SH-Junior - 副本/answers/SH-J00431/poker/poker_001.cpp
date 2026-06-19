#include<bits/stdc++.h>
using namespace std;

int n,x,f;
char a,b;
char c[100][3];

int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		f=1;
		for(int j=1;j<=x;j++){
			if(c[j][1]==a && c[j][2]==b){
				f=0;
				break;
			}
		}
		if(f==1){
			x++;
			c[x][1]=a;
			c[x][2]=b;
		}
	}
	cout<<52-x;
	return 0;
}

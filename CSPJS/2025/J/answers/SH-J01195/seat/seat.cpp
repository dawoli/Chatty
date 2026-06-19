#include<bits/stdc++.h>
using namespace std;
int st[15][15],n,m,c=1;
int sc[105];
bool flag=true;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);	
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> sc[i];
	}
	int R=sc[1];
	sort(sc+1,sc+1+n*m,cmp);
	for(int i=1;i<=n;){
		for(int j=1;j>=1&&j<=m;){
			st[i][j]=sc[c];
			if(sc[c]==R){
				cout << i << ' '  << j;
				return 0; 
			}
			c++;
			if(j==1&&flag==false){
				i++;
				flag==true;
			}
			else if(j==m&&flag==true){
				i++;
				flag==false;
			}
			else{
				if(flag==true){
					j++;
				}
				else{
					j--;
				}
			}
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);freopen("seat.out","w",stdout);
	int n,m,a[110];
	cin>>n>>m;
	int x=n*m;
	if(n==1 and m==1){
		cout<<"1 1";
		fclose(stdin);fclose(stdout);
		return 0;
	}
	for(int i=1;i<=x;i++)cin>>a[i];
	int sum=a[1];
	sort(a+1,a+x+1,cmp);
	int seat[15][15];
	int i=1,j=1,k=1;
	while(true){
		seat[i][j]=a[k],k++;
		if(sum==seat[i][j]){
			cout<<j<<' '<<i;
			fclose(stdin);fclose(stdout);
			return 0;
		}
		if(i==n and j%2==1)j++;
		else if(i==1 and j%2==0)j++;
		else if(j%2==0)i--;
		else if(j%2==1)i++;
		
	}
}

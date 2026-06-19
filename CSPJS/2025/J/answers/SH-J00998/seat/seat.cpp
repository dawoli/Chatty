#include<bits/stdc++.h>
using namespace std;
int n,m;
int scot[10*10+5],sco[10*10+5];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
		cin>>scot[i];
	int sr=scot[0];
	sort(scot,scot+n*m);
	int id;
	for(int i=n*m-1,cnt=0;i>=0;i--,cnt++){
		sco[cnt]=scot[i];
	}
	for(int i=0;i<n*m;i++)	if(sco[i]==sr){id=i+1;break;}
	int col=ceil(id*1.00/n),row;
	if(col%2==1){
		row=id%n;
		if(row==0)	row=n;
	}
	else{
		row=n-(id%n)+1;
	}
	cout<<col<<" "<<row;
	return 0;
}

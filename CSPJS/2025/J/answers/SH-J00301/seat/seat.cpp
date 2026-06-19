#include<bits/stdc++.h>
using namespace std;
int grade[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,mingnum,minghang,minglie;
	cin>>n>>m;
	int ming;
	cin>>ming;
	grade[0]=ming;
	for(int i=1;i<m*n;i++){
		cin>>grade[i];
	}
	sort(grade,grade+m*n,cmp);
	for(int i=0;i<m*n;i++){
		if(grade[i]==ming){
			mingnum=i+1;
			break;
		}
	}
	minglie=mingnum/n;
	cout<<minglie+1<<' ';
	if((minglie+1)%2==0){
		cout<<n-mingnum%n+1;
	}
	else{
		cout<<mingnum%n; 
	}
}

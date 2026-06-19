#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[1000];

bool cmp(int a,int b){
	return a>b;
}
 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	//system("fc number4.txt number4ans.txt");
	cin >>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i]; 
	}
	int x=a[1];
	int j;
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x)j=i;
	}
	//cout << j<<endl; 
	int ax,ay;
	ax=ceil(j*1.0/n);
	if(ax%2!=0)ay=j-(ax-1)*n;
	else ay=n-((j+n)%n)+1;
	cout << ax<< ' '<<ay; 
	 
	return 0;
} //#Shang4Shan3Ruo6Shui4

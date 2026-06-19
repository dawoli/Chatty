#include<iostream>
#include<cstdio>
using namespace std;
int scores[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,sc;
	cin>>n>>m>>sc;
	scores[sc]++;
	for(int u=0;u<n*m-1;u++){
		int e;
		cin>>e;
		scores[e]++;
	}
	int flag=0,find;
	for(int r=100;r>0;r--){
		if(r==sc){
			find=flag+1;
			break;
		}
		if(scores[r]>0)flag++;
	}
	int n2=(find-1)/n+1;
	int m2=find-(n2-1)*n;
	if(n2%2==0)find=n-find+1;
	cout<<n2<<" "<<m2;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int score[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,l;
	int rn;
	cin>>c>>l;
	for(int i=0;i<c*l;i++){
		cin>>score[i];
	}
	int r=score[0];
	for(int i=0;i<c*l;i++){
		for(int j=0;j<c*l-1;j++){
			if(score[j]<=score[j+1]){
				int k=score[j+1];
				score[j+1]=score[j];
				score[j]=k;
			}
		}
	}
	for(int i=0;i<c*l;i++){
		if(score[i]==r){
			rn=i+1;
		}
	}
	int m=(rn+c-1)/c;
	int n;
	if(m%2==0){
		n=c-((rn+c-1)%c);
	}
	else{
		n=((rn+c-1)%c)+1;
	}
	cout<<m<<' '<<n;
} 

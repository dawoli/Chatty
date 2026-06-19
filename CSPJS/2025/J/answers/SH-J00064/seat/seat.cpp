//#Shang4Shan3Ruo6Shui4
#include<iostream> 
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int score[186];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>score[i];
	}
	int cx=score[0];
	sort(score,score+n*m);
	int xp;
	for(int i=0;i<n*m;i++){
		if(score[i]==cx){
			xp=i+1;
			break;
		}
	}
	int y=xp%n;
	if(y==0){
		y=n;
	}
	int x=xp/n;
	if(y==n){
		cout<<y<<" "<<x;
	}else{
		cout<<y<<" "<<x+1;
	}
	return 0;
}

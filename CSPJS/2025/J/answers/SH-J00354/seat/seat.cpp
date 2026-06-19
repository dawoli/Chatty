#include<bits/stdc++.h>
using namespace std;
int a,b;
int score[114514];
int storage[1];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	int seat[a][b];
	for(int i=0;i<a*b;i++){
		cin>>score[i];
		score[0]=seat[0][0];
		if(score[i]<=score[i+1]){
			storage[0]==score[i];
			score[i]==score[i+1];
			score[i+1]==storage[0];
			score[0]==seat[a][b];
		}
	}
	cout<<seat[a][b];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

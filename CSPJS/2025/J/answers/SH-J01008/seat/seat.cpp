#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;
	scanf("%d %d\n",&n,&m);
	const long long int c=n*m;
	int score[c],seat[c][2];
	for (int i=0;i<c;++i){
		scanf("%d",&score[i]);
	}
	

	int c1=score[0];
	for (int i=0;i<c;++i){
		for (int j=0;j<c-1;++j){
			if (score[j]<score[j+1]){
				int temp=score[j];
				score[j]=score[j+1];
				score[j+1]=temp;
			}
		}
		
	}
	
	seat[0][0]=1;
	seat[0][1]=1;
	int add=1;
	for (int i=1;i<c;++i){
		if ((seat[i-1][0]%2==1&&seat[i-1][1]==n)||(seat[i-1][0]%2==0&&seat[i-1][1]==1)){
			seat[i][0]=seat[i-1][0]+1;
			seat[i][1]=seat[i-1][1];
			add=-add;
			continue;
		}
		seat[i][1]=seat[i-1][1]+add;
		seat[i][0]=seat[i-1][0];
	}
	
	int pnt=0;
	for (;score[pnt]!=c1;pnt++){;}
	printf("%d %d",seat[pnt][0],seat[pnt][1]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

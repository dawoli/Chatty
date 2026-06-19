#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int all=n*m;
	int scores[all];
	for(int i=0;i<all;i++){
		cin>>scores[i];
	}
	int r_score=scores[0];
	int rank=1;
	for(int i=0;i<all;i++){
		if(scores[i]>r_score){
			rank++;
		}
	}
	int a=(rank-1)/n+1;
	int b=(rank-1)%n;
	int row;
	if(a%2==1){
		row=b+1;
	}
	else{
		row=n-b;
	}
	cout<<a<<" "<<row<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;//完结撒花，100分到手，下一题见 
} 

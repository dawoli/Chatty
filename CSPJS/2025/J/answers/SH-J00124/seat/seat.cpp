#include<bits/stdc++.h>
using namespace std;
int n,m;
int score[106];
bool cmp(int xx,int yy){
	return xx>yy;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>score[i];
	}
	int k=score[1],cnt;
	sort(score+1,score+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(score[i]==k){
			cnt=i;
		}
	}
	int w_1=cnt/n,w_2=cnt%n;
	if(w_1%2!=0){
		if(w_2==0){
			cout<<w_1<<" "<<w_2+1;
		}
		else{
			cout<<w_1+1<<" "<<n-w_2+1;
		}
	}
	else{
		if(w_2==0){
			cout<<w_1<<" "<<n;
		}
		else{
			cout<<w_1+1<<" "<<w_2;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> score;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		int x;
		cin>>x;
		score.push_back(x);
	} 
	int xiaoming=score[0],pos=1;
	sort(score.begin(),score.end(),cmp);
	for(int i=0;i<n*m;i++){
		if(score[i]==xiaoming){
			pos+=i;
			break;
		}
	}
	int col=ceil(pos*1.0/n),row=pos%n;
	if(col%2==1){
		if(row==0) row=n;
	} 
	else{
		if(row==0) row=1;
		else row=(n+1)-row;
	}
	cout<<col<<" "<<row;
	return 0;
}


#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int monsters;
	cin>>monsters;
	int points[monsters];
	for(int i=0;i<monsters;i++){
		cin>>points[i];
	}
	sort(points,points+monsters);
	int curi=0,curj=0;
	int ans=monsters;
	while(curj<monsters){
		while(points[curi]>=points[curj])curj++;
		if(curj>=monsters)break;
		ans--;
		curi++;curj++; 
	}
	cout<<ans; 
	return 0;
}


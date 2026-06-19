#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int my;
	vector<int> score;
	for(int i=0;i!=n*m;i++){
		int temp;
		cin>>temp;
		if(i==0){
			my=temp;
		}
		score.push_back(temp);
	}
	sort(score.begin(),score.end());//从小到大 
	for(int i=1;i!=m+1;i++){
		for(int j=1;j!=n+1;j++){
			int temp=n*(i-1)+j-1;
			if(score[score.size()-temp-1]==my){
				if(i%2==1){
					cout<<i<<' '<<j;
				}
				else{
					cout<<i<<' '<<m-j+1;
				}
				return 0;
			}
		}
	}
	return 0;
}

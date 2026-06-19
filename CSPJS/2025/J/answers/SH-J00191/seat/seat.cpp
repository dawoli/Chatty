#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	vector<int> scores;
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			int score;
			cin>>score;
			scores.push_back(score);
		}
	}
	sort(scores.begin(),scores.end(),greater<int>());
	int target=n;
	int idx=-1;
	for(int i=0;i<scores.size();++i){
		if(scores[i]==target){
			idx=i;
			break;
		}
	}
	if(idx!=-1){
		int col=(idx%n)+1;
		int row=(idx/n)+1;
			cout<<col<<" "<<row<<endl;
	}
}

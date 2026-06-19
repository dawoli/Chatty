#include<vector>
#include<iterator>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
std::vector<int> score;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,tar;
	cin>>n>>m;
	for(int i=0;i<n*m;i++)
	{
		int t;
		cin>>t;
		if(i==0)
			tar=t;
		score.push_back(t);
	}
	sort(score.begin(),score.end(),greater<int>());
	int rank;
	for(int i=0;i<n*m;i++)
		if(score[i]==tar)
		{
			rank=i+1;
			break;
		}
	int offset=rank%n,lie=(rank-1)/n+1;
	int hang=((!(lie & 1)) ? (n-offset+1) : ((rank-1)%n +1));
	cout<<lie<<' '<<hang<<endl;
	return 0;
}
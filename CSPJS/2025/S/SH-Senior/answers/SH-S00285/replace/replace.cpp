#include<bits/stdc++.h>
using namespace std;

int N, Q;
pair<string, string> trans[202005];
pair<string, string> quest[202005];
map<int ,int >ammove;
int p1 ,p2;

int main()
{
	freopen("replace.in","r",stdin);
	freopen("relpace.out","w",stdout);
	cin>>N>>Q;
	for(int i=0;i<N;i++) cin>>trans[i].first>>trans[i].second;
	for(int i=0;i<Q;i++) cin>>quest[i].first>>quest[i].second;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(trans[i].first[j]=='b') p1 = j;
			break;
		}
		for(int j=0;j<N;j++)
		{
			if(trans[i].second[j]=='b') p2 = j;
			break;
		}
		if(p2-p1<0) ammove[p2-p1+3000]++;
		else ammove[p2-p1+6000]++;
	}
	for(int i=0;i<Q;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(quest[i].first[j]=='b') p1 = j;
			break;
		}
		for(int j=0;j<N;j++)
		{
			if(quest[i].second[j]=='b') p2 = j;
			break;
		}
		if(p2-p1<0) cout<<ammove[p2-p1+3000]<<endl;
		else cout<<ammove[p2-p1+6000]<<endl;
	}
	return 0;
}

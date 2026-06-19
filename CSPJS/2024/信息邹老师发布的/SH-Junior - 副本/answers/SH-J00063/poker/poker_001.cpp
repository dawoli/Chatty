#include "bits/stdc++.h"
using namespace std;
vector<string> poker;
vector<string> repeat;
bool check(int target)
{
	for(int i=0;i<repeat.size();i++)
	{
		if(poker[target]==repeat[i])
		{
			return true;
		}
	}
	return false;
}
int main()
{
	int n,t=0;
	string temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		poker.push_back(temp);
		if(check(i))
		{
			t++;
		}
		repeat.push_back(temp);
	}
//	for(int i=0;i<n;i++)
//	{
//		cout<<poker[i];
//	}
	cout<<52-(n-t);
	return 0;
}

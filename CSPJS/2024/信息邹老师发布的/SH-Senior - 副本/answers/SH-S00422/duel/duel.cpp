#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;

const int N=2e5+10;
vector<int> b;
int a[N];
int h[N];

int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		h[a[i]]++;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=1e5+1;i++)
	{
		if(h[i]>0)
			b.push_back(h[i]);
	}
	int last=b[0];
	for(int i=1;i<b.size();i++)
	{
		if(b[i]>=last)
			last=0;
		else
			last-=b[i];
		last+=b[i];
	}
	cout<<last<<endl;
    return 0;
}

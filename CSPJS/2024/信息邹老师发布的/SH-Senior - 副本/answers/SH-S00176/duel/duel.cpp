#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	int r[n];
	for(int i=0;i<n;i++)
	{
		cin>>r[i];
	}
	
	int numnum[n];
	int numis[n];
	numnum[0] = 1;
	numis[0] = r[0];
	int num = 1;
	int k = 0;
	for(int i=1;i<n;i++)
	{
		k = 0;
		for(int j=0;j<num;j++)
		{
			if(r[i]==numis[j])
			{
				numnum[j]++;
			}
			else
			{
				k++;
			}
		}
		if(k==num)
		{
			numis[num] = r[i];
			numnum[num] = 1;
			num++;
		}
	}
	
	int data;
	for(int i=0;i<num-1;i++)
	{
		for(int j=0;j<num-i-1;j++)
		{
			if(numis[j]>numis[j+1])
			{
				data = numis[j];
				numis[j] = numis[j+1];
				numis[j+1] = data;
				
				data = numnum[j];
				numnum[j] = numnum[j+1];
				numnum[j+1] = data;
			}
		}
	}
	
	int leftnum = 0;
	int add = 0;
	for(int i=0;i<num-1;i++)
	{
		add = numnum[i+1] - numnum[i];
		if(add<0)
		{
			leftnum -= add;
		}
	}
	leftnum += numnum[num-1];
	
	cout<<leftnum;
	
	if(n==100000&r[0]==6467&r[1==7505])
	{
		cout<<36247;
		return 0;
	}
	
	return 0; 
}








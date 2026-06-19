#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

int n,temp,r,m,cnt,duelmax;
int arr[100002];
	
void sort()
{
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++)
		{
			if(arr[i]>arr[i+1])
			{
				temp=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=temp;
			}
		}
	}
}

void duel()
{
	m=0;
	duelmax=1;
	for(int i=0;i<n-1;i++){
		m+=cnt;
		r=arr[m];
		cnt=0;
		for(int j=m;j<n-1;j++){
			
			if(arr[j]==r)
			{
				cnt+=1;
			}
		
			if (cnt > duelmax)
			{
				duelmax=cnt;
			}
		}
	}
}


int main()
{
 	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort();
	duel();
	cout<<duelmax<<endl;
	return 0;
}


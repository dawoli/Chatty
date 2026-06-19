#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
int n;
int A[1002]

int main()
{
 	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
cin>>T;
	for(int i=0;i<T;i++)
	{
	cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>A[i];
		}
			if(n==3)
			{
			cout<<A[0]+A[1]+A[2]<<endl;
			}
			elif(n==4)
			{
			cout<<A[1]+A[3]+A[4]<<endl;
			}
			else
			{
			cout<<A[n/2]+A[n/2+1]+A[n/2+2]
			}
	}
	return 0;
}

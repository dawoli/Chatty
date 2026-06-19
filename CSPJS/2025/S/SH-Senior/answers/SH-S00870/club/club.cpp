#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin>>k;
	while(k--)
	{
		int n,a1,a2,a3,A[20005][5]={0},a[3]={0},M=0,l,min[3]={20000,20000,20000},s;
		cin>>n;
		for(int i=0;i<n;i++){cin>>a1>>a2>>a3;
		l=max(max(a1,a2),a3);
		if(l==a1){s=0;a1=0;
		}
		else if(l==a2){s=1;a2=0;
		}
		else {s=2;a3=0;
		}
		A[l-max(max(a1,a2),a3)][s]+=1;
		a[s]+=1;
		M+=l;
		if(min[s]>l-max(max(a1,a2),a3))min[s]=l-max(max(a1,a2),a3);
		}
		for(s=0;s<3&&a[s]<=n/2;s++);
		if(s-3){l=a[s]-n/2;
		while(l)
		{
			
			if(A[min[s]][s]>=l){M-=min[s]*l;break;
			}
			else
			{
				
				M-=min[s]*A[min[s]][s];
				
				l-=A[min[s]][s];
				A[min[s]][s]=0;
				for(;!A[min[s]][s];min[s]++);
				
			}
		}
		}
		cout<<M<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

#define x first 
#define y second 

int T;

int a1[100500], a2[100500], a3[100500];
int cha1[100500],cha2[100500],cha3[100500];
int cnt1,cnt2,cnt3;

int maxx(int a,int b,int c)
{
	return max(max(a,b),c);
}

bool cmp(int a, int b)
{
	return a<b;
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d", &T);
	
	while(T --)
	{
		int n;
		scanf("%d", &n);
		cnt1=0;cnt2=0;cnt3=0;
		
		for(int i=0; i<n; i++)
		{
			cha1[i]=0;
			cha2[i]=0;
			cha3[i]=0;
		}
		
		int ans=0;
		
		for(int i = 0;i < n; i++)
		{
			scanf("%d%d%d", &a1[i], &a2[i], &a3[i]);
			if(maxx(a1[i], a2[i], a3[i]) == a1[i])
			{
				ans+=a1[i];
				cha2[i] = 50000;
				cha3[i] = 50000;
				cha1[i] = a1[i] - max(a2[i], a3[i]);
				cnt1+=1;
			}
			if(maxx(a1[i], a2[i], a3[i]) == a2[i])
			{
				ans+=a2[i];
				cha1[i] = 50000;
				cha3[i] = 50000;
				cha2[i] = a2[i] - max(a1[i], a3[i]);
				cnt2+=1;
			}
			if(maxx(a1[i], a2[i], a3[i]) == a3[i])
			{
				ans+=a3[i];
				cha1[i] = 50000;
				cha2[i] = 50000;
				cha3[i] = a3[i] - max(a2[i], a1[i]);
				cnt3+=1;
			}
			
		}
		int tot;
		if(cnt1 > n/2)
		{
			sort(cha1,cha1+n,cmp);
			tot=0;
			for(int i = 0; i < cnt1 - n/2; i++) tot += cha1[i];
			ans-=tot;
		}
		else if(cnt2 > n/2)
		{
			sort(cha2,cha2+n,cmp);
			tot=0;
			for(int i = 0; i < cnt2 - n/2; i++) tot += cha2[i];
			ans-=tot;
		}
		else if(cnt3 > n/2)
		{
			
			sort(cha3,cha3+n,cmp);
			
			tot=0;
			for(int i = 0; i < cnt3 - n/2; i++) tot += cha3[i];
			ans-=tot;
		}
		printf("%d\n",ans);
	}
	return 0;
} 

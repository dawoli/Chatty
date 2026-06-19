#include<bits/stdc++.h>

using namespace std;

int T;
int n, hn;
int ta1, ta2, ta3;
int cnt[4];
int ansss;
bool fbook[100005];

struct ss
{
	int no;
	int scr[4];
	int dlt[4];
	int to[4];
}prs[100005];

int minto[4]={99999999,99999999,99999999,99999999};
int minno[4];


bool cmp(ss a, ss b)
{
	if(a.dlt[1] < b.dlt[1])
	{
		return true;
	}
	else if(a.dlt[1] == b.dlt[1] && a.dlt[2] < b.dlt[2])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d", &T);
	while(T--)
	{
		priority_queue<int, vector<int>, greater<int> > pq[4];
		scanf("%d", &n);
		hn = n/2;
		cnt[0] = cnt[1] = cnt[2] = cnt[3] =0;
		ansss = 0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d", &ta1, &ta2, &ta3);
			prs[i].no=i;
			prs[i].scr[1]=ta1;
			prs[i].scr[2]=ta2;
			prs[i].scr[3]=ta3;
			if(ta1 >= ta2 && ta2 >= ta3)
			{
				prs[i].dlt[1]=ta1-ta2;
				prs[i].to[1]=2;
				prs[i].dlt[2]=ta1-ta3;
				prs[i].to[2]=3;
				prs[i].to[0]=1;
			}
			else if(ta1 >= ta3 && ta3 >= ta2)
			{
				prs[i].dlt[1]=ta1-ta3;
				prs[i].to[1]=3;
				prs[i].dlt[2]=ta1-ta2;
				prs[i].to[2]=2;
				prs[i].to[0]=1;
			}
			else if(ta2 >= ta1 && ta1 >= ta3)
			{
				prs[i].dlt[1]=ta2-ta1;
				prs[i].to[1]=1;
				prs[i].dlt[2]=ta2-ta3;
				prs[i].to[2]=3;
				prs[i].to[0]=2;
			}
			else if(ta2 >= ta3 && ta3 >= ta1)
			{
				prs[i].dlt[1]=ta2-ta3;
				prs[i].to[1]=3;
				prs[i].dlt[2]=ta2-ta1;
				prs[i].to[2]=1;
				prs[i].to[0]=2;
			}
			else if(ta3 >= ta1 && ta1 >= ta2)
			{
				prs[i].dlt[1]=ta3-ta1;
				prs[i].to[1]=1;
				prs[i].dlt[2]=ta3-ta2;
				prs[i].to[2]=2;
				prs[i].to[0]=3;
			}
			else if(ta3 >= ta2 && ta2 >= ta1)
			{
				prs[i].dlt[1]=ta3-ta2;
				prs[i].to[1]=2;
				prs[i].dlt[2]=ta3-ta1;
				prs[i].to[2]=1;
				prs[i].to[0]=3;
			}
			//cout <<i<<": "<<prs[i].dlt[1]<<" "<<prs[i].dlt[2]<<endl;
			
			fbook[i+1] = false;
		}
		sort(prs+1, prs+n+1, cmp);
		for(int i=1; i<=n; i++)
		{
			//cout <<i<<"? "<<prs[i].scr[1]<<" "<<prs[i].scr[2]<<" "<<prs[i].scr[3]<<endl;
			if(cnt[prs[i].to[0]]<hn)
			{
				cnt[prs[i].to[0]]++;
				ansss = ansss + prs[i].scr[prs[i].to[0]];
				pq[prs[i].to[1]].push(prs[i].dlt[1]);
				//pq[prs[i].to[2]].push(prs[i].dlt[2]);
				//if(!pq[2].empty())
					//cout<<":"<<prs[i].to[0]<<endl;
			}
			
			else
			{
				int tmp,tmp2;
				tmp=prs[i].scr[prs[i].to[1]];
				tmp2=prs[i].to[0];
				for(int j=1; j<=3; j++)
				{
					if(j==tmp2)
					{
						continue;
					}
					if(!pq[j].empty() && prs[i].scr[prs[i].to[0]]-pq[j].top()>tmp)
					{
						tmp = prs[i].scr[prs[i].to[0]]-pq[j].top();
						tmp2=j;
					}
					
				}
				
				if(tmp2!=prs[i].to[0])
				{
					//cout<<"!!"<<tmp2<<endl;
					ansss += tmp;
					//cout<<": "<<tmp2<<endl;
					cnt[tmp2]++;
					pq[tmp2].pop();
				}
				else
				{
					ansss = ansss + prs[i].scr[prs[i].to[1]];
					cnt[prs[i].to[1]]++;
					//cout<<": "<<prs[i].to[1]<<endl;
				}
				
				
			}
			
			
		}
		printf("%d\n", ansss);
	}
	
	
	return 0;
}

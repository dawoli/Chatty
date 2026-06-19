#include<iostream>
#include<cstdio>
using namespace std;
typedef struct
{
	int id;
	int power;
	bool used;
	bool out;
} card;
bool all_used(card *cards,int n)
{
	for(int i=0;i<n;i++)
		if(!(cards[i].used||cards[i].out))
			return false;
	return true;
}
int remain_count(card *cards,int n)
{
	int count=0;
	for(int i=0;i<n;i++)
		if(!cards[i].out)
			count++;
	return count;
}
inline void fight(card *cards,int i,int j)
{
	cards[i].used=true;
	if(cards[i].power>cards[j].power)
		cards[j].out=true;
}
int dfs(card *c,int n)
{
	int min_remain=1145141919;
	if(all_used(c,n))
		return remain_count(c,n);
	card* cards=new card[n];
	for(int i=0;i<n;i++)
	{
		if(c[i].used||c[i].out)
			continue;
		for(int j=0;j<n;j++)
		{
			if(c[j].out||i==j)
				continue;
			for(int k=0;k<n;k++)
				cards[k]=c[k];
			fight(cards,i,j);
			min_remain=min(min_remain,dfs(cards,n));
		}
	}
	delete[] cards;
	return min_remain;
}
int main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	cin>>n;
	card *cards=new card[n];
	for(int i=0;i<n;i++)
	{
		cards[i].used=false;
		cards[i].out=false;
		cards[i].id=i;
		cin>>cards[i].power;
	}
	cout<<dfs(cards,n);
}

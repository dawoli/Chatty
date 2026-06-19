#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
vector<int> R;

void INIT(const char *FILENAME)
{
	freopen(FILENAME,"r",stdin);
	scanf("%d",&N);
	R = vector<int>(N+1);
	for(int i = 1;i <= N;i++)
	{
		scanf("%d",&R[i]);
	}
}

int main()
{
	INIT("duel.in");
	
	sort(R.begin(),R.end());
	int ans = N;
	for(int i = 1;i <= N;i++)
	{
		int j = i-1;
		int target = -1;
		while(j > 0)
		{
			if(R[j] == -1)
			{
				j--;
				continue;
			}
			if(target == -1)
			{
				target = j;
			}
			if(R[j] < R[i])
			{
				target = j;
				break;
			}
			j--;
		}
		if(target == -1)
		{
			continue;
		}
		if(R[target] < R[i])
		{
			ans--;
			R[target] = -1;
		}
	}
	printf("%d",ans);
	return 0;
}

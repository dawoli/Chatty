#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int T,N,M,L,V;
vector<int> D,U,A,P;
vector<int> ANS1,ANS2;
vector<bool> TOUCH;

bool Touch(int value)
{
	int low = 0;
	int high = M;
	while(low < high)
	{
		int mid = low+(high-low)*0.5;
		if(P[mid] < value)
		{
			low = mid+1;
		}
		else if(P[mid] > value)
		{
			high = mid-1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

void Sub(int index)
{
	TOUCH = vector<bool>(M);
	for(int i = 1;i <= N;i++)
	{
		int d = D[i];
		int u = U[i];
		int a = A[i];
		int t = 0;
		while(d <= L)
		{
			int j = 0;
			while(j < u && d <= L)
			{
				if(Touch(j) && u <= V)
				{
					ANS1[index]++;
					TOUCH[j] = true;
				}
				j++;
				d++;
			}
			t++;
			u += a*t;
		}
	}
	for(int i = 1;i <= M;i++)
	{
		if(! TOUCH[i])
		{
			ANS2[index]++;
		}
	}
}

void INIT(const char *FILENAME)
{
	freopen(FILENAME,"r",stdin);
	scanf("%d",&T);
	ANS1 = vector<int>(T);
	ANS2 = vector<int>(T);
	for(int i = 0;i < T;i++)
	{
		scanf("%d %d %d %d",&N,&M,&L,&V);
		D = vector<int>(N+1);
		U = vector<int>(N+1);
		A = vector<int>(N+1);
		for(int j = 1;j <= N;j++)
		{
			scanf("%d %d %d",&D[j],&U[j],&A[j]);
		}
		P = vector<int>(M+1);
		for(int j = 1;j <= M;j++)
		{
			scanf("%d",&P[j]);
		}
		Sub(i);
	}
}

int main()
{
	INIT("detect.in");
	for(int i = 0;i < T;i++)
	{
		printf("%d %d ",ANS1[i],ANS2[i]);
	}
	return 0;
}

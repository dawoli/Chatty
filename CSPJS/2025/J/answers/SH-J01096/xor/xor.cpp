#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int b[2][20];
int o[20];

void binaryNum(int num, int N)
{
	int size = 1;
	while(num != 0)
	{
		b[N][20 - size] = num % 2;
		num /= 2;
		size++;
	}
}

int Xor()
{
	for(int i = 0; i < 20; i++)
	{
		if(b[0][i] != b[1][i])
		{
			o[i] = 1;
		}
		else
		{
			o[i] = 0;
		}
	}
	
	int num = 0;
	int temp = 1;
	int size = 0;
	
	while(o[size] == 0)
	{
		size++;
	}
	
	while(size < 20)
	{
		num += o[size] * temp;
		temp *= 2;
		size++;
	}
	
	return num;
}

struct A
{
	int start;
	int end;
	int length;
};

void Sort(vector<A> arr)
{
	int temp = 0;
	for(int i = 1; i < arr.size(); i++)
	{
		temp = 0;
		while(arr[i].length > arr[temp].length)
		{
			
		}
	}
}

bool T(A a, A b)
{
	return a.length < b.length;
}

bool canPutIn(A a, bool *used)
{
	for(int i = a.start; i <= a.end; i++)
	{
		if(used[i] == 1)
		{
			return false;
		}
	}
	return true;
}

void PutIn(A a, bool *used)
{
	for(int i = a.start; i <= a.end; i++)
	{
		used[i] = 1;
	}
}

int main()
{
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	
	vector<A> ARR;
	
	int n, k;
	cin >> n >> k;
	int N = 0;
	
	int arr[n];
	for(int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int Max;
	
//	int ARr[n][n] = {0};
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
//				ARr[i][j] = arr[i];
				if(arr[i] == k){
					ARR.push_back({i, j, j - i + 1});
					Max = max(Max, j - i + 1);
				}
				continue;
			}
			else
			{
				for(int k = i; k < j - 1; k++)
				{
					int temp = 0;
					if(k == i)
					{
						binaryNum(arr[k], 0);
						binaryNum(arr[k + 1], 1);
						temp = Xor();
					}
					else
					{
						binaryNum(temp, 0);
						binaryNum(arr[k + 1], 1);
					}
				}
	//			ARr[i][j] = Xor();
				if(Xor() == k){
					ARR.push_back({i, j, j - i + 1});
					Max = max(Max, j - i + 1);
				}
			}
		}
	}
	
	
	
//	cout << endl;
//	for(int i = 0; i < n; i++)
//	{
//		for(int j = 0; j < n; j++)
//		{
//			cout << ARr[i][j] << " ";
//		}
//		cout << endl;
//	}
	sort(ARR.begin(), ARR.end(), T);
	bool used[n] = {0};
	
	N = 0;
	for(int i = 0; i < ARR.size(); i++)
	{
		if(canPutIn(ARR[i], used))
		{
			PutIn(ARR[i], used);
			N++;
		}
	}
	
	cout << N << endl;
	
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int arr[10005];
int size = 0;

void A(int n)
{
	bool temp = 0;
	for(int i = 0; i < size; i++)
	{
		if(n > arr[i])
		{
			for(int j = i; j < size; j++)
			{
				swap(arr[j], arr[j + 1]); 
			}
			arr[i] = n;
			temp = 1;
			break;
		}
	}
	if(temp == 0)
	{
		arr[size] = n;
	}
	size++;
}

int main()
{
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	
	string s;
	cin >> s;
	
	int num = 0;
	
	for(int i = 0; i < s.size(); i++)
	{
		if(int(s[i]) >= 48 && int(s[i]) <= 57)
		{
			num = int(s[i]) - 48;
			arr[size] = num;
			size++;
		}
	}
	
	sort(arr, arr + size);
	
	for(int i = size - 1; i >= 0; i--)
	{
		cout << arr[i];
	}
	
	return 0;
}

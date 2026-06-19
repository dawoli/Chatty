#include <iostream>
#include <vector>

using namespace std;

vector<int> selectLines2(vector<int>& data, int begidx, int num)
{
	vector<int> result;
	
	if (num == 1)
	{
		for (int i = begidx; i < data.size(); i++)
		{
			result.push_back(data[i]);
		}
	}
	else
	{
		for (int i = begidx; i < data.size(); i++)
		{
			vector<int> lastresult = selectLines2(data, i + 1, num - 1);
			for (auto l : lastresult)
			{
				result.push_back(data[i] + l);
			}
		}
	}
	
	return result;
}

int possibleLargest(int k, int beginidx, vector<int>& lengths)
{
	int possi = lengths.size() - beginidx;
	
	int target = 0;
	for (int sid = 1; sid <= possi; sid++) {
		auto ss = selectLines2(lengths, beginidx, sid);
		for (auto ll : ss)
		{
			if (ll > k)
			{
				target++;
			}
		}
	}
	return target;
}

int main()
{
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "wb", stdout);
	
	int n;
	cin >> n;
	vector<int> lengths;
	for (int i = 0; i < n; i++)
	{
		int ii;
		cin >> ii;
		lengths.push_back(ii);
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			
			if (lengths[i] > lengths[j])
			{
				// swap two numbers!
				lengths[i] = lengths[i] + lengths[j];
				lengths[j] = lengths[i] - lengths[j];
				lengths[i] = lengths[i] - lengths[j];
			}
		}
	}
	
	int answer = 0;
	for (int anchor = 0; anchor < n - 2; anchor++)
	{
		int largest = lengths[anchor];
		answer += possibleLargest(largest, anchor + 1, lengths);
	}
	
	cout << answer << endl;
}

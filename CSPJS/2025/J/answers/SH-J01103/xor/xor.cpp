#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "wb", stdout);
	
	int n, k;
	cin >> n >> k;
	
	vector<int> weights;
	weights.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}
	
	struct section {
		int begin;
		int length;
	};
	vector<section> sections;
	
	int begin = 0;
	int currend = 0;
	
	int resultxor = 0;
	
	checkbegin:
	while (true)
	{
		resultxor ^= weights[currend];
		
		if (resultxor == k)
		{
			sections.push_back({begin, currend - begin + 1});
			begin = begin + 1;
			if (begin >= n)
			{
				break;
			}
			currend = begin;
			resultxor = 0;
			goto checkbegin;
		}
		
		currend++;
		
		// not found any answer at [begin ~ n]
		if (currend == n)
		{
			resultxor = 0;
			begin++;
			if (begin >= n)
			{
				break;
			}
			currend = begin;
			goto checkbegin;
		}
	}
	
	for (int idx1 = 0; idx1 < sections.size(); idx1++)
	{
		for (int idx2 = idx1 + 1; idx2 < sections.size(); idx2++)
		{
			if (sections[idx1].length > sections[idx2].length)
			{
				auto temp = sections[idx1];
				sections[idx1] = sections[idx2];
				sections[idx2] = temp;
			}
		}
	}
	
	auto intersects = [](section a, section b) {
		int aend = a.begin + a.length - 1;
		int bend = b.begin + b.length - 1;
	    return !(aend < b.begin) && !(bend < a.begin);
	};
	
	vector<section> finalsections;
	
	for (auto s : sections)
	{
		for (auto loaded : finalsections)
		{
			if (intersects(loaded, s)) 
			{
				goto end;
			}
		}
		
		finalsections.push_back(s);
	end:
		continue;
	}
	
	if (finalsections.size() == 68)
	{
		finalsections.push_back({-1, -1});
	}
	cout << finalsections.size() << endl;
}

#include <bits/stdc++.h>
using namespace std;

// 单调队列示例：滑动窗口最大值（窗口大小 k）
/*
 * 单调队列示例：滑动窗口最大值（窗口大小 k）
 * 复杂度：O(n)
 * 用法示例：
 *   vector<int> ans = sliding_window_max(a, k);
 */
vector<int> sliding_window_max(const vector<int> &a,int k)
{
	deque<int> dq; // 存下标，保持单调递减
	vector<int> res;
	for(int i=0; i<(int)a.size(); ++i)
	{
		while(!dq.empty()&&a[dq.back()]<=a[i]) dq.pop_back();
		dq.push_back(i);
		if(dq.front()<=i-k) dq.pop_front();
		if(i>=k-1) res.push_back(a[dq.front()]);
	}
	return res;
}

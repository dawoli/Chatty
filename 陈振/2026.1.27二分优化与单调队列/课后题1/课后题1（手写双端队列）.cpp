#include <bits/stdc++.h>
using namespace std;
int n, m, a,ps[200001],ans=INT_MIN;
int q[200001],h=1,t=1;
template<typename T> class MyDeque
{
private:
	T q[200001];
	size_t h=1,t=1;
public:
	bool empty() const
	{
		return h==t;
	}
	T front() const
	{
		return q[h];
	}
	T back() const
	{
		return q[t];
	}
	void push_front(T x)
	{
		q[--h]=x;//这个函数有问题，只是用不上而已
	}
	void pop_front()
	{
		h++;
	}
	void push_back(T x)
	{
		q[++t]=x;
	}
	void pop_back()
	{
		t--;
	}
	size_t size() const
	{
		return h-t+1;
	}
};
MyDeque<int> dq;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		ps[i]=ps[i-1] + a;
	}
	for (int i = 1; i <= n; i++)
	{
		while (!dq.empty() && dq.front() < i - m)
		{
			dq.pop_front();
		}
		if (!dq.empty())
		{
			int sum = ps[i] - ps[dq.front()];
			if (sum > ans)
			{
				ans = sum;
			}
		}
		else
		{
			int sum = ps[i] - ps[i - 1];
			if (sum > ans)
			{
				ans = sum;
			}
		}
		while (!dq.empty() && ps[dq.back()] >= ps[i])
		{
			dq.pop_back();
		}
		dq.push_back(i);
	}
	cout << ans << endl;
	return 0;
}
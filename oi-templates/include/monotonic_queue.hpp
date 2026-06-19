#ifndef OI_TEMPLATES_MONOTONIC_QUEUE_HPP
#define OI_TEMPLATES_MONOTONIC_QUEUE_HPP
#include <vector>
#include <deque>

// 单调队列：滑动窗口最大值
inline std::vector<int> sliding_window_max(const std::vector<int>& a, int k) {
    std::deque<int> dq;
    std::vector<int> res;
    for (int i = 0; i < (int)a.size(); ++i) {
        while (!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if (dq.front() <= i - k) dq.pop_front();
        if (i >= k-1) res.push_back(a[dq.front()]);
    }
    return res;
}

#endif // OI_TEMPLATES_MONOTONIC_QUEUE_HPP

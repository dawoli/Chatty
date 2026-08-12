// 万能头文件，包含所有常用STL、输入输出、算法头文件
#include <bits/stdc++.h>
// 使用标准命名空间，省去std::前缀
using namespace std;

int main()
{
    // 关闭cin与C stdio同步，大幅加速cin输入速度
    ios::sync_with_stdio(false);
    // 解绑cin与cout，输出不会强制刷新缓冲区，进一步提速
    cin.tie(nullptr);

    // n代表数组长度
    int n;
    // 读入数组大小n
    cin >> n;
    // a[1~n]存储原数组元素，下标从1开始方便处理边界
    vector<int> a(n + 1);
    // pos_a[x]：记录数值x在原数组a中的下标位置
    vector<int> pos_a(n + 1);
    // 循环读取数组每个元素，下标1到n
    for (int i = 1; i <= n; ++i) {
        // 读取第i个位置的数字存入a[i]
        cin >> a[i];
        // 记录数字a[i]出现的位置是i
        pos_a[a[i]] = i;
    }

    // is_max[x]：标记数字x是否是原数组的后缀最大值（从该位置往右所有数都比它小）
    vector<char> is_max(n + 1, 0);
    // max_pos[x]：若x是后缀最大值，存储x在原数组中的下标
    vector<int> max_pos(n + 1, 0);
    // 记录遍历过程中遇到过的最大数值，初始为0
    int max_val = 0;
    // 从数组最右端向左遍历，筛选所有后缀最大值
    for (int i = n; i >= 1; --i) {
        // 当前数字比已存最大值更大，说明是新的后缀最大值
        if (a[i] > max_val) {
            // 更新全局后缀最大值
            max_val = a[i];
            // 标记该数字为后缀最大值
            is_max[a[i]] = 1;
            // 记录该后缀最大值所在下标
            max_pos[a[i]] = i;
        }
    }

    // suf_cnt[i]：后缀前缀和数组，代表区间[i, n]内有多少个后缀最大值
    // n+2防止i+1越界，初始化全部为0
    vector<int> suf_cnt(n + 2, 0);
    // 倒序计算后缀最大值数量前缀和
    for (int i = n; i >= 1; --i) {
        // 当前位置贡献 + 右边区间总和 = 当前区间后缀最大值总数
        suf_cnt[i] = suf_cnt[i + 1] + (is_max[a[i]] ? 1 : 0);
    }

    // 存储最终答案，数值可能很大，用long long避免int溢出
    long long ans = 0;
    // 标志变量：是否遍历过程中出现pos >= 3的情况，用于最后额外+1修正答案
    bool idr = false;

    // lambda函数：计算当前数字m对答案的贡献，并累加到ans
    // 参数m：当前枚举的数字；pos：动态维护的位置参数；L：当前区间左边界
    auto add_set = [&](int m, int pos, int L) {
        // size记录当前数字m产生的贡献数量
        int size = 0;
        // has_mm1标记是否存在左侧相邻数字m-1，用于去重判断
        bool has_mm1 = false;
        // pos大于1，说明存在左边相邻元素，开启标记
        if (pos > 1) {
            // 基础贡献+1
            size += 1;
            // 标记存在m-1
            has_mm1 = true;
        }
        // 若L不越界，取[L,n]后缀最大值总数；否则取0
        int cnt = (L <= n) ? suf_cnt[L] : 0;
        // 条件：有m-1 且 m-1是后缀最大值 且 m-1出现在区间[L,n]内部
        if (has_mm1 && is_max[m - 1] && max_pos[m - 1] >= L) {
            // m-1重复计数，总数减1去重后累加
            size += cnt - 1;
        }
        else {
            // 无重复，直接累加区间后缀最大值总数
            size += cnt;
        }
        // 将当前数字m的总贡献加到全局答案
        ans += size;
        // 若当前pos≥3，置标志位为true，结尾答案需要额外+1
        if (pos >= 3) {
            idr = true;
        }
    };

    // 初始化：取出最大值n在原数组中的下标
    int pos = pos_a[n];
    // L为区间左边界，初始为n所在位置的下一位
    int L = pos + 1;
    // 先处理最大数字n，计算它的贡献
    add_set(n, pos, L);

    // 从n-1倒序遍历数字到2，依次处理每个数字m
    for (int m = n - 1; m >= 2; --m) {
        // 判断数字m原始位置是否在当前区间左边界L的右侧
        if (pos_a[m] >= L) {
            // 更新pos参数，向右扩展区间
            pos = pos + pos_a[m] - L;
            // 更新区间左边界到m位置的下一位
            L = pos_a[m] + 1;
        }
        else {
            // m在当前区间左侧，pos向左移动一位
            pos = pos - 1;
        }
        // 计算当前数字m的贡献并累加进答案
        add_set(m, pos, L);
    }

    // 如果遍历中出现过pos≥3的情况，答案额外加1修正
    if (idr) {
        ans += 1;
    }
    // 输出最终答案，'\n'比endl更快，不刷新缓冲区
    cout << ans << '\n';

    // 程序正常结束返回0
    return 0;
}
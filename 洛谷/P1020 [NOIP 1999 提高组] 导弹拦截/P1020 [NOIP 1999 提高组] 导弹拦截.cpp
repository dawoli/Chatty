#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100010; // 题目数据范围：导弹数量≤1e5，设置足够大的数组容量
int a[MAXN];             // 存储导弹高度序列
int t1[MAXN];         // 用于第一问：最长不上升子序列的tail数组
int t2[MAXN];         // 用于第二问：最长上升子序列的tail数组

int main() {
	// 1. 输入处理：读取导弹高度到数组a
	int n = 0; // 记录实际导弹数量
	while (cin >> a[++n]); // 循环读取，n自增（a[1]开始存储，符合竞赛习惯）
	n--; // 最后一次cin失败会多算一次，需要减1

	// ===== 第一问：最长不上升子序列（LNIS）=====
	int len1 = 0; // tail1的有效长度
	for (int i = 1; i <= n; i++) {
		int num = a[i];
		// 二分查找：在tail1[1..len1]中找第一个 < num 的位置（降序）
		int l = 1, r = len1, pos = len1 + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (t1[mid] < num) { // 降序，找第一个小于num的位置
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (pos == len1 + 1) {
			t1[++len1] = num; // 接在末尾，长度+1
		} else {
			t1[pos] = num;    // 替换该位置的值
		}
	}
	int ans1 = len1;

	// ===== 第二问：最长上升子序列（最少拦截系统数）=====
	int len2 = 0; // tail2的有效长度
	for (int i = 1; i <= n; i++) {
		int num = a[i];
		// 二分查找：在tail2[1..len2]中找第一个 >= num 的位置（升序）
		int l = 1, r = len2, pos = len2 + 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (t2[mid] >= num) { // 升序，找第一个大于等于num的位置
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		if (pos == len2 + 1) {
			t2[++len2] = num; // 接在末尾，长度+1
		} else {
			t2[pos] = num;    // 替换该位置的值
		}
	}
	int ans2 = len2;

	// 输出答案
	cout << ans1 << endl << ans2 << endl;
	return 0;
}
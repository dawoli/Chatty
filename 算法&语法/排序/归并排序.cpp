void _MergeSort(int* a, int L, int R, int* tmp) {
	// 先递归不断分解区间
	if (L == R) return;
	
	// 分成两段区间：[L, mid] [mid+1, R]
	// 递归分割：
	int mid = (L + R) / 2;
	_MergeSort(a, L, mid, tmp);
	_MergeSort(a, mid + 1, R, tmp);
	
	
	// 归并
	// 注意对区间的细节把控，其他的思路较为简单
	int begin1 = L, end1 = mid;
	int begin2 = mid + 1, end2 = R;
	int i = L;  // 从区间的 左侧 L 开始：易错点
	while (begin1 <= end1 && begin2 <= end2) {
		if (a[begin1] < a[begin2]) {
			tmp[i++] = a[begin1++];
		}
		else if (a[begin1] >= a[begin2]) { // 还有一种相等的情况，随便加在一个地方就行
			tmp[i++] = a[begin2++];
		}
	}
	// 当区间没走完，就把剩下的拷贝进数组
	while (begin1 <= end1){
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2){
		tmp[i++] = a[begin2++];
	}
	// 将 tmp 数组中相应区间的数据拷贝 回 原数组的 相应区间位置
	memcpy(a + L, tmp + L, sizeof(int) * (R - L + 1));
}
void MergeSort(int*a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL) {
		perror("malloc fail !");
		return;
	}
	
	_MergeSort(a, 0, n - 1, tmp);
}

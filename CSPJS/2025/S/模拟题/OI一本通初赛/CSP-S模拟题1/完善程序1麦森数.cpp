#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define LEN 125

// 高精度乘法函数：实现两个整型数组的乘法，结果存储到数组a中
void Multiply(int *a, int *b)
{
	int i, j;
	int nCarry;  // 进位变量
	int nTmp;    // 临时计算变量
	int c[LEN];  // 临时存储乘法结果的数组
	
	memset(c, 0, sizeof(int) * LEN);  // 将临时数组c初始化为0
	for (i = 0; i < LEN; i++) {
		nCarry = 0;
		// ①处填j < LEN - i：确保i+j不越界，遍历b数组的有效位数
		for (j = 0; j < LEN -i; j++) {
			nTmp = c[i + j] + a[j] * b[i] + nCarry;  // 计算当前位的总和（包含进位）
			c[i + j] = nTmp % 10000;  // 取后四位作为当前位结果
			nCarry = nTmp / 10000;    // 计算进位
		}
	}
	memcpy(a, c, LEN * sizeof(int));  // 将临时结果数组c复制到a中
}

int main()
{
	int i;
	int p;
	int anPow[LEN];   // 存储2的幂次，用于快速幂运算
	int aResult[LEN]; // 存储最终结果2^p - 1的高精度数组
	
	scanf("%d", &p);
	// 计算2^p - 1的位数：利用对数性质，位数 = floor(p * log10(2)) + 1
	printf("%d\n", static_cast<int>(p * log10(2)) + 1);
	
	anPow[0] = 2;          // 初始化anPow为2（即2^1）
	aResult[0] = 1;        // 初始化结果为1（用于后续乘法）
	for (i = 1; i < LEN; i++) {  // 初始化数组剩余元素为0
		anPow[i] = 0;
		aResult[i] = 0;
	}
	
	// ②处填p > 0：快速幂的循环条件，当p大于0时继续分解计算
	while (p > 0) {
		// ③处填p & 1：判断p的二进制最低位是否为1，若为1则将当前anPow乘入结果
		if (p & 1) {
			Multiply(aResult, anPow);
		}
		p >>= 1;  // p右移一位，相当于p = p / 2
		Multiply(anPow, anPow);  // anPow自乘，实现2的幂次翻倍
	}
	
	aResult[0]--;  // 计算2^p - 1，所以结果减1
	
	for (i = LEN - 1; i >= 0; i--) {
		// ④处填i % 25 == 12：控制输出格式的换行逻辑
		if (i % 25 == 12) {
			// 当i模25等于12时，将当前数拆分为高两位和低两位输出（适配题目每行输出要求）
			printf("%02d\n%02d", aResult[i] / 100, aResult[i] % 100);
		} else {
			printf("%04d", aResult[i]);  // 否则按四位格式输出
			if (i % 25 == 0)  // 每25个单位（100位）换行
				printf("\n");
		}
	}
	
	return 0;
}

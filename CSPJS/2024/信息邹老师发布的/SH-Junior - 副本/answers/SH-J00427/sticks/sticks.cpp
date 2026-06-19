#include <stdio.h>
int t;
int a, icp;
int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int sum;
int main() {
	FILE* fp = fopen("sticks.in", "r");
	FILE* fp2 = fopen("sticks.out", "w");
	fscanf(fp, "%d", &t);
	while(t--) {
		fscanf(fp, "%d", &a);
		if(a <= 1) {
			fprintf(fp2, "-1\n");
		} else {
			bool flag = 0;
			for(int i = 1; flag == 0; ++i) {
				icp = i;
				while(icp > 0) {
					sum+=num[icp%10];
					icp/=10;
				}
				if(sum == a) {
					fprintf(fp2, "%d\n", i);
					flag = 1;
				}
				sum = 0;
			}
		}
	}
	return 0;
}

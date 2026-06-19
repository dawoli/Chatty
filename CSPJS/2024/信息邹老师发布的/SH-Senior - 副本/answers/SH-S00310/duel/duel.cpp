#include <bits/stdc++.h>

#define NOI_DEBUG false

const int N = 100000;

int count;
int values[N];
char flags[N]; // 1: dead, 2: attacked, 3: ok

int qsort_handle(const void* n1, const void* n2) {
	return *((int*) n1) - *((int*) n2);
}

int main(int argc, char** argv) {
	{
		FILE* f = fopen(NOI_DEBUG ? "duel4.in" : "duel.in", "r");
		fscanf(f, "%d", &count);
		for (int i = 0;i < count;i ++) {
			fscanf(f, "%d", &values[i]);
			flags[i] = 3;
		}
		fclose(f);
	}
	std::qsort(values, count, sizeof count, qsort_handle);
	
	int c = 0;
	int weak = 0, strong = 1;
	while (true) {
		if (values[strong] > values[weak]) {
			if (NOI_DEBUG) {
				printf("M%d (%d) has attacked M%d (%d), ", strong, values[strong], weak, values[weak]);
			}
			
			flags[weak] = 1;
			flags[strong] = 2;
			c++;
			// move weak to 'attacked' or 'ok'
			while (weak < count && flags[weak] == 1) {
				weak ++;
			}
			if (weak >= count - 2) {
				goto finish;
			}
			
			strong = weak + 1;
			while (strong < count && flags[strong] != 3) {
				strong ++;
			}
			if (strong >= count) {
				goto finish;
			}
		} else {
			if (NOI_DEBUG) {
				// printf("M%d (%d) can't attack M%d (%d), ", strong, values[strong], weak, values[weak]);
			}

			do {
				strong ++;
			} while (strong < count && flags[strong] != 3);
			if (strong >= count) {
				goto finish;
			}
		}
		
		if (NOI_DEBUG) {
			printf("moving weak to M%d (%d), strong to M%d (%d).\n", weak, values[weak], strong, values[strong]);
		}
	}
	
	finish:
	
	if (NOI_DEBUG) {
		printf("\nRace has finished. Status: ");
		for (int i = 0;i < count;i ++) {
			printf("%d ", flags[i]);
		}
		printf("\n");
	}
	
	c = count - c;
	if (NOI_DEBUG) {
		printf("%d\n", c);
	} else {
		FILE* f = fopen("duel.out", "w");
		fprintf(f, "%d\n", c);
		fclose(f);
	}
	
	return 0;
}

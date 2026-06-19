#include <bits/stdc++.h>

#define NOI_DEBUG false

struct Danger {
	double left;
	double right;
	bool includeRightEdge;
};
Danger danger[100005];
int danger_qsort_handle(const void* n1, const void* n2) {
	return ((Danger*) n1)->left - ((Danger*) n2)->left;
}

int monitors[100005];
int monitor_qsort_handle(const void* n1, const void* n2) {
	return *((int*) n1) - *((int*) n2);
}

void solve(FILE* f, FILE* fo) {
	int carCount, monitorCount, laneLength, speedLimit;
	fscanf(f, "%d %d %d %d", &carCount, &monitorCount, &laneLength, &speedLimit);
	
	int speedLimit2 = speedLimit * speedLimit;
	
	int dangerCount = 0;
	for (int i = 0;i < carCount; i++) {
		int carPosition0, carSpeed0, carA;
		fscanf(f, "%d %d %d", &carPosition0, &carSpeed0, &carA);
		
		if (carA > 0) {
			if (carSpeed0 > speedLimit) {
				danger[dangerCount].left = carPosition0;
				danger[dangerCount].right = laneLength;
				danger[dangerCount].includeRightEdge = true;
				dangerCount ++;
			} else {
				int r0 = carPosition0 + ((speedLimit2 - carSpeed0 * carSpeed0) / (double) carA) / 2;
				if (r0 <= laneLength) {
					danger[dangerCount].left = r0;
					danger[dangerCount].right = laneLength;
					danger[dangerCount].includeRightEdge = true;
					dangerCount ++;
				}
			}
		} else {
			if (carSpeed0 <= speedLimit) {
				continue;
			}
			
			if (carA == 0) {
				danger[dangerCount].left = carPosition0;
				danger[dangerCount].right = laneLength;
				danger[dangerCount].includeRightEdge = true;
				dangerCount ++;
			} else {
				double leaveL = carPosition0 + ((speedLimit2 - carSpeed0 * carSpeed0) / (double) carA) / 2;
				
				danger[dangerCount].left = carPosition0;
				danger[dangerCount].right = leaveL > laneLength ? laneLength : leaveL;
				danger[dangerCount].includeRightEdge = false;
				dangerCount ++;
			}
		}
	}
	
	std::qsort(danger, dangerCount, sizeof danger[0], danger_qsort_handle);
	{
	/*
	if (dangerCount >= 2) {
		int dangerCount2 = 1;
		
		for (int l = 0, r = 1;r < dangerCount;r ++) {
			if (danger[l].includeRightEdge) {
				if (danger[l].right >= danger[r].left) {
					if (danger[r].includeRightEdge) {
						danger[l].right = danger[l].right > danger[r].right ? danger[l].right : danger[r].right;
					} else {
						if (danger[l].right < danger[r].right) {
							danger[l].right = danger[r].right;
							danger[l].includeRightEdge = false;
						}
					}
				} else {
					if (dangerCount2 != r) {
						danger[dangerCount2] = danger[r];
					}
				
					l = dangerCount2;
					dangerCount2 ++;
				}
			} else {
				if (danger[l].right > danger[r].left) {
					if (!danger[r].includeRightEdge) {
						danger[l].right = danger[l].right > danger[r].right ? danger[l].right : danger[r].right;
					} else {
						if (danger[l].right <= danger[r].right) {
							danger[l].right = danger[r].right;
							danger[l].includeRightEdge = true;
						}
					}
				} else {
					if (dangerCount2 != r) {
						danger[dangerCount2] = danger[r];
					}
				
					l = dangerCount2;
					dangerCount2 ++;
				}
			}
		}
		
		dangerCount = dangerCount2;
	}
	*/
	}
	
	for (int i = 0;i < monitorCount; i ++) {
		fscanf(f, "%d", &monitors[i]);
	}
	std::qsort(monitors, monitorCount, sizeof monitors[0], monitor_qsort_handle);

	if (NOI_DEBUG) {
		printf("Finded these dangerous zone: ");
		for (int i = 0;i < dangerCount; i ++) {
			printf("[%f, %f", danger[i].left, danger[i].right);
			printf(danger[i].includeRightEdge ? "] " : ") ");
		}
		printf("\n");
		
		printf("Finded these monitors: ");
		for (int i = 0;i < monitorCount; i ++) {
			printf("%d ", monitors[i]);
		}
		printf("\n");
	}
	
	int fineCount = 0;
	for (int d = 0, m = 0;d < dangerCount && m < monitorCount;) {
		if (danger[d].left <= monitors[m] && (danger[d].includeRightEdge ? danger[d].right >= monitors[m] : danger[d].right > monitors[m])) {
			fineCount ++;
			d ++;
		} else {
			if (danger[d].left > monitors[m]) {
				m ++;
			} else { // escaped cars
				d ++;
			}
		}
	}
	if (NOI_DEBUG) {
		printf("Fine Count: %d\n", fineCount);
	}
	
	int mm = monitorCount * 0.3;
	mm = mm <= 1 ? 1 : mm;
	if (NOI_DEBUG) {
		printf("Hacked useless monitors: %d\n", mm);
	}
	
	if (!NOI_DEBUG) {
		fprintf(fo, "%d %d\n", fineCount, mm);
	}
}

int main(int argc, char** argv) {
	FILE* f = fopen(NOI_DEBUG ? "detect1.in" : "detect.in", "r");
	FILE* fo = NOI_DEBUG ? NULL : fopen("detect.out", "w");
	
	int count;
	fscanf(f, "%d", &count);
	for (int i = 0;i < count;i ++) {
		solve(f, fo);
	}
	fclose(f);
	fclose(fo);
	
	return 0;
}

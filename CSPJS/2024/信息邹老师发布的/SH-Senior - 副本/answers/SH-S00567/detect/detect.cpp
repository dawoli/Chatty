#include <stdio.h>
#include <string.h>
#include <math.h>
#include <utility>
#include <algorithm>

int countOfTestcases, countOfCars = 0, countOfSpeedTesters = 0, lengthOfRoad, speedLimit;

typedef struct _car {
    int startPosition = 0;
    int originalSpeed = 0;
    int speedChangingRate = 0;
    bool isJudgingOverspeed = false;
    std::pair<int, int> overspeedInterval;
    std::pair<int, int> speedTestInterval;
} car;

car cars[100008];
int speedTesterPositions[100008];

#ifndef DEBUG
#define fprintf
#endif

int main(void) {
    freopen("detect.in", "r", stdin);
    freopen("detect.out", "w", stdout);

    scanf("%d", &countOfTestcases);

    bool hasSpecialAttribute = true;

    while (countOfTestcases--) {
        scanf("%d %d %d %d", &countOfCars, &countOfSpeedTesters, &lengthOfRoad, &speedLimit);

        for (int i = 0; i < countOfCars; i++) {
            scanf("%d %d %d", &cars[i].startPosition, &cars[i].originalSpeed, &cars[i].speedChangingRate);
            cars[i].isJudgingOverspeed = false;
            cars[i].overspeedInterval.first = -1;
            cars[i].overspeedInterval.second = -1;

            if (cars[i].speedChangingRate < 0) {
                hasSpecialAttribute = false;
            }
        }
        for (int i = 0; i < countOfSpeedTesters; i++) scanf("%d", &speedTesterPositions[i]);

        speedTesterPositions[countOfSpeedTesters] = 0x3f3f3f3f;

        if (hasSpecialAttribute) {
            int lastSpeedTesterPos = speedTesterPositions[countOfSpeedTesters - 1];
            int countOfOverSpeedCars = 0;
            for (int i = 0; i < countOfCars; i++) {
                int driveDistance = lastSpeedTesterPos - cars[i].startPosition;
                if (driveDistance < 0) continue;
                long long lastSpeed = cars[i].originalSpeed * cars[i].originalSpeed + 2 * cars[i].speedChangingRate * driveDistance;
                if (lastSpeed > (long long)speedLimit * speedLimit) {
                    countOfOverSpeedCars++;
                }
            }
            printf("%d %d\n", countOfOverSpeedCars, countOfOverSpeedCars == 0 ? countOfSpeedTesters : (countOfSpeedTesters - 1));
            continue;
        }
        
        for (int i = 0; i < countOfCars; i++) {
            if (cars[i].speedChangingRate == 0) {
                if (cars[i].originalSpeed > speedLimit) {
                    cars[i].overspeedInterval.first = cars[i].startPosition;
                    cars[i].overspeedInterval.second = lengthOfRoad;
                }
            } else if (cars[i].speedChangingRate > 0) {
                cars[i].overspeedInterval.first = (int)ceil((double)(speedLimit * speedLimit - cars[i].originalSpeed * cars[i].originalSpeed) / (double)((double)2.0f * cars[i].speedChangingRate) + cars[i].startPosition + 1e-10);
                cars[i].overspeedInterval.second = lengthOfRoad;

            } else if (cars[i].speedChangingRate < 0) {
                if (cars[i].originalSpeed > speedLimit) {
                    cars[i].overspeedInterval.second = (int)floor((double)(speedLimit * speedLimit - cars[i].originalSpeed * cars[i].originalSpeed) / (double)((double)2.0f * cars[i].speedChangingRate) + cars[i].startPosition - 1e-10);
                    cars[i].overspeedInterval.first = cars[i].startPosition;
                }

            }
            fprintf(stderr, "Car %d is over speed on [%d, %d]\n", i + 1, cars[i].overspeedInterval.first, cars[i].overspeedInterval.second);
        }

        int carsCaught = 0;

        int t = 0;

        for (int i = 0; i < countOfCars; i++) {
            if (cars[i].overspeedInterval.first >= 0 && cars[i].overspeedInterval.first <= lengthOfRoad) {
                int theFirstSpeedTester = *(std::lower_bound(
                    speedTesterPositions,
                    speedTesterPositions + countOfSpeedTesters + 1, cars[i].overspeedInterval.first
                ));
                

                if (theFirstSpeedTester <= cars[i].overspeedInterval.second) {
                    cars[i].isJudgingOverspeed = true;
                    carsCaught++;
                    if (cars[i].speedChangingRate < 0) t++;
                    fprintf(stderr, "Car %d is caught by the speed tester on %d\n", i + 1, theFirstSpeedTester);

                }
            }
        }

        int q = countOfSpeedTesters - t - 1;
        printf("%d %d\n", carsCaught, std::max(q, 0));
    }

    return 0;
}
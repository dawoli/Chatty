#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

typedef struct _student {
        unsigned int chooseClub1, maxValue1;
        unsigned int chooseClub2, maxValue2;
        unsigned int chooseClub3, maxValue3;

        bool operator<(const _student& other) const {
          if (maxValue1 - maxValue2 == other.maxValue1 - other.maxValue2) {
                  if (maxValue2 - maxValue3 == other.maxValue2 - other.maxValue3) {
                          if (maxValue1 == other.maxValue1) {
                              if (maxValue2 == other.maxValue2) {
                                      return maxValue3 < other.maxValue3;
                              }
                              return maxValue2 < other.maxValue2;
                          }
                          return maxValue1 < other.maxValue1;
                  }
                  return maxValue2 - maxValue3 < other.maxValue2 - other.maxValue3;
          }
          return maxValue1 - maxValue2 < other.maxValue1 - other.maxValue2;
        };
} student;

auto main(void) -> int {
  freopen("club.in", "r", stdin);
#ifndef CORGI
  freopen("club.out", "w", stdout);
#endif

  unsigned int countOfTestcases;
  scanf("%u", &countOfTestcases);

  for (unsigned int cjj = 1; cjj <= countOfTestcases; cjj++) {
    unsigned int countOfStudents;
    scanf("%u", &countOfStudents);

    unsigned int studentCounts[4] = {0, 0, 0, 0};
    student students[countOfStudents + 1];

    auto limit = countOfStudents / 2;
    unsigned int ans = 0;

    for (unsigned int i = 1; i <= countOfStudents; i++) {
      std::pair<unsigned int, unsigned int> values[4];

      for (unsigned int j = 1; j <= 3; j++) {
        scanf("%u", &values[j].first);
        values[j].second = j;
      }

      std::sort(values + 1, values + 4, [&](std::pair<unsigned int, unsigned int> &a, std::pair<unsigned int, unsigned int>&b) {
              return a.first > b.first;
      });

      students[i].maxValue1 = values[1].first;
      students[i].chooseClub1 = values[1].second;
      students[i].maxValue2 = values[2].first;
      students[i].chooseClub2 = values[2].second;
      students[i].maxValue3 = values[3].first;
      students[i].chooseClub3 = values[3].second;
    }

    std::priority_queue<student> unallocatedStudents;

    for (unsigned int i = 1; i <= countOfStudents; i++)
            unallocatedStudents.push(students[i]);
  
    while (unallocatedStudents.size()) {
      auto currentStudent = unallocatedStudents.top();
      unallocatedStudents.pop();

      if (studentCounts[currentStudent.chooseClub1] == limit) {
              currentStudent.chooseClub1 = currentStudent.chooseClub2;
              currentStudent.maxValue1 = currentStudent.maxValue2;
              currentStudent.chooseClub2 = currentStudent.chooseClub3;
              currentStudent.maxValue2 = currentStudent.maxValue3;
              currentStudent.chooseClub3 = 0;
              currentStudent.maxValue3 = 0;
              unallocatedStudents.push(currentStudent);
      } else {
              studentCounts[currentStudent.chooseClub1]++;
              ans += currentStudent.maxValue1;
      }
    }

    printf("%u\n", ans);
  }

  return 0;
}

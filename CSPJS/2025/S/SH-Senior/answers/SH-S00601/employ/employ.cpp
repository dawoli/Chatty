#include <stdio.h>
#include <algorithm>

constexpr unsigned int mod = 998244353;

auto main(void) -> int {
  freopen("employ.in", "r", stdin);
#ifndef CORGI
  freopen("employ.out","w",stdout);
#endif

  unsigned int countOfPeople, employCount;
  scanf("%u %u", &countOfPeople, &employCount);

  char difficulty[countOfPeople + 2];
  scanf("%s", difficulty + 1);

  unsigned int patient[countOfPeople + 1];

  for (unsigned int i = 1; i <= countOfPeople; i++)
          scanf("%u", &patient[i]);

  unsigned int order[countOfPeople + 1];

  for (unsigned int i = 1; i <= countOfPeople; i++) order[i] = i;

  unsigned int ans = 0;

  do {
          unsigned int giveUpCount = 0, currentEmploy = 0;
          for (unsigned int i = 1; i <= countOfPeople; i++) {
                  unsigned int currentPeopleId = order[i];
                  if (patient[currentPeopleId] <= giveUpCount) {
                          giveUpCount++;
                          continue;
                  }
                  if (difficulty[i] == '1') currentEmploy++;
                  else giveUpCount++;
          }
          if (currentEmploy >= employCount) ans++;
  } while (std::next_permutation(order + 1, order + countOfPeople + 1));

  printf("%u", ans);
  return 0;
}

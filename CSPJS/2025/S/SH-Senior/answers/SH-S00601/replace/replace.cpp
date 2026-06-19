#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_map>

#define hashPair(x, y) ((x) * 97 + (y))

typedef struct _replacement {
        std::string source;
        std::string target;
        unsigned int maxPrefixLength = 0, maxSuffixLength = 0, diffPartLength = 0;
        unsigned int prefixHash = 0, suffixHash = 0, diffSourceHash = 0, diffTargetHash = 0;
        unsigned int prefixHash2 = 0, suffixHash2 = 0, diffSourceHash2 = 0, diffTargetHash2 = 0;
} replacement;

constexpr unsigned int base1 = 31;
constexpr unsigned int base2 = 131;

unsigned int quickPow(unsigned int base, unsigned int exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;
    unsigned int x = quickPow(base, exp / 2);
    if (exp & 1) return x * x * base;
    else return x * x;
}

auto main(void) -> int {
        freopen("replace.in", "r", stdin);
#ifndef CORGI
        freopen("replace.out", "w", stdout);
#endif

        unsigned int countOfReplacements, countOfQueries;
        std::cin >> countOfReplacements >> countOfQueries;

        std::vector<replacement> replacements(countOfReplacements + 1);

        for (unsigned int i = 1; i <= countOfReplacements; i++) {
                std::cin >> replacements[i].source >> replacements[i].target;
                
                for (unsigned int j = 0; j < replacements[i].source.size(); j++)
                        if (replacements[i].source[j] == replacements[i].target[j])
                                replacements[i].maxPrefixLength++;
                        else
                                break;

                for (unsigned int j = replacements[i].source.size(); j--; )
                        if (replacements[i].source[j] == replacements[i].target[j])
                                replacements[i].maxSuffixLength++;
                        else
                                break;
                replacements[i].diffPartLength = replacements[i].source.size() - replacements[i].maxPrefixLength - replacements[i].maxSuffixLength;
                for (unsigned int j = 0; j < replacements[i].maxPrefixLength; j++) {
                        replacements[i].prefixHash *= base1;
                        replacements[i].prefixHash2 *= base2;
                        replacements[i].prefixHash += replacements[i].source[j];
                        replacements[i].prefixHash2 += replacements[i].source[j];
                }
                for (unsigned int j = replacements[i].maxPrefixLength; j < replacements[i].source.size() - replacements[i].maxSuffixLength; j++) {
                        replacements[i].diffSourceHash *= base1;
                        replacements[i].diffSourceHash2 *= base2;
                        replacements[i].diffTargetHash *= base1;
                        replacements[i].diffTargetHash2 *= base2;
                        replacements[i].diffSourceHash += replacements[i].source[j];
                        replacements[i].diffSourceHash2 += replacements[i].source[j];
                        replacements[i].diffTargetHash += replacements[i].target[j];
                        replacements[i].diffTargetHash2 += replacements[i].target[j];
                }
                for (unsigned int j = replacements[i].source.size() - replacements[i].maxSuffixLength; j < replacements[i].source.size(); j++) {
                        replacements[i].suffixHash *= base1;
                        replacements[i].suffixHash2 *= base2;
                        replacements[i].suffixHash += replacements[i].source[j];
                        replacements[i].suffixHash2 += replacements[i].source[j];
                }
        }

        std::unordered_map<unsigned int, std::vector<unsigned int>> patterns;

        for (unsigned int i = 1; i <= countOfReplacements; i++)
                patterns[hashPair(replacements[i].diffSourceHash, replacements[i].diffTargetHash)].push_back(i);

        for (unsigned int cjj = 1; cjj <= countOfQueries; cjj++) {
                unsigned int ans = 0;

                std::string source, target;
                std::cin >> source >> target;

                if (source.size() != target.size()) {
                        puts("0");
                        continue;
                }

                unsigned int differentStart = 0, differentEnd = source.size() - 1;
                bool isDifferent = source[0] != target[0];
                for (unsigned int i = 1; i < source.size(); i++) {
                    if (isDifferent == false && source[i] != target[i]) {
                            differentStart = i;
                            isDifferent = true;
                    }
                    else if (isDifferent == true && source[i] == target[i]) {
                            differentEnd = i - 1;
                            isDifferent = false;
                    }
                }
                auto diffSubStringLength = differentEnd - differentStart + 1;

                unsigned int sourceHash1[source.size()], targetHash1[target.size()], sourceHash2[source.size()], targetHash2[target.size()];

                sourceHash1[0] = source[0], targetHash1[0] = target[0];
                sourceHash2[0] = source[0], targetHash2[0] = target[0];

                for (unsigned int i = 1; i < source.size(); i++) {
                    sourceHash1[i] = base1 * sourceHash1[i - 1] + source[i];
                    sourceHash2[i] = base2 * sourceHash2[i - 1] + source[i];
                    targetHash1[i] = base1 * targetHash1[i - 1] + target[i];
                    targetHash2[i] = base2 * targetHash2[i - 1] + target[i];
                }

                unsigned int diffPartSourceHash1, diffPartSourceHash2, diffPartTargetHash1, diffPartTargetHash2;
                if (differentStart == 0) {
                        diffPartSourceHash1 = sourceHash1[differentEnd];
                        diffPartSourceHash2 = sourceHash2[differentEnd];
                        diffPartTargetHash1 = targetHash1[differentEnd];
                        diffPartTargetHash2 = targetHash2[differentEnd];
                } else {
                        diffPartSourceHash1 = sourceHash1[differentEnd] - sourceHash1[differentStart - 1] * quickPow(base1, diffSubStringLength);
                        diffPartSourceHash2 = sourceHash2[differentEnd] - sourceHash2[differentStart - 1] * quickPow(base2, diffSubStringLength);
                        diffPartTargetHash1 = targetHash1[differentEnd] - targetHash1[differentStart - 1] * quickPow(base1, diffSubStringLength);
                        diffPartTargetHash2 = targetHash2[differentEnd] - targetHash2[differentStart - 1] * quickPow(base2, diffSubStringLength);
                }

                auto queryResultPtr = patterns.find(hashPair(diffPartSourceHash1, diffPartTargetHash1));
                if (queryResultPtr != patterns.end()) {
                        for (auto replacementId: queryResultPtr->second) {
                                auto currentReplacement = replacements[replacementId];
                                if (currentReplacement.diffSourceHash == diffPartSourceHash1 && currentReplacement.diffSourceHash2 == diffPartSourceHash2 && currentReplacement.diffTargetHash == diffPartTargetHash1 && currentReplacement.diffTargetHash2 == diffPartTargetHash2) {
                                        if (differentStart < currentReplacement.maxPrefixLength) continue;
                                        if (source.size() - differentEnd - 1 < currentReplacement.maxSuffixLength) continue;

                                        unsigned int prefixHash1, prefixHash2, suffixHash1, suffixHash2;
                                        if (currentReplacement.maxPrefixLength == 0) {
                                                prefixHash1 = prefixHash2 = 0;
                                        } else {
                                                auto prefixStart = differentStart - currentReplacement.maxPrefixLength - 1;
                                                if (prefixStart > source.size()) {
                                                        prefixHash1 = sourceHash1[differentStart - 1];
                                                        prefixHash2 = sourceHash2[differentStart - 1];
                                                } else {
                                                        prefixHash1 = sourceHash1[differentStart - 1] - sourceHash1[prefixStart] * quickPow(base1, currentReplacement.maxPrefixLength);
                                                        prefixHash2 = sourceHash2[differentStart - 1] - sourceHash2[prefixStart] * quickPow(base2, currentReplacement.maxPrefixLength);
                                                }
                                        }

                                        suffixHash1 = sourceHash1[differentEnd + currentReplacement.maxSuffixLength] - sourceHash1[differentEnd] * quickPow(base1, currentReplacement.maxSuffixLength);
                                        suffixHash2 = sourceHash2[differentEnd + currentReplacement.maxSuffixLength] - sourceHash2[differentEnd] * quickPow(base2, currentReplacement.maxSuffixLength);

                                        if (currentReplacement.prefixHash == prefixHash1 && currentReplacement.prefixHash2 == prefixHash2 && currentReplacement.suffixHash == suffixHash1 && currentReplacement.suffixHash2 == suffixHash2) ans++;
                                }
                        }
                printf("%u\n", ans);
                } else {
                    puts("0");
                }
        }
        return 0;
}

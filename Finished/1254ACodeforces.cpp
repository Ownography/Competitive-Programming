/* In this problem it's easy to see why the difference can't be greater than one.
 * Reason for this is that CountOfChickens will always be greater than x % CountOfChickens.
 * Meaning that if we distribute equally, and have left overs, the left overs can be given each to each chicken.
 * Giving us in the end, a difference of 0 or 1 in the worst case.
 * We can then do the distribution pretty primitively and it'll work just fine. But iterating through the grid,
 * Each row from a side to insure connectivity, and then split them equally or equally + 1 accroding to a precalculation.
 * */

#include <stdio.h>
#include <iostream>

using namespace std;

const int N = 1e2 + 10;
int t, r, c, k, totCnt, tempCnt, idx, baseRet, extraRet;
char grid[N][N], ret[N][N];

char intToChar(int idx) {
  int alpha = 'z' - 'a' + 1;
  if (idx >= 0 && idx < alpha) {
    return 'a' + idx;
  }
  if (idx >= alpha && idx < alpha * 2) {
    return 'A' + idx - alpha;
  }
  return '0' + idx - (2 * alpha);
}

void calc(int i, int j) {
  if (grid[i][j] == 'R') {
    tempCnt++;
    ret[i][j] = intToChar(idx);
    if (tempCnt == baseRet) {
      if (extraRet) {
        extraRet--;
      } else {
        tempCnt = 0;
        idx++;
      }
    } else if (tempCnt > baseRet){
      tempCnt = 0;
      idx++;
    }
  } else {
    if (idx < k)
      ret[i][j] = intToChar(idx);
    else
      ret[i][j] = intToChar(idx - 1);
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  scanf("%d", &t);
  while (t--) {
    totCnt = 0, idx = 0, tempCnt = 0, totCnt = 0;
    scanf("%d%d%d", &r, &c, &k);
    for (int i = 0; i < r; ++i) {
      scanf(" %s", grid[i]);
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (grid[i][j] == 'R') {
          totCnt++;
        }
      }
    }
    baseRet = totCnt / k, extraRet = totCnt % k;
    for (int i = 0; i < r; i++) {
      if (i & 1) {
        for (int j = c - 1; j > -1; j--) {
          calc(i, j);
        }
      } else {
        for (int j = 0; j < c; j++) {
          calc(i,j);
        }
      }
    }
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        printf("%c", ret[i][j]);
      }
      puts("");
    }
  }
  return 0;
}

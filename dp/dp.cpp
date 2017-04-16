//
// Created by RetroX on 16/04/2017.
//

#include <cstdio>

#define MAXN 1000
#define MAXC 100000

int V[MAXN], W[MAXN];
int d[MAXN][MAXC];

int main() {
    freopen("/Users/retrox/ProgramHomework/Algorithm/dp/data.in", "r", stdin);
    int n, C;
    while (scanf("%d %d", &n, &C) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d %d", &V[i], &W[i]);
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= C; ++j) {
                if (i == 0) {
                    d[i][j] = 0;
                } else {
                    d[i][j] = d[i - 1][j];
                }
                if (i > 0 && j >= V[i - 1]) {
                    if (d[i][j] < d[i - 1][j - V[i - 1]] + W[i - 1]) {
                        d[i][j] = d[i - 1][j - V[i - 1]] + W[i - 1];
                    };
                }
            }
        }

        printf("%d\n", d[n][C]);
    }
}
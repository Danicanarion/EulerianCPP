#include "Eulerian.h"
#include <vector>
using namespace std;

int Eulerian::euleriantab(int n, int m) {
    vector< vector<int> > dp(static_cast<unsigned long>(n + 1), vector<int>(static_cast<unsigned long>(m + 1)));

    for (int i = 1; i <= n ; i++) {
        for (int j = 0; j <= m ; j++) {

            if (i > j){
                if (j == 0){
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = ((i - j) * dp[i - 1][j - 1]) + ((j + 1) * dp[i - 1][j]);
                }
            }

        }
    }
    return dp[n][m];
}

int Eulerian::eulerianmem(int n, int m) {
    vector< vector<int> > dp(static_cast<unsigned long>(n + 1), vector<int>(static_cast<unsigned long>(m + 1)));
    if(dp[n][m] != 0){
        return dp[n][m];
    }
    if (n > m){
        if(m == 0){
            dp[n][m] = 1;
        } else {
            dp[n][m] = ((n-m) * eulerianmem(n-1, m-1)) + ((m+1) * eulerianmem(n-1, m));
        }
    }
    return dp[n][m];
}

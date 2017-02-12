#include "chap2/greedy_coin.h"

int greedy_coin(
    const int price, const int coins[6], const int numCoins[6])
{
    int answer = 0;
    int rest = price;
    for (int i = 5; i >= 0; --i) {
         const int numUsed = (int)(rest / coins[i]);
         if (numUsed > numCoins[i]) {
            rest -= numCoins[i] * coins[i];
            answer += numCoins[i];
         } else {
             rest = rest % coins[i];
            answer += numUsed;
         }
    }
    return answer;
}


#include "pccb/chap4/set/inclusion_exclusion_principle.h"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <bit>

using namespace std;
typedef long long ll;
typedef std::vector<int> vec;
typedef std::vector<vec> mat;

namespace pccb {

ll gcd(ll a, ll b) {
  assert(a >= b);
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int inclusion_exclusion_principle(const int n, const std::vector<long long>& a) {
  ll res = 0;
  const ll m = a.size();
  for (unsigned int i = 0; i < (1 << m); ++i) {
    ll lcm = 1;
    for (int j = 0; j < m; j++) {
      if ((i >> j) & 1) {
        ll gcdd = 0;
        if (lcm < a[j]) {
          gcdd = gcd(a[j], lcm);
        } else {
          gcdd = gcd(lcm, a[j]);
        }
        lcm = lcm / gcdd * a[j];
      }
      if (lcm > n) break;
    }
    if (std::popcount(i) % 2 == 0) {
      res -= n / lcm;
    } else {
      res += n / lcm;
    }
  }
  return res;
}

} // namespace pccb


#include "algorithm/bucket_method/k_th_number.h"
#include <algorithm>
#include <cmath>
#include <iostream>

namespace algorithm {
  int SolveKThNumberGetSize(const int size) {
    return std::floor(std::sqrt(size));
  }

  int SolveKThNumberGetBucketIndex(const int size, const int b_size) {
    return size / b_size;
  }

  std::vector<int> SolveKThNumber(
      const int num_seq,
      int seq[],
      const std::vector<std::vector<int>>& queries)
  {
    const int b_size = SolveKThNumberGetSize(num_seq);
    // sorted sequence
    int sorted[num_seq];
    // sorted buckets
    std::vector<std::vector<int>> buckets(b_size + 3, std::vector<int>(0));

    for (int i = 0; i < num_seq; ++i) {
      sorted[i] = seq[i];
      buckets[i / b_size].push_back(seq[i]);
    }
    std::sort(sorted, sorted + num_seq);
    // sort buckets
    for (int i = 0; i < b_size + 1; ++i) {
      std::sort(buckets[i].begin(), buckets[i].end());
    }

    for (int vi = 0; vi < num_seq; ++vi) {
      std::cout << seq[vi] << ", ";
    }
    std::cout << std::endl;
    for (int vi = 0; vi < num_seq; ++vi) {
      std::cout << sorted[vi] << ", ";
    }
    std::cout << std::endl;
    std::vector<int> ans(0);
    for (int q = 0; q < queries.size(); ++q) {
      // find k-th number between a[i],...,a[j]
      const int left = queries[q][0];
      const int right = queries[q][1];
      const int k = queries[q][2];

      int lb = -1;
      int ub = num_seq - 1;
      // (lb, ub]
      while (ub - lb > 1) {
        const int mid = (lb + ub) / 2;
        int mid_val = sorted[mid];
        int tleft = left;
        int tright = right;
        // the number of values less than or euqal to mid_val
        int pos = 0;

        std::cout << "b_size: " << b_size << std::endl;
        std::cout << "k: " << k << std::endl;
        std::cout << "sorted[" << mid << "]: " << mid_val << std::endl;
        std::cout << "seq[" << tleft << ", " << tright << "]: " << std::endl;
        std::cout << "biseq[" << lb << ", " << ub << "]: " << std::endl;
        for (int vi = tleft; vi <= tright; ++vi) {
          std::cout << seq[vi] << ", ";
        }
        std::cout << std::endl;
        // left-side extra elems
        while (tleft <= tright && tleft % b_size != 0) {
          if (seq[tleft++] <= mid_val) {
            pos++;
          }
        }
        std::cout << pos << std::endl;
        // right-side extra elems
        while (tleft < tright && tright % b_size != 0) {
          if (seq[--tright] <= mid_val) {
            pos++;
          }
        }
        std::cout << pos << std::endl;

        // bucket
        while(tleft < tright) {
          const int b = tleft / b_size;
          pos += std::upper_bound(buckets[b].begin(), buckets[b].end(), mid_val)
            - buckets[b].begin();
          tleft += b_size;
        }
        std::cout << pos << std::endl;

        if (pos >= k) {
          ub = mid;
        } else {
          lb = mid;
        }

      }
      std::cout << std::endl;
      ans.push_back(sorted[ub]);
    }
    return ans;
  }
} // namespace algorithm

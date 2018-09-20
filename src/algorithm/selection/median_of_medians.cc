
namespace algorithm {
namespace selection {

  int Pivot(
      const int array[],
      const int left,
      const int right)
  {
    if (right - left <= 5) {
      // get median of 5
      return Partition5(array, left, right);
    }
    // otherwise move the medians of five-elements subgroups to the first n/5 positions
    for (int i = left; i <= right; i+=5) {
      // get the median of the ith five-elements subgroup
      int sub_right = i + 4;
      if (sub_right > right) {
        sub_right = right;
      }

      median5 = Partition5(array, i, sub_right);
      const int swap_index = left + std::floor((i - left) / 5);
      std::swap(array[median5], array[swap_index]);
    }

    // compute the median of the n / 5 medians of five
    return MedianOfMedians(array, left, left + std::floor((right - left) / 5, (right - left) / 10 + 1));
  }

  int Partition5(
      const int array[],
      const int left,
      const int right)
  {
    const int size = right - left;
    assert(size < 5);
    assert(size >= 0);
    int store[size];
    for (int i = 0; i < size; ++i) {
      store[i] = array[i];
    }
    std::sort(store, store + size);
    return store[size / 2];
  }

  int Partition(
      const int array[],
      const int left,
      const int right,
      const int pivot_index)
  {
    const int pivot_value = array[pivot_index];
    std::swap(array[right], array[pivot_index]);
    int store_index = left;
    for (int i = left; i < right; ++i) {
      if (array[i] < pivot_value) {
        std::swap(array[i], array[store_index]);
        store_index++;
      }
    }
    std::swap(array[right], array[store_index]);
    return store_index;
  }

  int MedianOfMedians(
      const int array[],
      const int left0,
      const int right0,
      const int size)
  {
    int left = left0;
    int right = right0;
    while (true) {
      if (left == right) {
        return left;
      }
      int pivot_index = Pivot(array, left, right);
      pivot_index = Partition(array, left, right, pivot_index);
      if (size == pivot_index) {
        return size;
      } else if (size < pivot_index) {
        right = pivot_index - 1 ;
      } else {
        left = pivot_index + 1;
      }
    }
  }
} // namespace selection
} // namespace algorithm




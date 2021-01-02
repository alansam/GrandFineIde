
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std::literals;

int main() {
  std::cout << "GrandFineIde"s << std::endl;
  std::cout << __cplusplus << std::endl;

  size_t cc;
  size_t const cc_max(10);
  auto pa = [& cc](auto n_) {
    std::cout << std::setw(8) << n_
              << ((++cc % cc_max == 0) ? "\n"s : ""s);
  };

  int nums[] { 444, 42, 10344, -549, -1, 2243, };
  std::vector<int> numbers(std::cbegin(nums), std::cend(nums));

  {
    std::cout << "std::min_element & std::max_element"s << '\n';
    auto it_min = std::min_element(numbers.cbegin(), numbers.cend());
    auto it_max = std::max_element(numbers.cbegin(), numbers.cend());
    auto dst_min = std::distance(numbers.cbegin(), it_min);
    auto dst_max = std::distance(numbers.cbegin(), it_max);

    cc = 0;
    std::for_each(numbers.cbegin(), numbers.cend(), pa);
    std::cout << std::endl;
    std::cout << "Min "s
              << "element["s << std::setw(2) << dst_min << "]:"s
              << std::setw(8) << *it_min << '\n';
    std::cout << "Max "s
              << "element["s << std::setw(2) << dst_max << "]:"s
              << std::setw(8) << *it_max << '\n';
    std::cout << std::endl;
  }

  {
    std::cout << "std::minmax_element"s << '\n';
    auto [it_min, it_max] =
      std::minmax_element(numbers.cbegin(), numbers.cend());
    auto dst_min = std::distance(numbers.cbegin(), it_min);
    auto dst_max = std::distance(numbers.cbegin(), it_max);
    auto min = *it_min;
    auto max = *it_max;

    cc = 0;
    std::for_each(numbers.begin(), numbers.end(), pa);
    std::cout << std::endl;
    std::cout << "Min "s
              << "element["s << std::setw(2) << dst_min << "]:"s
              << std::setw(8) << min << '\n';
    std::cout << "Max "s
              << "element["s << std::setw(2) << dst_max << "]:"s
              << std::setw(8) << max << '\n';
    std::cout << std::endl;
  }

  return 0;
}

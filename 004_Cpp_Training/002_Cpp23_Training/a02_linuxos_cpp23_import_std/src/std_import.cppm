module;

// Include standard library headers
#include <iostream>
#include <print>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <memory>
#include <stdexcept>
#include <format>
#include <ranges>
#include <span>
#include <concepts>
#include <tuple>
#include <optional>
#include <variant>
#include <chrono>
#include <filesystem>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>
#include <numbers>
#include <cmath>
#include <complex>
#include <valarray>
#include <numeric>
#include <random>
#include <bitset>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <array>
#include <iterator>
#include <utility>
#include <type_traits>
#include <initializer_list>
#include <source_location>
#include <expected>
#include <string_view>

export module std_import;

// Export the standard library names from this module
export using std::cout;
export using std::cin;
export using std::cerr;
export using std::clog;
export using std::endl;
export using std::flush;
export using std::string;
export using std::vector;
export using std::map;
export using std::set;
export using std::pair;
export using std::tuple;
export using std::optional;
export using std::variant;
export using std::unique_ptr;
export using std::shared_ptr;
export using std::weak_ptr;
export using std::make_unique;
export using std::make_shared;
export using std::move;
export using std::forward;
export using std::swap;
export using std::sort;
export using std::find;
export using std::transform;
export using std::for_each;
export using std::copy;
export using std::fill;
export using std::reverse;
export using std::max;
export using std::min;
export using std::clamp;
export using std::abs;
export using std::sqrt;
export using std::pow;
export using std::sin;
export using std::cos;
export using std::tan;
export using std::exp;
export using std::log;
export using std::chrono::seconds;
export using std::chrono::milliseconds;
export using std::chrono::microseconds;
export using std::chrono::nanoseconds;
export using std::chrono::duration_cast;
export using std::chrono::steady_clock;
export using std::chrono::system_clock;
export using std::thread;
export using std::mutex;
export using std::lock_guard;
export using std::unique_lock;
export using std::condition_variable;
export using std::future;
export using std::promise;
export using std::async;
export using std::atomic;
export using std::function;
export using std::bind;
export using std::runtime_error;
export using std::logic_error;
export using std::exception;
export using std::out_of_range;
export using std::invalid_argument;
export using std::format;
export using std::print;
export using std::println;
export using std::ranges::view;
export using std::ranges::input_range;
export using std::ranges::output_range;
export using std::span;
export using std::integral;
export using std::floating_point;
export using std::derived_from;
export using std::convertible_to;
export using std::same_as;
export using std::get;
export using std::make_tuple;
export using std::tie;
export using std::make_pair;
export using std::bitset;
export using std::deque;
export using std::list;
export using std::forward_list;
export using std::unordered_map;
export using std::unordered_set;
export using std::stack;
export using std::queue;
export using std::priority_queue;
export using std::array;
export using std::begin;
export using std::end;
export using std::cbegin;
export using std::cend;
export using std::size;
export using std::empty;
export using std::data;
export using std::initializer_list;
export using std::source_location;
export using std::expected;
export using std::unexpected;
export using std::string_view;
export using std::numbers::pi;
export using std::numbers::e;
export using std::complex;
export using std::valarray;
export using std::accumulate;
export using std::iota;
export using std::partial_sum;
export using std::adjacent_difference;
export using std::inner_product;
export using std::random_device;
export using std::mt19937;
export using std::uniform_int_distribution;
export using std::uniform_real_distribution;
export using std::normal_distribution;

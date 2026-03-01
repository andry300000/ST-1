// Copyright 2025 UNN-CS
#include <cstddef>
#include <cstdint>
#include <vector>
#include "alg.h"


bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  if (value == 2 || value == 3) return true;
  if (value % 2 == 0 || value % 3 == 0) return false;

  for (uint64_t i = 5; i <= value / i; i += 6) {
    if (value % i == 0) return false;
    if (value % (i + 2) == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  if (n == 0) return 0;
  if (n == 1) return 2;

  uint64_t count = 1;
  uint64_t candidate = 3;
  while (count < n) {
    if (checkPrime(candidate)) ++count;
    if (count == n) return candidate;
    candidate += 2;
  }
  return 0;
}

uint64_t nextPrime(uint64_t value) {
  if (value < 2) return 2;
  if (value == UINT64_MAX) return 0;

  uint64_t candidate = value + 1;
  if (candidate % 2 == 0) ++candidate;

  while (candidate != 0) {
    if (checkPrime(candidate)) return candidate;
    if (candidate > UINT64_MAX - 2) return 0;
    candidate += 2;
  }
  return 0;
}

uint64_t sumPrime(uint64_t hbound) {
  if (hbound <= 2) return 0;
  if (hbound == 3) return 2;

  const uint64_t limit = hbound - 1;
  const uint64_t odd_count = (limit - 3) / 2 + 1;
  std::vector<uint8_t> is_prime_odd(static_cast<size_t>(odd_count), 1);

  for (uint64_t i = 0; i < odd_count; ++i) {
    if (!is_prime_odd[static_cast<size_t>(i)]) continue;
    const uint64_t p = 2 * i + 3;
    if (p > limit / p) break;

    uint64_t start = (p * p - 3) / 2;
    for (uint64_t j = start; j < odd_count; j += p) {
      is_prime_odd[static_cast<size_t>(j)] = 0;
    }
  }

  uint64_t sum = 2;
  for (uint64_t i = 0; i < odd_count; ++i) {
    if (is_prime_odd[static_cast<size_t>(i)]) sum += (2 * i + 3);
  }
  return sum;
}

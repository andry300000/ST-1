// Copyright 2025 UNN-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"


TEST(st1, checkPrime_small_nonprimes) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_FALSE(checkPrime(4));
  EXPECT_FALSE(checkPrime(9));
}

TEST(st1, checkPrime_small_primes) {
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_TRUE(checkPrime(5));
  EXPECT_TRUE(checkPrime(7));
}

TEST(st1, checkPrime_composite_squares) {
  EXPECT_FALSE(checkPrime(25));
  EXPECT_FALSE(checkPrime(49));
  EXPECT_FALSE(checkPrime(121));
}

TEST(st1, checkPrime_larger_prime) {
  EXPECT_TRUE(checkPrime(97));
  EXPECT_TRUE(checkPrime(1009));
}

TEST(st1, nPrime_basic) {
  EXPECT_EQ(2ULL, nPrime(1));
  EXPECT_EQ(3ULL, nPrime(2));
  EXPECT_EQ(5ULL, nPrime(3));
  EXPECT_EQ(13ULL, nPrime(6));
}

TEST(st1, nPrime_100th_is_541) {
  EXPECT_EQ(541ULL, nPrime(100));
}

TEST(st1, nextPrime_from_composite) {
  EXPECT_EQ(5ULL, nextPrime(4));
  EXPECT_EQ(11ULL, nextPrime(10));
  EXPECT_EQ(29ULL, nextPrime(28));
}

TEST(st1, nextPrime_from_prime_excludes_value) {
  EXPECT_EQ(13ULL, nextPrime(11));
  EXPECT_EQ(19ULL, nextPrime(17));
  EXPECT_EQ(3ULL, nextPrime(2));
}

TEST(st1, sumPrime_boundaries) {
  EXPECT_EQ(0ULL, sumPrime(0));
  EXPECT_EQ(0ULL, sumPrime(1));
  EXPECT_EQ(0ULL, sumPrime(2));
  EXPECT_EQ(2ULL, sumPrime(3));
}

TEST(st1, sumPrime_small_values) {
  EXPECT_EQ(17ULL, sumPrime(10));
  EXPECT_EQ(77ULL, sumPrime(20));
}

TEST(st1, sumPrime1) {
  uint64_t res = sumPrime(2000000);
  uint64_t expected = 142913828922;
  EXPECT_EQ(expected, res);
}
TEST(st1, sumPrime2) {
  uint64_t res = sumPrime(10);
  uint64_t expected = 17;
  EXPECT_EQ(expected, res);
}

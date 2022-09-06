// rng.h

#pragma once

#include <random>

class Rng {

public:
  Rng(int seed = 12345678);
  double RandReal(double min = 0.0, double max = 1.0);
  double RandNormal(double mean = 0.0, double stddev = 1.0);
  int RandInt(int min, int max);

  std::mt19937 gen;
};

Rng::Rng(int seed) {
  gen = std::mt19937(seed);
}

double Rng::RandReal(double min, double max) {
  std::uniform_real_distribution<double> dist(min, max);
  return dist(gen);
}

double Rng::RandNormal(double mean, double stddev) {
  std::normal_distribution<double> dist(mean, stddev);
  return dist(gen);
}

int Rng::RandInt(int min, int max) {
  std::uniform_int_distribution<int> dist(min, max);
  return dist(gen);
}

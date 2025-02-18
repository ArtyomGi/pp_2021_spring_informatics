// Copyright 2021 Rustamov Azer

#ifndef MODULES_TASK_1_RUSTAMOV_A_HISTOGRAM_STRETCH_HISTOGRAM_STRETCH_H_
#define MODULES_TASK_1_RUSTAMOV_A_HISTOGRAM_STRETCH_HISTOGRAM_STRETCH_H_
#include <vector>


using Matrix = std::vector<int>;

Matrix generate_random_image(int w, int h, int min_y = 30, int max_y = 192);
Matrix make_histogram(const Matrix& image, int w, int h);
int get_min_y(const Matrix& histogram);
int get_max_y(const Matrix& histogram);
Matrix stretch_histogram(const Matrix& histogtram, const int& min_y, const int& max_y);
Matrix increase_contrast(const Matrix& image, int w, int h, const int& min_y, const int& max_y);

Matrix histogram_sretch_algorithm(const Matrix& image, const int w, const int h);



#endif  // MODULES_TASK_1_RUSTAMOV_A_HISTOGRAM_STRETCH_HISTOGRAM_STRETCH_H_

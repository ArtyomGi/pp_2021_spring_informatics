// Copyright 2021 Vlasov Maksim

#include "../../../modules/task_1/vlasov_m_simpson_method/simpson_method.h"

#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <stdexcept>
#include <utility>

static void sumUp(std::vector<double>* accum, const std::vector<double>& add) {
    assert(accum->size() == add.size());
    for (size_t i = 0; i < accum->size(); i++)
        accum->at(i) += add[i];
}

double SimpsonMethod::integrate(
    const std::function<double(const std::vector<double>&)>& func,
    const std::vector<double>& seg_begin, const std::vector<double>& seg_end,
    size_t steps_count) {
    if (seg_begin.empty() || seg_end.empty())
        throw std::runtime_error("No segments");
    if (seg_begin.size() != seg_end.size())
        throw std::runtime_error("Invalid segments");
    size_t dim = seg_begin.size();
    std::vector<double> steps(dim), segments(dim);
    for (size_t i = 0; i < dim; i++) {
        steps[i] = (seg_end[i] - seg_begin[i]) / static_cast<int>(steps_count);
        segments[i] = seg_end[i] - seg_begin[i];
    }
    auto sum = std::make_pair<double, double>(0.0, 0.0);
    std::vector<double> args = seg_begin;
    for (size_t i = 0; i < steps_count; i += 2) {
        sumUp(&args, steps);
        sum.first += func(args);
        sumUp(&args, steps);
        sum.second += func(args);
    }
    double seg_prod = std::accumulate(segments.begin(), segments.end(), 1.0,
                                      [](double p, double s) { return p * s; });
    return (func(seg_begin) + 4 * sum.first + 2 * sum.second - func(seg_end)) *
           seg_prod / (3.0 * static_cast<double>(steps_count));
}

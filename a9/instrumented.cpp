#include "instrumented.h"
#include <algorithm>

const size_t instrumented_base::number_ops;
double instrumented_base::counts[];
const char* operation_numbers[] = {"n", "copy", "assignment",
    "destructor", "default_constructor", "equality",
    "comparison", "constructor"};
void instrumented_base::initialize(size_t m) {
    std::fill(counts, counts + number_ops, 0.0);
    counts[0] = double(m);
}

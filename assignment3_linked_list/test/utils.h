#pragma once
#include <vector>
#include <assert.h>

template <typename T>
void assertEqual(std::vector<T> listVectorRepresentation, std::vector<T> expectedAnswer) {
    assert(listVectorRepresentation == expectedAnswer);
}

#pragma once
#include <vector>
#include <assert.h>
#include "../Polynomial.h"


void asserEqualPolyTerms(PolynomialTerm term1, PolynomialTerm term2);

template <typename T>
void assertEqual(std::vector<T> listVectorRepresentation, std::vector<T> expectedAnswer) {
    assert(listVectorRepresentation == expectedAnswer);
}

void assertEqualPolynomials(Polynomial p1, Polynomial p2);

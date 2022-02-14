#include "utils.h"

void asserEqualPolyTerms(PolynomialTerm term1, PolynomialTerm term2) {
    assert(term1.base == term2.base && term1.power == term2.power);
}

void assertEqualPolynomials(Polynomial p1, Polynomial p2) {
    assert(p1.length() == p2.length());
    for (int i=0; i<p1.length(); i++) {
        asserEqualPolyTerms(p1.at(i), p2.at(i));
    }
}
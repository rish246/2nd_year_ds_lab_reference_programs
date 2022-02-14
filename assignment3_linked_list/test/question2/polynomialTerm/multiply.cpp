#include "multiply.h"

void testMultiplyTermWithZeroReturnsZeroSuccess() {
    PolynomialTerm term1(2, 2);
    PolynomialTerm term2(0, 0);
    PolynomialTerm prod2 = term1.multiply(term2);
    asserEqualPolyTerms(prod2, PolynomialTerm(0, 2));
    std::cout << "Passed multiplying polynomial terms with 0 test" << std::endl;
}

void testMultiplyTwoNonZeroTermsSuccess() {
    PolynomialTerm term1(2, 2);
    PolynomialTerm term2(2, 3);
    PolynomialTerm prod2 = term1.multiply(term2);
    asserEqualPolyTerms(prod2, PolynomialTerm(4, 5));
    std::cout << "Passed multiplying non zero polynomial terms test" << std::endl;
}

void runMultiplyTests() {
    testMultiplyTermWithZeroReturnsZeroSuccess();
    testMultiplyTwoNonZeroTermsSuccess();
}
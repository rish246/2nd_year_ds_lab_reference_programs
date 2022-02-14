#include "add.h"

void testAddTwoTermsWithSamePowerSuccess() {
    // std::cout << "Reached here" << std::endl;
    PolynomialTerm term1(2, 2), term2(3, 2); // 2x2 + 3x2 -> 5x2
    PolynomialTerm sum2 = term1.add(term2);
    PolynomialTerm expectedSum(5, 2);
    assertEqualPolynomials(sum2, expectedSum);
    std::cout << "Passed testing adding two polynomial terms with same power" << std::endl;
}


void testAddATermWithZeroSuccess() {
    // std::cout << "Reached here" << std::endl;
    PolynomialTerm term1(2, 2), term2(0, 1); // 2x2 + 3x2 -> 5x2
    PolynomialTerm sum2 = term1.add(term2);
    PolynomialTerm expectedSum(2, 2);
    assertEqualPolynomials(sum2, expectedSum);
    std::cout << "Passed testing a polynomial term to zero" << std::endl;
}



void runAddTests() {
    testAddTwoTermsWithSamePowerSuccess();
    testAddATermWithZeroSuccess();
    // addTwoTermsWithDifferentPowerSuccess();
}
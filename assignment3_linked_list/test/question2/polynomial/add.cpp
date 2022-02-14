#include "add.h"

void testAddTwoPolynomialsWithSameLengthAndSamePowersSuccess() {
    /*
    2x2 + 3x + 2 
    3x2 -4x + 7
    -----------
    5x2 - x + 9
    */
    Polynomial poly1; // 2x2 + 3x + 2
    poly1.append(PolynomialTerm(2, 2));
    poly1.append(PolynomialTerm(3, 1));
    poly1.append(PolynomialTerm(2, 0));

    Polynomial poly2; // 3x2 - 4x + 7
    poly2.append(PolynomialTerm(3, 2));
    poly2.append(PolynomialTerm(-4, 1));
    poly2.append(PolynomialTerm(7, 0));

    Polynomial sum2 = poly1.add(poly2);
    
    Polynomial expectedAns; // 5x2 - x + 9
    expectedAns.append(PolynomialTerm(5, 2));
    expectedAns.append(PolynomialTerm(-1, 1));
    expectedAns.append(PolynomialTerm(9, 0));

    assertEqualPolynomials(sum2, expectedAns);
    std::cout << "Passed adding two polynomials with same length and same powers test" << std::endl;
}



void testAddTwoPolynomialsWithDifferentLengthAndDifferentPowersSuccess() {
/*
    2x2 + 3x + 2 
    3x3 -4x
    -----------
    3x3 + 2x2 -x + 2
    */
    Polynomial poly1; // 2x2 + 3x + 2
    poly1.append(PolynomialTerm(2, 2));
    poly1.append(PolynomialTerm(3, 1));
    poly1.append(PolynomialTerm(2, 0));

    Polynomial poly2; // 3x3 - 4x
    poly2.append(PolynomialTerm(3, 3));
    poly2.append(PolynomialTerm(-4, 1));

    Polynomial sum2 = poly1.add(poly2);
    
    Polynomial expectedAns; // 3x3 + 2x2 -x + 2
    expectedAns.append(PolynomialTerm(3, 3));
    expectedAns.append(PolynomialTerm(2, 2));
    expectedAns.append(PolynomialTerm(-1, 1));
    expectedAns.append(PolynomialTerm(2, 0));

    assertEqualPolynomials(sum2, expectedAns);
    std::cout << "Passed adding two polynomials with different lengths and powers" << std::endl;


}


void testAddPolynomialWithZeroReturnsSamePolynomialSuccess() {
    /*
    2x2 + 3x + 2 
    0
    -----------
    2x2 + 3x + 2 
    */
    Polynomial poly1; // 2x2 + 3x + 2
    poly1.append(PolynomialTerm(2, 2));
    poly1.append(PolynomialTerm(3, 1));
    poly1.append(PolynomialTerm(2, 0));


    Polynomial poly2(PolynomialTerm(0, 1));

    Polynomial sum2 = poly1.add(poly2);

    assertEqualPolynomials(sum2, poly1);
    std::cout << "Passed adding a polynomial with zero test" << std::endl;
}




void runAddTests() {
    testAddTwoPolynomialsWithSameLengthAndSamePowersSuccess();
    testAddTwoPolynomialsWithDifferentLengthAndDifferentPowersSuccess();
    testAddPolynomialWithZeroReturnsSamePolynomialSuccess();
}
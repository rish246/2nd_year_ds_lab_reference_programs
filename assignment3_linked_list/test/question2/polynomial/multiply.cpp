#include "multiply.h"

void testMultiplyTwoPolynomialsWithSameLengthSuccess() {
    /*
    3x2 + 2x
    2x3 + 4x
    ------------
    6x5 + 12x3 + 4x4 + 8x2
    ------------
    */
    std::vector<PolynomialTerm> firstPolyTerms;
    firstPolyTerms.push_back(PolynomialTerm(3, 2));
    firstPolyTerms.push_back(PolynomialTerm(2, 1));            
    // firstPolyTerms.push_back(PolynomialTerm(1, 0));           
    Polynomial poly1(firstPolyTerms);

    // 2x3 + 4x
    std::vector<PolynomialTerm> secondPolyTerms;
    secondPolyTerms.push_back(PolynomialTerm(2, 3));
    secondPolyTerms.push_back(PolynomialTerm(4, 1));   
    Polynomial poly2(secondPolyTerms);

    Polynomial prod2 = poly1.multiply(poly2);

    Polynomial expectedAns;
    expectedAns.append(PolynomialTerm(6, 5));
    expectedAns.append(PolynomialTerm(4, 4));
    expectedAns.append(PolynomialTerm(12, 3));
    expectedAns.append(PolynomialTerm(8, 2));

    assertEqualPolynomials(prod2, expectedAns);
    std::cout << "Passed multiply two polynomials with same length test" << std::endl;

}

void testMultiplyTwoPolynomialsWithDifferentLengthSuccess() {
    /*
    3x2 + 2x
    2x3 + 4x + 7
    ------------
    6x5 + 12x3 + 21x2 + 4x4 + 8x2 + 14x
    6x5 + 4x4 + 12x3 + 29x2 + 14x
    ------------
    */
    std::vector<PolynomialTerm> firstPolyTerms;
    firstPolyTerms.push_back(PolynomialTerm(3, 2));
    firstPolyTerms.push_back(PolynomialTerm(2, 1));            
    // firstPolyTerms.push_back(PolynomialTerm(1, 0));           
    Polynomial poly1(firstPolyTerms);

    // 2x3 + 4x
    std::vector<PolynomialTerm> secondPolyTerms;
    secondPolyTerms.push_back(PolynomialTerm(2, 3));
    secondPolyTerms.push_back(PolynomialTerm(4, 1)); 
    secondPolyTerms.push_back(PolynomialTerm(7, 0));   

    Polynomial poly2(secondPolyTerms);

    Polynomial prod2 = poly1.multiply(poly2);

    Polynomial expectedAns;
    expectedAns.append(PolynomialTerm(6, 5));
    expectedAns.append(PolynomialTerm(4, 4));
    expectedAns.append(PolynomialTerm(12, 3));
    expectedAns.append(PolynomialTerm(29, 2));
    expectedAns.append(PolynomialTerm(14, 1));

 
    assertEqualPolynomials(prod2, expectedAns);
    std::cout << "Passed multiply two polynomials with different length test" << std::endl;
}


void runMultiplyTests() {
    testMultiplyTwoPolynomialsWithSameLengthSuccess();
    testMultiplyTwoPolynomialsWithDifferentLengthSuccess();
}
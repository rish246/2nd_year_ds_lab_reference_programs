#include "Polynomial.h"

int main() {

    // 3x2 + 2x + 1
    std::vector<PolynomialTerm> firstPolyTerms;
    firstPolyTerms.push_back(PolynomialTerm(3, 2));
    firstPolyTerms.push_back(PolynomialTerm(2, 1));            
    firstPolyTerms.push_back(PolynomialTerm(1, 0));           


    Polynomial poly1(firstPolyTerms);
    poly1.print();

    // 2x3 + 4x
    std::vector<PolynomialTerm> secondPolyTerms;
    secondPolyTerms.push_back(PolynomialTerm(2, 3));
    secondPolyTerms.push_back(PolynomialTerm(4, 1));            
    // secondPolyTerms.push_back(PolynomialTerm(2, 0));     
    Polynomial zero;
    zero.append(PolynomialTerm(0, 0));

    Polynomial poly2(secondPolyTerms);
    poly2.print();

    Polynomial sum2Poly = poly1.add(poly2);
    sum2Poly.print(); // 2x3 + 3x2 + 6x + 1 // 

    Polynomial sub2Poly = poly1.subtract(poly2);
    sub2Poly.print(); // -2x3 + 3x2 - 2x + 1 // works

    Polynomial prod2Poly = poly1.multiply(poly2);
    prod2Poly.print();
}



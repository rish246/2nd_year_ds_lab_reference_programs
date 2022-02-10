#include "Polynomial.h"

int main() {

    // 3x2 + 2x + 1
    std::vector<PolynomialTerm> firstPolyTerms;
    firstPolyTerms.push_back(PolynomialTerm(3, 2));
    firstPolyTerms.push_back(PolynomialTerm(2, 1));            
    firstPolyTerms.push_back(PolynomialTerm(1, 0));           


    Polynomial poly1(firstPolyTerms);
    poly1.print();

    // 2x3
    std::vector<PolynomialTerm> secondPolyTerms;
    secondPolyTerms.push_back(PolynomialTerm(2, 3));
    // secondPolyTerms.push_back(PolynomialTerm(4, 1));            
    // secondPolyTerms.push_back(PolynomialTerm(2, 0));     

    Polynomial poly2(secondPolyTerms);
    poly2.print();

    Polynomial sum2Poly = poly1.add(poly2);
    sum2Poly.print(); // 2x3 + 3x2 + 2x + 1 // 
}



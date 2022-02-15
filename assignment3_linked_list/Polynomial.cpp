#include "Polynomial.h"

////////////////////////// POLYNOMIAL TERM //////////////////////////////
PolynomialTerm::PolynomialTerm(): base(0), power(1) {}

PolynomialTerm::PolynomialTerm(int _base, int _power): base(_base), power(_power) {}

PolynomialTerm PolynomialTerm::add(PolynomialTerm &other) {
    if (base == 0 || other.base == 0) {
        PolynomialTerm nonZeroTerm = base == 0 ? other : (*this);
        return nonZeroTerm;
    }
    return PolynomialTerm(base + other.base, other.power); 
}

PolynomialTerm PolynomialTerm::multiply(PolynomialTerm &other) {
    // bases get multiplied and powers get added
    // 3x * 4x => 12x2
    return PolynomialTerm(base * other.base, other.power + power);
}

void PolynomialTerm::print() {
    std::cout << "(" << base << "x^" << power << ") ";
}

//////////////////////////// UTILITY CLASSES //////////////////////////////


NextMove::NextMove(PolynomialTerm _nextTermInResult, int _ownIndexMove, int _otherIndexMove)
    : nextTermInResult(_nextTermInResult), ownIndexMove(_ownIndexMove), otherIndexMove(_otherIndexMove){}



/*                  MAIN POLYNOMIAL CLASS                       */
    
Polynomial::Polynomial(): expression(new LinkedList<PolynomialTerm>()) {}
    
Polynomial::Polynomial(std::vector<PolynomialTerm> &terms) {
    expression = new LinkedList<PolynomialTerm>();
    for (PolynomialTerm &polyTerm : terms) {
        expression->insertBack(polyTerm);
    }
    sort();
}

Polynomial::Polynomial(PolynomialTerm term) {
    expression = new LinkedList<PolynomialTerm>();
    expression->insertBack(term);
}


// Polynomial::~Polynomial() {
//     if (expression) delete expression;
//     expression = nullptr;
// }

void Polynomial::sort() {
    expression->sort([](PolynomialTerm a, PolynomialTerm b) { return a.power < b.power; });        
}

void Polynomial::print() {
    for (int i=0; i<expression->length(); i++) {
        PolynomialTerm curTerm = expression->at(i);
        std::cout << "( " << curTerm.base << "x^" << curTerm.power << ") + ";
    }
    std::cout << std::endl;
}

    // Good enough for now.
Polynomial Polynomial::add(Polynomial &other) {
    int ownIndex = 0, otherIndex = 0;
    Polynomial result;
    while (ownIndex < length() && otherIndex < other.length()) {
        PolynomialTerm ownTerm = at(ownIndex), otherTerm = other.at(otherIndex);
        NextMove nextMove = getNextTermToInsert(ownTerm, otherTerm); 
        result.append(nextMove.nextTermInResult);
        ownIndex = ownIndex + nextMove.ownIndexMove;
        otherIndex = otherIndex + nextMove.otherIndexMove;
    }
    
    if (ownIndex == length())
        other.insertRemainingTerms(otherIndex, result);
    else if (otherIndex == other.length())
        insertRemainingTerms(ownIndex, result);

    return result;
}

Polynomial Polynomial::subtract(Polynomial &other) {
    // a - b == a + (-b)
    Polynomial negativeOfOther = other.negate();
    return add(negativeOfOther);
}

Polynomial Polynomial::multiply(Polynomial &other) {
    // good old polynomial multiplication algorithm
    Polynomial product;

    for (int i=0; i<length(); i++) {
        PolynomialTerm curTerm = at(i);
        Polynomial productCurTermWithOther = multiplyPolynomialTermAndPolynomial(curTerm, other);
        product = product.add(productCurTermWithOther);
    }
    return product;
} 


Polynomial Polynomial::multiplyPolynomialTermAndPolynomial(PolynomialTerm &term, Polynomial &polynomial) {
    Polynomial product;

    for (int i=0; i<polynomial.length(); i++) {
        PolynomialTerm polyTerm = polynomial.at(i);
        product.append(polyTerm.multiply(term)); 
    }

    return product;
}


PolynomialTerm Polynomial::at(int index) {
    return expression->at(index);
}

void Polynomial::append(PolynomialTerm newTerm) {
    expression->insertBack(newTerm);
}

int Polynomial::length() {
    return expression->length();
}


NextMove Polynomial::getNextTermToInsert(PolynomialTerm &ownTerm, PolynomialTerm &otherTerm) {
    int ownIndexMove = 0, otherIndexMove = 0;
    int ownPower = ownTerm.power, otherPower = otherTerm.power;
    PolynomialTerm nextTermInResult;
    if (ownPower == otherPower) {
        nextTermInResult = ownTerm.add(otherTerm);
        ownIndexMove = 1, otherIndexMove = 1;
    }
    else if (ownPower > otherPower) {
        nextTermInResult = ownTerm;
        ownIndexMove = 1;
    }
    else if (ownPower < otherPower) {
        nextTermInResult = otherTerm;
        otherIndexMove = 1;
    }

    return NextMove(nextTermInResult, ownIndexMove, otherIndexMove);
}


void Polynomial::insertRemainingTerms(int startingFrom, Polynomial &result) {
    for (int i=startingFrom; i<length(); i++) {
        result.append(at(i));
    }
}

Polynomial Polynomial::negate() {
    Polynomial negativePoly;
    for (int i=0; i<length(); i++) {
        PolynomialTerm curTerm = expression->at(i);
        curTerm.base *= -1;
        negativePoly.append(curTerm);
    }
    return negativePoly;
}
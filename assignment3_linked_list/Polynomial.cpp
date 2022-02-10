#include "Polynomial.h"

////////////////////////// POLYNOMIAL TERM //////////////////////////////
PolynomialTerm::PolynomialTerm() {}

PolynomialTerm::PolynomialTerm(int _base, int _power): base(_base), power(_power) {}

PolynomialTerm PolynomialTerm::add(PolynomialTerm &other) {
    return PolynomialTerm(base + other.base, other.power);
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

Polynomial::~Polynomial() {
    std::cout << "Deleted expression";
    if (expression) delete expression;
    expression = nullptr;
}

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


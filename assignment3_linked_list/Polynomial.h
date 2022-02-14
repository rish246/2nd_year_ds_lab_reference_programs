#pragma once

#include "LinkedList.h"
class Polynomial;
struct PolynomialTerm {
    int base, power;
    PolynomialTerm();
    PolynomialTerm(int _base, int _power);
    PolynomialTerm add(PolynomialTerm &other);
    PolynomialTerm multiply(PolynomialTerm &other);
    void print();
};


// chose a better name for this
struct NextMove {
    PolynomialTerm nextTermInResult;
    int ownIndexMove, otherIndexMove;
    NextMove(PolynomialTerm _nextTermInResult, int _ownIndexMove, int _otherIndexMove);
};

class Polynomial {
public:
    Polynomial();
    Polynomial(std::vector<PolynomialTerm> &terms);
    Polynomial(PolynomialTerm);
    // ~Polynomial();
    void sort();
    void print();
    Polynomial add(Polynomial &other);
    Polynomial subtract(Polynomial &other);
    Polynomial multiply(Polynomial &other);
    PolynomialTerm at(int index);
    void append(PolynomialTerm newTerm); // can result in unsorted polynomial.. but for this case, it works
    int length();

private:
    LinkedList<PolynomialTerm> *expression;
    NextMove getNextTermToInsert(PolynomialTerm &ownTerm, PolynomialTerm &otherTerm);
    void insertRemainingTerms(int startingFrom, Polynomial &result);
    Polynomial negate();
    Polynomial multiplyPolynomialTermAndPolynomial(PolynomialTerm &term, Polynomial &polynomial);
};

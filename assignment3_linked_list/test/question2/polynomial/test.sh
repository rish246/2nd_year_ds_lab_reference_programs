rm polynomialTests.exe
g++ -o polynomialTests main.cpp add.cpp multiply.cpp subtract.cpp ../../utils.cpp ../../../Polynomial.cpp
./polynomialTests
//
// Created by ANDREW SMITH on 11/12/2022.
//

#include "BigInt.h"
#include "iostream"
BigInt::BigInt(long init) {
    mpz_init(_value);
    mpz_set_si(_value, init);
}

BigInt::~BigInt() {
    mpz_clear(_value);
}

void BigInt::Add(BigInt *a, BigInt *b) {
    mpz_add(_value, a->_value, b->_value);
}

void BigInt::Mult(BigInt *a, BigInt *b) {
    mpz_mul(_value, a->_value, b->_value);
}

void BigInt::Div(BigInt *a, BigInt *b) {
    mpz_div(_value, a->_value, b->_value);
}

bool BigInt::DividesInto(BigInt *other) {
    mpz_t r;
    mpz_init(r);
    mpz_mod(r, _value, other->_value);
    return mpz_cmp_si(r, 0) == 0;
}

void BigInt::Rem(BigInt *a, BigInt *b) {
//    std::cout << "a: ";
//    a->inspect();
//    std::cout << " b: ";
//    b->inspect();
//    std::cout << std::endl;
    mpz_mod(_value, a->_value, b->_value);
}

void BigInt::inspect() {
    mpz_out_str(stdout, 10, _value);
}


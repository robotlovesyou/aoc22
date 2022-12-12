//
// Created by ANDREW SMITH on 11/12/2022.
//

#ifndef AOC22_BIGINT_H
#define AOC22_BIGINT_H
#include <stdio.h>
#include <gmp.h>
#include <memory>

class BigInt {
public:
    explicit BigInt(long init);
    ~BigInt();
    BigInt(const BigInt&) = delete;
    BigInt& operator=(const BigInt&) = delete;
    void Add(BigInt* a, BigInt *b);
    void Mult(BigInt* a, BigInt *b);
    void Div(BigInt *a, BigInt *b);
    bool DividesInto(BigInt *other);
    void Rem(BigInt *a, BigInt *b);
    void inspect();

private:
    mpz_t _value{};
};

using UBigInt = std::unique_ptr<BigInt>;


#endif //AOC22_BIGINT_H

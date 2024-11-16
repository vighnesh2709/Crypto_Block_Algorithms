# Crypto_Block_Algorithms
A collection of cryptographic algorithms used in blockchain technology, including RSA, ECC, hashing, and more. Focused on learning and implementing key concepts for blockchain security and decentralization.


# RSA Encryption in C

This program implements basic RSA encryption and decryption in C. It demonstrates key generation, encryption, and decryption using the RSA algorithm.

## Features

- Key generation (public and private keys)
- Encryption with the public key
- Decryption with the private key
- Modular exponentiation and extended Euclidean algorithm

## Functions

- `eulers_totient()`: Computes Euler's Totient function.
- `encryption_exponent()`: Finds the public key exponent.
- `decryption_exponent()`: Computes the private key exponent.
- `encryption_using_public_key()`: Encrypts a message using the public key.
- `decryption_using_private_key()`: Decrypts the ciphertext using the private key.

## Compilation

```bash
gcc RSA.c
```
```bash
./a.out
```

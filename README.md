# projet_blockchain_python
Fork du Groupe Jeremy Sellem, Bastien Lesouef, Thibault Bougerol

# python_cpp
* Installation

* Compilation

* Exécution


Exemple d'utilisation d'un composant en python
Utilise pybind11
apres git clone, faire:
```
cd comp_decrypt_ecies
git submodule init
git submodule update
```

Pour compiler

```
cd comp_decrypt_ecies/cryptopp
make

cd ../
make

```

Pour utiliser
```
python3
>>> import decrypt
>>> a = decrypt.Decrypt()
>>> a.GenerateKeys()
>>> a.PrintPrivateKey()
Modulus: fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2fh
Cofactor: 1h
Coefficients
  A: 0h
  B: 7h
Base Point
  x: 79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798h
  y: 483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8h
Public Point
  x: 6f5bc72efafd500d0f738b238a468765e62c916315f43b87c7c32e8a581fd66ah
  y: 4846ece5e5f59d8ab07d7525f75bc593675130d7821094ae99bd094bf4c5724dh
Private Exponent (multiplicand): 
  829148574f6d17b772395032c2e0f8cfc998cae838708acc9e428f2001ad946bh
>>> 
KeyboardInterrupt
>>> b = "829148574f6d17b772395032c2e0f8cfc998cae838708acc9e428f2001ad946b"
>>> b = int(b, 16)
>>> from coincurve import PrivateKey
>>> k1 = PrivateKey.from_int(b)
>>> pkey = k1.public_key.format(False).hex()
>>> print(pkey)
046f5bc72efafd500d0f738b238a468765e62c916315f43b87c7c32e8a581fd66a4846ece5e5f59d8ab07d7525f75bc593675130d7821094ae99bd094bf4c5724d
>>> 

```

* Google Cloud token : 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

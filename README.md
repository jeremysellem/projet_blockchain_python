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
  x: f49e3ab38ed819cb9a190f39a18583c5f04868a4a384e7a9c29bbb29297f212bh
  y: 8700dfa3e3904089d1b071a8e4e6540c117fe597e92036eaee079fe2d557332dh
Private Exponent (multiplicand): 
  9b80bd06fd91a9bf3a1e16f3e4a25bd2500c8f8f45ca248bfebd03b2e3609cdfh
>>> quit()

```

* Google Cloud token : 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

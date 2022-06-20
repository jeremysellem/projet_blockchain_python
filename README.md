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
>>> a.Encrypt("hello")
Plain text Message : hello
Encrypted Message : X8-iR+hPtYn#i,*$!ul;+Pd))[2"QVO1"CP
z
Encrypted Message (std::hex) : 45838ffffffaaffffffa4fffffffeffffffabffffff82ffffff822dffffff8969fffffffbe522b68fffffff4ffffffb2ffffffe2ffffffde5074596e23692cffffffd3ffffffe1ffffffb6ffffffe7f2affffff822421ffffffb075ffffffe66cffffff89ffffffbfffffffd5fffffffb1affffff9313bffffffb62bffffff8bffffffb75064ffffffcc292945bffffff9dffffffd3ffffffeeffffffdc32ffffffe9ffffff940fffffffaffffffe32251fffffff4ffffffe9ffffff9156ffffff92ffffffb14f312243ffffff8d50ffffff8daffffffb97affffffd7f
Encrypted Message (HexEncoder) : 045838AAA4FEAB82822D89690FBE522B68F4B2E2DE5074596E23692CD3E1B6E70F2A822421B075E66C89BFD5FB1A93013BB62B8BB75064CC2929045B9DD3EEDC32E99400FAE32251F4E9915692B14F3122438D508D0AB97AD70F
>>> a.DecryptText()
Decrypted Message : hello
>>> 

```

* Google Cloud token : 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

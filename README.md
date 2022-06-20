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
>>> a = decrypt.Chiffrage()
>>> a.encrypt_decrypt("Hello ca va")
Encrypted Message (std::hex) : 4ffffffbcffffffd2ffffffbaffffffd0ffffff98ffffffbdffffffcd2dffffffd0ffffff8b38ffffffa8ffffffda6d7e164effffffd1fffffff3166136d78ffffffa5ffffffb4ffffffdfffffffe670fffffff12144fffffff91effffff83767cffffffc7ffffffdc2b78ffffffaeffffffaa7b3bffffff83fffffff67fffffffb2ffffffca757bffffffe9ffffffea20ffffffe5ffffffafffffffdbffffffe7ffffffe2ffffffe41f4428ffffffa9ffffff8215ffffffac2228ffffff8c7bffffff906dffffff8e61ffffffebfffffff6ffffffb53b7a6f4a6fcffffff904b910fffffff71273efffffff652
Encrypted Message (HexEncoder) : 04BCD2BAD098BDCD2DD08B38A8DA6D7E164ED1F30166136D78A5B4DFE670F12144F91E83767CC7DC2B78AEAA7B3B83F67FB2CA757BE9EA20E5AFDBE7E2E41F4428A98215AC22288C7B906D8E61EBF6B53B7A6F4A6F0C904B0910F701273EF652
Decrypted Message : Hello ca va
>>> 
```

* Google Cloud token : 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

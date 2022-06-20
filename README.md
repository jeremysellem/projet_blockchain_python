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
>>> a.encrypt_decrypt("Message")
Encrypted Message : H[3j)*pI y
c']0:EoC}
         61m$bGPD*-{P,
Da4'
Encrypted Message (std::hex) : 4ffffffcf48ffffffa95bffffff9efffffff4ffffffbc1833fffffff9ffffffb36affffffdaffffffd7ffffffefffffffb7ffffffd629ffffffe92a70ffffffc94920ffffffa279a1363ffffffccffffffe60ffffffc6275d7ffffffa2fffffffcffffffc630ffffffd03a451b1678617ffffff99ffffff9cffffffbaffffffea6f437dcffffffe61736317f6d24ffffffd762ffffffa7ffffff8f47ffffff91ffffffdd1150442a2d7b50ffffff9bffffffecfffffff5ffffffd92cffffffbba4461ffffff97ffffffee341f27
Encrypted Message (HexEncoder) : 04CF48A95B9EF4BC1833F9B36ADAD7EFB7D629E92A70C94920A2790A1363CCE600C6275D07A2FCC630D03A451B16780617999CBAEA6F437D0CE61736317F6D24D762A78F4791DD1150442A2D7B509BECF5D92CBB0A446197EE341F27
Decrypted Message : Message
>>> 
```

* Google Cloud token : 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

# projet_blockchain_python
Fork du Groupe Jeremy Sellem, Bastien Lesouef, Thibault Bougerol

# python_cpp
* Installation
![Image text](images/Google_Cloud_Platform/git_commandes.png)
* Compilation
![Image text](images/Google_Cloud_Platform/Compilation.png)
* Exécution
![Image text](images/Google_Cloud_Platform/Execution.png)

Exemple d'utilisation d'un composant en python
Utilise pybind11
apres git clone, faire:
```
cd python_cpp
git submodule init
git submodule update
```

Pour compiler

```
cd hello
make
```

Pour utiliser
```
python3
>>> import hello_component
>>> hello_component.greet()
'hello, world'
>>> hello_component.getVersion()
'1.0'
>>> 
```

* Google Cloud token : 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

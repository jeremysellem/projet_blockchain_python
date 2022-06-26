#include <pybind11/pybind11.h>
#include "micro-ecc/uECC.h"
#include "cryptopp/eccrypto.h"
#include "cryptopp/base64.h"
#include "cryptopp/filters.h"
#include "cryptopp/rsa.h"
#include "cryptopp/cryptlib.h"
#include "cryptopp/poly1305.h"
#include "cryptopp/osrng.h"
#include "cryptopp/aes.h"
#include "cryptopp/hex.h"
#include "cryptopp/integer.h"
#include "cryptopp/oids.h"
#include "cryptopp/files.h"
#include <iostream>
using namespace CryptoPP;

class Decrypt {
    private:
        std::string encryptedtext;
        std::string DecryptorfilePublic = "ECIES_PublicKey.key"; //Chemin vers le fichier de stockage de la cle publique
        std::string DecryptorfilePrivate = "ECIES_PrivateKey.key"; //Chemin vers le fichier de stockage de la cle privee
        AutoSeededRandomPool prng;
        ECIES < ECP > ::PrivateKey privateKey;
        ECIES < ECP > ::PublicKey publicKey;
        ECIES < ECP > ::Encryptor e0;
        std::string em0; // Encrypted message
        std::string dm0; // Decrypted message
    
    public:
        Decrypt() {}
        ~Decrypt() {}

        const std::string & getEncryptedText() const {
            return encryptedtext;
        }

        const std::string & getPublicFile()const{
    	   return DecryptorfilePublic;
        }

        const std::string & getPrivateFile() const{
        	return DecryptorfilePrivate;
        }
        
        void setEncryptedMessage(std::string message){
            em0 = message;
        }

        void SavePrivateKey(const CryptoPP::PrivateKey & key,
            const std::string & file) {
            CryptoPP::FileSink sink(file.c_str());
            key.Save(sink);
        }

        void SavePublicKey(const CryptoPP::PublicKey & key,
            const std::string & file) {
            CryptoPP::FileSink sink(file.c_str());
            key.Save(sink);
        }

        void LoadPrivateKey(CryptoPP::PrivateKey & key,
            const std::string & file) {
            CryptoPP::FileSource source(file.c_str(), true);
            key.Load(source);
        }

        void Generate_keys(){
            // Curve Key Generation
            privateKey.Initialize(prng, ASN1::secp256k1()); //Generation courbe ECIES
            privateKey.MakePublicKey(publicKey); //Generation cle publique
            SavePublicKey(publicKey, DecryptorfilePublic); //Sauvegarde cle publique
            SavePrivateKey(privateKey, DecryptorfilePrivate); //Sauvegarde cle privee
    	}

        void DecryptText(){
            ECIES < ECP > ::Decryptor d0(privateKey);
            
            StringSource ss2(em0, true, new PK_DecryptorFilter(prng, d0, new StringSink(dm0)));
            plaintext = dm0;

            std::cout << "Decrypted Message : " << dm0 << std::endl;
        }
};

namespace py = pybind11;

PYBIND11_MODULE(decrypt, greetings) {
    greetings.doc() = "decrypt 1.0";
    py::class_ < Decrypt > (greetings, "Decrypt", py::dynamic_attr())
        .def(py::init())
        .def("LoadPublicKey", & Decrypt::LoadPublicKey)
        .def("GetPublicFile", & Decrypt::getPublicFile)
        .def("LoadPrivateKey", & Decrypt::LoadPrivateKey)
        .def("SavePublicKey", & Decrypt::SavePublicKey)
        .def("SavePriavteKey", & Decrypt::SavePrivateKey)
    	.def("GenerateKeys", & Decrypt::Generate_keys)
    	.def("Encrypt", & Decrypt::Encrypt)
        .def("SetEncryptedMessage", & Decrypt::setEncryptedMessage)
        .def("DecryptText", & Decrypt::DecryptText);
}

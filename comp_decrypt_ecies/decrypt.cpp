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
#include <sstream>
using namespace CryptoPP;

class Decrypt {
    private:
        std::string encryptedtext;
	std::string PrivateKeyString;
	std::string PublicKeyString1;
	std::string PublicKeyString2;
        std::string plaintext;
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
	
	ECIES < ECP > ::PrivateKey & GetPrivateKey(){
		return privateKey;
	}
	
	ECIES < ECP > ::PublicKey & GetPublicKey(){
		return publicKey;
	}

        void DecryptText(std::string message){
	    std::string em0;
	    StringSource ss4(message, true, new HexDecoder(new StringSink(em0)));
            ECIES < ECP > ::Decryptor d0(privateKey);
            
            StringSource ss2(em0, true, new PK_DecryptorFilter(prng, d0, new StringSink(dm0)));
            plaintext = dm0;

            std::cout << "Decrypted Message : " << dm0 << std::endl;
        }
    
        void PrintPrivateKey(){
		// Group parameters
		ECIES < ECP > :: PrivateKey key = GetPrivateKey();
    		const DL_GroupParameters_EC<ECP>& params = key.GetGroupParameters();
    		// Base precomputation (for public key calculation from private key)
    		const DL_FixedBasePrecomputation<ECPPoint>& bpc = params.GetBasePrecomputation();
    		// Public Key (just do the exponentiation)
    		const ECPPoint point = bpc.Exponentiate(params.GetGroupPrecomputation(), key.GetPrivateExponent());

    		std::cout << "Modulus: " << std::hex << params.GetCurve().GetField().GetModulus() << std::endl;
    		std::cout << "Cofactor: " << std::hex << params.GetCofactor() << std::endl;

    		std::cout << "Coefficients" << std::endl;
    		std::cout << "  A: " << std::hex << params.GetCurve().GetA() << std::endl;
    		std::cout << "  B: " << std::hex << params.GetCurve().GetB() << std::endl;

    		std::cout << "Base Point" << std::endl;
    		std::cout << "  x: " << std::hex << params.GetSubgroupGenerator().x << std::endl;
    		std::cout << "  y: " << std::hex << params.GetSubgroupGenerator().y << std::endl;

    		std::cout << "Public Point" << std::endl;
    		std::cout << "  x: " << std::hex << point.x << std::endl;
    		std::cout << "  y: " << std::hex << point.y << std::endl;
		std::stringstream ss1;
		ss1 << std::hex << point.x;
		std::stringstream ss2;
		ss2 << std::hex << point.y;
		PublicKeyString1 = ss1.str();
		PublicKeyString2 = ss2.str();

    		std::cout << "Private Exponent (multiplicand): " << std::endl;
    		std::cout << "  " << std::hex << key.GetPrivateExponent() << std::endl;
		std::stringstream ss;
		ss << std::hex << key.GetPrivateExponent();
		PrivateKeyString = ss.str();
	}

	std::string GetPrivateKeyString(){
		return PrivateKeyString;
	}
	
	std::string GetPublicKeyString1(){
		return PublicKeyString1;
	}

	std::string GetPublicKeyString2(){
		return PublicKeyString2;
	}

	void PrintPublicKey()
	{
		// Group parameters
		ECIES < ECP > :: PublicKey key = GetPublicKey();
    		const DL_GroupParameters_EC<ECP>& params = key.GetGroupParameters();
    		// Public key
    		const ECPPoint& point = key.GetPublicElement();
    
   		std::cout << "Modulus: " << std::hex << params.GetCurve().GetField().GetModulus() << std::endl;
    		std::cout << "Cofactor: " << std::hex << params.GetCofactor() << std::endl;
    
    		std::cout << "Coefficients" << std::endl;
    		std::cout << "  A: " << std::hex << params.GetCurve().GetA() << std::endl;
    		std::cout << "  B: " << std::hex << params.GetCurve().GetB() << std::endl;
    
    		std::cout << "Base Point" << std::endl;
    		std::cout << "  x: " << std::hex << params.GetSubgroupGenerator().x << std::endl;
    		std::cout << "  y: " << std::hex << params.GetSubgroupGenerator().y << std::endl;
    
   		std::cout << "Public Point" << std::endl;
    		std::cout << "  x: " << std::hex << point.x << std::endl;
    		std::cout << "  y: " << std::hex << point.y << std::endl;	
	}
};

namespace py = pybind11;

PYBIND11_MODULE(decrypt, greetings) {
    greetings.doc() = "decrypt 1.0";
    py::class_ < Decrypt > (greetings, "Decrypt", py::dynamic_attr())
        .def(py::init())
        .def("GetPublicFile", & Decrypt::getPublicFile)
        .def("LoadPrivateKey", & Decrypt::LoadPrivateKey)
        .def("SavePublicKey", & Decrypt::SavePublicKey)
        .def("SavePriavteKey", & Decrypt::SavePrivateKey)
    	.def("GenerateKeys", & Decrypt::Generate_keys)
        .def("SetEncryptedMessage", & Decrypt::setEncryptedMessage)
        .def("PrintPrivateKey", & Decrypt::PrintPrivateKey)
	.def("GetPrivateKey", & Decrypt::GetPrivateKey)
	.def("PrintPublicKey", & Decrypt::PrintPublicKey)
	.def("GetPrivateKeyString", & Decrypt::GetPrivateKeyString)
	.def("GetPublicKeyString1", & Decrypt::GetPublicKeyString1)
	.def("GetPublicKeyString2", & Decrypt::GetPublicKeyString2)
        .def("DecryptText", & Decrypt::DecryptText);
}

#Import packages
import decrypt
from coincurve import PrivateKey

#Initialize component
a = decrypt.Decrypt()
a.GenerateKeys()
a.PrintPrivateKey()
b = a.GetPrivateKeyString()[:-1]
c = a.GetPublicKeyString1()[:-1] + a.GetPublicKeyString2()[:-1]

#coincurve key
k1 = PrivateKey.from_int(int(b, 16))
pkey = k1.public_key.format(False).hex()

#Test
print("-----------Coincurve Package Public Key----------")
print(pkey)
print("-------------Component Public Key----------------")
print(c)

if pkey == "04"+c:
	print("TEST OK")
else : 
	print("KEYS NOT EQUAL")

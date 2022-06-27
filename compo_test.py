#Import components
import projet_blockchain_python.comp_decrypt_ecies.decrypt as decrypt
import compo_flo.chiffrage_component.chiffrage_component as encrypt

#Initialization
message = "Hello"
d = decrypt.Decrypt()
d.GenerateKeys()
d.PrintPrivateKey()

#Encryt with Decryptor Public Key
e = encrypt.Chiffrage()
e.encrypt(message, d.GetPublicFile())

#Decrypt encrypted message with Decryptor Private Key
#d.SetEncryptedMessage(e.getEncryptedText())
d.DecryptText(e.getEncryptedText())
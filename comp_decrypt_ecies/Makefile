CPPFLAGS += -I /usr/include/python3.9
LIBS=-lpython3.9

COMPOSANT = decrypt

LIB_ECC = micro-ecc/uECC

LIB_ECCRYPTO = cryptopp/eccrypto
LIB_B64 = cryptopp/base64
LIB_ASN = cryptopp/asn
LIB_QUEUE = cryptopp/queue
LIB_BASE = cryptopp/basecode
LIB_FILTERS = cryptopp/filters
LIB_RSA = cryptopp/rsa
LIB_CRYPTLIB = cryptopp/cryptlib
LIB_POLY = cryptopp/poly1305
LIB_OSRNG = cryptopp/osrng
LIB_HEX = cryptopp/hex
LIB_INT = cryptopp/integer
LIB_FILES = cryptopp/files
LIB_RANDPOOL = cryptopp/randpool
LIB_HMAC = cryptopp/hmac
LIB_ITER = cryptopp/iterhash

LIBSO = ${COMPOSANT}.so
LIBSO_OBJS = ${COMPOSANT}.o ${LIB_CRYPTLIB}.o ${LIB_ECCRYPTO}.o ${LIB_BASE}.o ${LIB_QUEUE}.o ${LIB_B64}.o ${LIB_ASN}.o ${LIB_FILTERS}.o ${LIB_RSA}.o  ${LIB_POLY}.o ${LIB_OSRNG}.o ${LIB_HEX}.o ${LIB_INT}.o ${LIB_FILES}.o ${LIB_RANDPOOL}.o ${LIB_HMAC}.o ${LIB_ITER}.o

include ../gcc.mk
include ../pybind11.mk


all: $(LIBSO)
clean:
	rm -f ${LIBSO}  ${LIBSO_OBJS}


${DESTINATION_LIBSO}: ${LIBSO}
	cp $< $@

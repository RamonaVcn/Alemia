#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"openssl/des.h"
#include"openssl/rand.h"
#include"openssl/aes.h"
#include"openssl/sha.h"
#include"openssl/evp.h"
#include"openssl/bn.h"
#include"openssl/applink.c"
#include"openssl/rsa.h"
#include"openssl/pem.h"

using namespace std;

unsigned char* calculcate_hash_EVP(unsigned char * plaintext,int size_plaintext)
{
	
	unsigned int size_digest = 0;
	EVP_MD_CTX* ctx = EVP_MD_CTX_new();
	EVP_DigestInit(ctx, EVP_sha3_256());
	EVP_DigestUpdate(ctx, plaintext, size_plaintext);

	unsigned char* output = new unsigned char[32];
	EVP_DigestFinal(ctx, output, &size_digest);


	return output;
}
void encrypt_decrypt_block_ciphers_EVP(unsigned char* key, unsigned char* iv, const EVP_CIPHER* tip_criptare, int flag_enc_dec,
	unsigned char* input, unsigned char* output, int input_size, int& out_size)
{
	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
	EVP_CipherInit(ctx, tip_criptare, key, iv, flag_enc_dec);
	EVP_CipherUpdate(ctx, output, &out_size, input, input_size);
	int copy_out_size = out_size;
	EVP_CipherFinal(ctx, output + copy_out_size, &out_size);
	out_size = out_size + copy_out_size;
}
void call_evp_functions()
{
	FILE* fin = fopen("output.txt", "wb");

	unsigned char* cleartext = new unsigned char[32];
	cout << "introduceti textul";
	cin >> cleartext;
	

	unsigned char* pass = new unsigned char[32];
	cout << "introduceti cheia";
	cin >> pass;

	unsigned char* digest = new unsigned char[SHA512_DIGEST_LENGTH];
	digest = calculcate_hash_EVP(cleartext, strlen((char*)pass));

	unsigned char* MasterIv = new unsigned char[16];
	memcpy(MasterIv, digest, 16);

	unsigned char* MasterKey = new unsigned char[32];
	memcpy(MasterKey, digest + 16, 32);



	unsigned char* iv = new unsigned char[16];
	unsigned char* K = new unsigned char[32];
	RAND_bytes(iv, 16);
	RAND_bytes(K, 32);
	
	unsigned char* concatIvK = new unsigned char[48];
	memcpy(concatIvK,iv,16);
	memcpy(concatIvK + 16, K, 32);


	unsigned char* cyphertext = new unsigned char[48];
	int size_out = 0;


	encrypt_decrypt_block_ciphers_EVP(MasterKey, MasterIv, EVP_aes_256_cbc(), AES_ENCRYPT, concatIvK, cyphertext, 48, size_out);
	fwrite(cyphertext, 1, 48, fin);

	encrypt_decrypt_block_ciphers_EVP(K, iv, EVP_aes_256_cbc(), AES_ENCRYPT, cleartext, cyphertext, strlen((char*)cleartext), size_out);
	fwrite(cyphertext, 1, size_out, fin);

	fclose(fin);
	//memset(cleartext, 0, file_size);
	//file_size = 0;
	//encrypt_decrypt_block_ciphers_EVP(key, iv2, EVP_aes_256_cbc(), AES_DECRYPT, cyphertext, cleartext, size_output, file_size);


}


void main()
{
	call_evp_functions();
}
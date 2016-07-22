#include "clocks.h"
#include <openssl/crypto.h>
#include <openssl/sha.h>

#define SIZE_MESSAGE 1024
int main()
{
	int i;
	const int BENCH = 1500;
	unsigned char message[SIZE_MESSAGE];
	unsigned char digest[SHA256_DIGEST_LENGTH];

	printf("===== HASH =====\n");
	printf("%s\n",SSLeay_version(SSLEAY_VERSION));
	printf("%s\n",SSLeay_version(SSLEAY_DIR));
	
	for(i=0;i<SIZE_MESSAGE;i++)
	{
		message[i] = rand();
	}
	
	printf("Message:\n");
	for(i=0;i<SIZE_MESSAGE;i++)
	{
		printf("%02x",message[i]);
	}
	printf("\n");
	
	CLOCKS(SHA256(message,SIZE_MESSAGE,digest));
	oper_second(SHA256(message,SIZE_MESSAGE,digest));
	
	printf("Digest:\n");
	for(i=0;i<SHA256_DIGEST_LENGTH;i++)
	{
		printf("%02x",digest[i]);
	}
	printf("\n");
	
	
	
	return 0;
}

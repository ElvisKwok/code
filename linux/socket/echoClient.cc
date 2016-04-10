#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
using namespace std;

#define ERR_EXIT(m) \
	do { \
		perror(m); \
		exit(EXIT_FAILURE); \
	} while (0)

int main() {
	int sockfd = socket(PF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		ERR_EXIT("socket error");
	
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(5188);
    //servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (connect(sockfd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) == -1)
		ERR_EXIT("connect error");

	char sendBuf[512];
	char recvBuf[512];
	while (fgets(sendBuf, sizeof(sendBuf), stdin) != NULL) {
		if (write(sockfd, sendBuf, strlen(sendBuf)) == -1)
			ERR_EXIT("write socket error");
		int readBytes = read(sockfd, recvBuf, sizeof(recvBuf));
		if (readBytes == 0) {
			cerr << "server connect closed.." << endl;
			break;
		}
		else if (readBytes == -1)
			ERR_EXIT("read socket error");
		cout << "from server: " << recvBuf;
		memset(sendBuf, 0, sizeof(sendBuf));
		memset(recvBuf, 0, sizeof(recvBuf));
	}
	close(sockfd);

	return 0;
}

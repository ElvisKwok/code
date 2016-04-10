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
	int listenfd = socket(PF_INET, SOCK_STREAM, 0);
	if (listenfd == -1)
		ERR_EXIT("socket error");
	
	struct sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(5188);
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY);
	//servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	if (bind(listenfd, (const struct sockaddr *)&servAddr, sizeof(servAddr)) == -1)
		ERR_EXIT("bind error");
	if (listen(listenfd, SOMAXCONN) <0)
		ERR_EXIT("listen error");

	char buf[512];
	int readBytes;
	struct sockaddr_in clientAddr;
	socklen_t addrLen = sizeof(clientAddr);
	while (true) {
		int clientfd = accept(listenfd, (struct sockaddr*)&clientAddr, &addrLen);
		if (clientfd == -1)
			ERR_EXIT("accept error");
		cout << "client information: " << inet_ntoa(clientAddr.sin_addr)
			 << ", " << ntohs(clientAddr.sin_port) << endl;
		memset(buf, 0, sizeof(buf));
		while ((readBytes = read(clientfd, buf, sizeof(buf))) > 0) {
			cout << buf;
			if (write(clientfd, buf, readBytes) == -1)
				ERR_EXIT("write socket error");
			memset(buf, 0, sizeof(buf));
		}
		if (readBytes == 0) {
			cerr << "client connect closed.." << endl;
			close(clientfd);
		}
		else if (readBytes == -1)
			ERR_EXIT("read socket error");
	}
	close(listenfd);

	return 0;
}

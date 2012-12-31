#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


static int dstSocket;
void tcp_start()
{
  /* IP アドレス、ポート番号、ソケット */
  char destination[80];
  unsigned short port = 9876;
  /* sockaddr_in 構造体 */
  struct sockaddr_in dstAddr;
  int status;
  int numsnt;

  /************************************************************/
  /* 相手先アドレスの入力 */
//  printf("Connect to ? : (name or IP address) ");
//  scanf("%s", destination);
  strcpy(destination, "127.0.0.1");

  /* sockaddr_in 構造体のセット */
  memset(&dstAddr, 0, sizeof(dstAddr));
  dstAddr.sin_port = htons(port);
  dstAddr.sin_family = AF_INET;
  dstAddr.sin_addr.s_addr = inet_addr(destination);
 
  /* ソケット生成 */
  dstSocket = socket(AF_INET, SOCK_STREAM, 0);

  /* 接続 */
  printf("Trying to connect to %s: \n", destination);
  connect(dstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr));
}

void tcp_printf(char *send_buf, int size)
{
    send(dstSocket, send_buf, size, 0);
}

void tcp_end(void)
{
  /* ソケット終了 */
  close(dstSocket);
}



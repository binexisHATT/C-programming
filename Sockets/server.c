#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

int main () {
    
    char msg[50] = "Successfully connected to server";
    
    //**|creating socket|
    
    int serv_soc;
    serv_soc = socket(AF_INET, SOCK_STREAM, 0);
    
    //**|defining sockets address|
    
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(1234);
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    
    //**|bind our socket| 
    
    bind(serv_soc, (struct* sockaddr) &serv_addr, sizeof(serv_addr));
    
    //**|listen for maximum 5 incomming connections|
    
    listen(serv_soc, 5);
    
    //**|accept incoming connections|
    int conn;
    conn = accept(serv_soc, NULL, NULL);
    
    //**|send a message to client|
    send(conn, msg, sizeof(msg), 0);
    
  return 0;
}

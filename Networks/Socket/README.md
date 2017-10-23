# Socket Programming

## Socket()
Get file descriptor of network socket

## Bind()
Attach to an IP and Port to a server

## Listen()
Wait for a connection
```c
int Accept(int socket, (struct sockaddr*) &server_addr, socklen_t len);
```

## Send() and Recv()
Send(), Recv(), Read(), Write()

## Close()
Good bye

## References:
- [Beej's Guide to Network Programming Using Internet Sockets](http://beej.us/guide/bgnet/output/print/bgnet_A4.pdf)
- [TheSecurityTube Playlist](https://www.youtube.com/watch?v=eVYsIolL2gE&list=PL0JmC-T2nhdgJ2Lw5YdufR8MffaQdAvEf&index=1)

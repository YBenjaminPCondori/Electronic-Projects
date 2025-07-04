import socket
import datetime

clientSocket = socket.AF_INET, socket.SOCK_STREAM;

clientSocket.connect(("127.0.0.1"));

data = "Hello Server!";

clientSocket.send(data.encode());

dataFromServer = clientSocket.rec(1024);

print(dataFromServer.decode());

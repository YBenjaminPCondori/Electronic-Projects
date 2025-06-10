import cv2
import socket
import pickle
import threading
import numpy as np
import os

server_ip = '34.147.169.216' #External IP Address of GCP Virutal Linux Instance
server_port = 6969
feedback_port = 6970  
sender_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

def feedbackfromreciever():
    feedback_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    feedback_socket.bind(('', feedback_port))  
    print("Listening for feedback...")
    while True:
        feedback_data, _ = feedback_socket.recvfrom(1024)
        print(feedback_data.decode('utf-8'))  

cap = cv2.VideoCapture(0)  e

print("Video frames from webcam transmitting (Loading now...)")
frame_sent = False 

while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        break

    _, buffer = cv2.imencode('.jpg', frame)
    data = pickle.dumps(buffer)

    sender_socket.sendto(data, (server_ip, server_port))

    if not frame_sent:
        feedback_thread = threading.Thread(target=feedbackfromreciever, daemon=True)
        feedback_thread.start()
        frame_sent = True

    cv2.imshow("Sending Video", frame)

    if cv2.waitKey(1) & 0xFF == ord('a'):
        break

cap.release()
cv2.destroyAllWindows()
sender_socket.close()

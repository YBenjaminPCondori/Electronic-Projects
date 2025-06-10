import cv2
import socket
import pickle
import numpy as np
import os
 
lower_red1 = np.array([0, 100, 100], dtype="uint8")
upper_red1 = np.array([10, 255, 255], dtype="uint8")
lower_red2 = np.array([170, 100, 100], dtype="uint8")
upper_red2 = np.array([180, 255, 255], dtype="uint8")
 
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
server_ip = '0.0.0.0'  
server_port = 6969
s.bind((server_ip, server_port))
 
s_send = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
 
print("Server is ready to receive video frames...")
 
prev_cx, prev_cy = None, None
 
while True:
    try:
        packet, client_address = s.recvfrom(1000000)
        print(f"Frame received from {client_address}")
        frame_data = pickle.loads(packet)
        frame = cv2.imdecode(frame_data, cv2.IMREAD_COLOR)
 
        frame_resized = cv2.resize(frame, (640, 480))
        hsv = cv2.cvtColor(frame_resized, cv2.COLOR_BGR2HSV)
 
        mask1 = cv2.inRange(hsv, lower_red1, upper_red1)
        mask2 = cv2.inRange(hsv, lower_red2, upper_red2)
        mask = cv2.bitwise_or(mask1, mask2)
 
        _, contours, _ = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
 
        if contours:
            largest_contour = max(contours, key=cv2.contourArea)
            moments = cv2.moments(largest_contour)
            if moments["m00"] != 0:
                cx = int(moments["m10"] / moments["m00"])
                cy = int(moments["m01"] / moments["m00"])
 
 
                cv2.drawContours(frame_resized, [largest_contour], -1, (0, 255, 0), 2)
                cv2.circle(frame_resized, (cx, cy), 5, (255, 0, 0), -1)
 
                if prev_cx is not None and prev_cy is not None:
                    motion_x = cx - prev_cx
                    motion_y = cy - prev_cy
                    print(f"Motion: X={motion_x}, Y={motion_y}")
 
                    feedback = f"Motion: X={motion_x}, Y={motion_y}"
                    s_send.sendto(feedback.encode('utf-8'), (client_address[0], send_port))
 
                prev_cx, prev_cy = cx, cy
 
        cv2.imshow("Tracking Red Dot", frame_resized)
 
        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    except Exception as e:
        print(f"Error: {e}")
 
s.close()
s_send.close()
cv2.destroyAllWindows()
 
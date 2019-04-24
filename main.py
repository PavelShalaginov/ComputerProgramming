import cv2

# Load the cascade
face_cascade = cv2.CascadeClassifier('haarcascade_frontalface_alt2.xml')

# To capture video from webcam. 
cap = cv2.VideoCapture(0)
# To use a video file as input 
cap = cv2.VideoCapture('BTC.mp4')
fps = int(cap.get(cv2.CAP_PROP_FPS))
cnt = 0
pts = 0.2
while True:
    # Read the frame
    _, img = cap.read()
    #####################
    cnt=cnt+1
    height,width,_=img.shape
    ####################
    # Convert to grayscale
    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    # Detect the faces
    faces = face_cascade.detectMultiScale(gray, 1.2, 3)
    # Draw the rectangle around each face
    _cnt = 0;
    img_BB=img.copy()
    for (x, y, w, h) in faces:
        x = int(x - pts*w)
        w = int(w + 2*pts*w)
        y = int(y - pts*h)
        h = int(h + 2*pts*h)
        x_min = max(x,1)
        y_min = max(y,1)
        x_max = min(x+w,width)
        y_max = min(y+h,height)
        #print (type(x))
        if cnt%fps == 0:
            _img=img[y_min:y_max,x_min:x_max]
            if _img.shape[0]>0 and _img.shape[1]>0:
                print(cv2.imwrite("/home/hoangduong/Downloads/FaceDetection/faces/img_"+str(cnt)+'_'+str(_cnt)+'.bmp',_img))
            _cnt = _cnt + 1;
        cv2.rectangle(img_BB, (x_min, y_min), (x_max, y_max), (0, 255, 0), 2)

    #Display
    #cv2.imshow('img', img_BB)
    
    # Stop if escape key is pressed
    k = cv2.waitKey(30) & 0xff
    if k==27:
        break
# Release the VideoCapture object
cap.release()
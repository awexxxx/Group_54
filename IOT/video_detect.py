from ultralytics import YOLO
import cv2
import time
import os

# Load a model
model = YOLO("C://Users//DELL//Desktop//best1.pt")  # load a pretrained model (recommended for training)qq

cap = cv2.VideoCapture("http://192.168.8.1:8083/?action=stream") # read video from the car
output_directory = "output_images"  # Specify the directory in which to save the image

# Make sure the output directory exists
if not os.path.exists(output_directory):
    os.makedirs(output_directory)

# Loop through the video frames
while cap.isOpened():
    # Read a frame from the video
    success, frame = cap.read()

    if success:
        # Run YOLOv8 inference on the frame
        results = model.predict(frame, save=True, classes=[0,1,2], conf=0.4) 

        # Visualize the results on the frame
        annotated_frame = results[0].plot()

        # Display the annotated frame
        cv2.imshow("Detection Video Window", annotated_frame)

        current_time = time.time()

        # save the original video picture
        original_image_filename = f"{output_directory}/original_image_{int(current_time)}.png"
        print(f"Saved original image: {original_image_filename}")

        # save the annotated video picture
        annotated_image_filename = f"{output_directory}/annotated_image_{int(current_time)}.png"
        print(f"Saved annotated image: {annotated_image_filename}")

        # compare the original video picture and the annotated video picture
        if False in (frame == annotated_frame):

            # if the two pictures are different, save the detected video picture
            different_image_filename = f"{output_directory}/detected_image_{int(current_time)}.png"

            cv2.imwrite(different_image_filename, annotated_frame)

            print(f"Saved different image: {different_image_filename}")

        # Break the loop if 'q' is pressed
        if cv2.waitKey(1) & 0xFF == ord("q"):
            break
    else:
        # Break the loop if the end of the video is reached
        break

# Release the video capture object and close the display window
cap.release()
cv2.destroyAllWindows()

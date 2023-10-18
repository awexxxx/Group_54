from ultralytics import YOLO

# Load a model
model = YOLO("C://Users//DELL//Desktop//best1.pt")

img_path = "C://Users//DELL//Desktop//D&B//image"
results = model.predict(img_path,save=True,classes=[0,1,2],conf=0.5)
import os
from PIL import Image, ImageTk
import tkinter as tk

class ImageComparator:
    def __init__(self, dir1, dir2):
        self.files1 = sorted(os.listdir(dir1))
        self.files2 = sorted(os.listdir(dir2))
        self.index = 0

        self.root = tk.Tk()
        self.root.title("Comparison")
        self.root.geometry("1150x500")  # Adjust the window size as needed

        self.frame1 = tk.Frame(self.root)
        self.frame1.grid(row=0, column=0, padx=10, pady=10)

        self.label_info1 = tk.Label(self.frame1, text="Before detection")
        self.label_info1.grid(row=0, column=0)
        self.label_info2 = tk.Label(self.frame1, text="After detection")
        self.label_info2.grid(row=0, column=1)


        self.image1_path = os.path.join(dir1, self.files1[self.index])
        self.image2_path = os.path.join(dir2, self.files2[self.index])


        self.image1 = Image.open(self.image1_path) 
        self.image2 = Image.open(self.image2_path)
  

        self.image1 = self.image1.resize((540, 360))
        self.image2 = self.image2.resize((540, 360))


        self.photo1 = ImageTk.PhotoImage(self.image1)
        self.photo2 = ImageTk.PhotoImage(self.image2)


        self.label1 = tk.Label(self.frame1, image=self.photo1)
        self.label1.grid(row=1, column=0, padx=10, pady=5)

        self.label2 = tk.Label(self.frame1, image=self.photo2)
        self.label2.grid(row=1, column=1, padx=10, pady=5)

        self.button_next = tk.Button(self.frame1, text="Next", command=self.next_images)
        self.button_next.grid(row=2, column=0, columnspan=2, padx=10, pady=5)

    def next_images(self):
        self.index += 1

        if self.index >= len(self.files1) or self.index >= len(self.files2):
            return

        self.image1_path = os.path.join(dir1, self.files1[self.index])
        self.image2_path = os.path.join(dir2, self.files2[self.index])

        self.image1 = Image.open(self.image1_path)
        self.image2 = Image.open(self.image2_path)

        self.image1 = self.image1.resize((540, 360))
        self.image2 = self.image2.resize((540, 360))

        self.photo1 = ImageTk.PhotoImage(self.image1)
        self.photo2 = ImageTk.PhotoImage(self.image2)

        self.label1.configure(image=self.photo1)
        self.label2.configure(image=self.photo2)

    def run(self):
        self.root.mainloop()

dir1 = "C://Users//DELL//Desktop//D&B//image"
dir2 = "C://Users//DELL//Desktop//D&B//image1"

app = ImageComparator(dir1, dir2)
app.run()
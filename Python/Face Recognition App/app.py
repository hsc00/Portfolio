import face_recognition as fr
import os
import cv2
import numpy
from tkinter import *
from tkinter.filedialog import askopenfilename
from tkinter.messagebox import showinfo


def get_encoded_faces():
    encoded = {}

    for dirpath, names, fnames in os.walk("./faces"):
        for f in fnames:
            if f.endswith(".jpg") or f.endswith(".png") or f.endswith(".gif"):
                face = fr.load_image_file("faces/" + f)
                encoding = fr.face_encodings(face)[0]
                encoded[f.split(".")[0]] = encoding

    return encoded


def unknown_image(img):
    face = fr.load_image_file("faces/" + img)
    encoding = fr.face_encodings(face)[0]

    return encoding


def classify_face(image):
    faces = get_encoded_faces()
    faces_encoded = list(faces.values())
    known_face_names = list(faces.keys())

    img = cv2.imread(image, 1)
    face_locations = fr.face_locations(img)
    unknown_face_encodings = fr.face_encodings(img, face_locations)

    face_names = []
    for face_encoding in unknown_face_encodings:
        matches = fr.compare_faces(faces_encoded, face_encoding)
        name = "Unknown"

    face_distances = fr.face_distance(faces_encoded, face_encoding)
    best_match_index = numpy.argmin(face_distances)
    if matches[best_match_index]:
        name = known_face_names[best_match_index]

    face_names.append(name)

    for (top, right, bottom, left), name in zip(face_locations, face_names):
        cv2.rectangle(img, (left - 20, top - 20), (right + 20, bottom + 20), (255, 0, 0), 2)

        cv2.rectangle(img, (left - 20, bottom - 15), (right + 20, bottom + 20), (255, 0, 0), cv2.FILLED)
        font = cv2.FONT_HERSHEY_COMPLEX
        cv2.putText(img, name, (left - 20, bottom + 15), font, 1.0, (255, 255, 255), 2)

        width = 600
        height = 540
        dim = (width, height)

        resized = cv2.resize(img, dim, interpolation=cv2.INTER_AREA)

    while True:
        cv2.imshow("", resized)
        return face_names


def menu():
    aux = False;

    def open_file():
        print(classify_face(askopenfilename()))

    root = Tk(className=" Face Recognition App")
    menu = Menu(root)
    root.config(menu=menu)
    root.geometry("400x400")
    filemenu = Menu(menu)
    menu.add_cascade(label="File", menu=filemenu)
    filemenu.add_command(label="Open", command=open_file)
    Label(root, text="Load your photo please, I'll do the rest!", font=("Helvetica", 14)).pack(pady=160)

    root.mainloop()


print(menu())

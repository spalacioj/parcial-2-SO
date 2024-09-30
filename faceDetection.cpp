#include <opencv2/opencv.hpp>
#include <omp.h>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

    if (argc != 2) {
        cout << "Usage: " << argv[0] << " imageName" << endl;
        return -1;
    }

    // Load the pre-trained Haar cascade for face detection
    CascadeClassifier faceCascade;
    faceCascade.load("haarcascade_frontalface_default.xml");

    // Read the input image
    Mat image = imread(argv[1]);
    if (image.empty()) {
        cout << "Could not open or find the image" << endl;
        return -1;
    }

    // Convert the image to grayscale
    Mat gray;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // Detect faces in the grayscale image
    vector<Rect> faces;
    faceCascade.detectMultiScale(gray, faces, 1.1, 3, 0, Size(30, 30));

    cout << "detected " << faces.size() << " faces in the image." << endl;

    // Draw rectangles around the detected faces
    #pragma omp parallel for
    for (size_t i = 0; i < faces.size(); i++) {
        rectangle(image, faces[i], Scalar(0, 255, 0), 2); 

        Mat face = image(faces[i]);

        string filename = "croppedFaces/face_" + to_string(i) + ".jpg";

        imwrite(filename, face);
    }

    // Display the image with detected faces
    string filename = "croppedFaces/all_faces.jpg";
    imwrite(filename, image);
    imshow("Detected Faces", image);
    waitKey(0);

    return 0;
}
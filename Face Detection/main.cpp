#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main() {

	string path = "Resources/face1.jpg";
	Mat img = imread(path);

	CascadeClassifier faceModel;
	faceModel.load("Resources/haarcascade_frontalface_default.xml");

	if (faceModel.empty()) { cout << "XML file not loaded" << endl; }

	vector<Rect> faces;

	faceModel.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	imshow("Image", img);
	waitKey(0);
}
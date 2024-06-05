#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

Point pt0ld;
void on_mouse(int event, int x, int y, int flags, void* userdata);
Mat src(500, 900, CV_8UC3, Scalar(255, 255, 255));
Mat drawLine();

int main() {
	Mat img = drawLine();
	namedWindow("Windows");
	setMouseCallback("Windows", on_mouse, &img);

	imshow("Windows", img);
	waitKey();
	return 0;
}

Mat drawLine() {
	rectangle(src, Rect(0, 0, 700, 500), Scalar(0, 0, 0), 2);
	rectangle(src, Rect(500, 0, 200, 100), Scalar(0, 0, 0), 2);		// save block
	rectangle(src, Rect(500, 100, 200, 100), Scalar(0, 0, 0), 2);		// load block
	rectangle(src, Rect(500, 200, 200, 100), Scalar(0, 0, 0), 2);		// clear	block
	rectangle(src, Rect(500, 300, 200, 100), Scalar(0, 0, 0), 2);		// run block
	rectangle(src, Rect(500, 400, 200, 100), Scalar(0, 0, 0), 2);		// exit block
	rectangle(src, Rect(700, 0, 200, 100), Scalar(0, 0, 0), 2);		// contours block
	rectangle(src, Rect(700, 100, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(src, Rect(700, 200, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(src, Rect(700, 300, 200, 100), Scalar(0, 0, 0), 2);
	rectangle(src, Rect(700, 400, 200, 100), Scalar(0, 0, 0), 2);
	const string text1[] = { "Save", "Load", "Clear", "Run", "Exit" };
	const string text2[] = { "contour", "feature1", "feature2", "feature3", "feature4"};
	int fontFace = FONT_HERSHEY_SIMPLEX;
	double fontScale = 1.5;
	double fontScale2 = 1.2;
	int thickness = 2;
	for (int i = 0; i < 5; i++) {
		Size sizeText = getTextSize(text1[i], fontFace, fontScale, thickness, 0);
		Size sizeText1 = getTextSize(text2[i], fontFace, fontScale, thickness, 0);
		Size sizeImg = src.size();
		int buttonXStart1 = 500;
		int buttonXStart2 = 720;
		int buttonWidth = 200;

		Point org1(buttonXStart1 + (buttonWidth - sizeText.width) / 2, 500 * i / 5 + (sizeImg.height + sizeText.height) / 8);
		Point org2(buttonXStart2 + (buttonWidth - sizeText1.width) / 2, 500 * i / 5 + (sizeImg.height + sizeText1.height) / 8);

		putText(src, text1[i], org1, fontFace, fontScale, Scalar(0), thickness);
		putText(src, text2[i], org2, fontFace, fontScale2, Scalar(0), thickness);
	}
	return src;
}

void on_mouse(int event, int x, int y, int flags, void* userdata) {
	switch (event) {
	case EVENT_LBUTTONDOWN:
		pt0ld = Point(x, y);
		if (Rect(500, 200, 200, 100).contains(Point(x, y))) {       // clear
			(*(Mat*)userdata)(Rect(0, 0, 500, 500)) = Scalar(255, 255, 255);		// userdata를 Mat 타입으로 캐스팅하고 이를 참조하여 500x500 영역을 흰색으로 채움
			rectangle((*(Mat*)userdata), Rect(0, 0, 500, 500), Scalar(0), 2);		// 같은 Mat 객체에 검은색 테두리를 그림
			cout << "입력창 삭제됨" << endl;
			imshow("Windows", (*(Mat*)userdata));						 // 변경된 이미지를 다시 표시함
		}
		else if (Rect(500, 0, 200, 100).contains(Point(x, y))) {		// save
			string fileName;
			Mat save = (*(Mat*)userdata)(Rect(2, 2, 496, 496)).clone();
			resize(save, save, Size(500, 500));
			cout << "파일명 입력: ";
			cin >> fileName;
			imwrite(fileName, save);
			cout << fileName << "이 저장됨" << endl;
		}
		else if (Rect(500, 100, 200, 100).contains(Point(x, y))) {		// load
			string fileName;
			cout << "파일명을 입력하시오: ";
			cin >> fileName;
			Mat numberImg = imread(fileName);
			rectangle(numberImg, Rect(0, 0, 500, 500), Scalar(0), 2);
			numberImg.copyTo((*(Mat*)userdata)(Rect(0, 0, 500, 500)));
			imshow("Windows", (*(Mat*)userdata));
		}
		else if (Rect(500, 400, 200, 100).contains(Point(x, y))) {		// exit
			exit(1);
		}
		else if (Rect(500, 300, 200, 100).contains(Point(x, y))) {		// run

		}
		else if (Rect(700, 0, 200, 100).contains(Point(x, y))) {		// contour
			Mat gray, bin;
			cvtColor((*(Mat*)userdata), gray, COLOR_BGR2GRAY);
			Mat gray_img = gray(Rect(2, 2, 496, 496));
			threshold(gray_img, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
			vector<vector<Point>> contours;
			findContours(bin, contours, RETR_LIST, CHAIN_APPROX_NONE);
			cout << "검출된 외곽선: " << contours.size() << endl;
		}
		break;
	case EVENT_MOUSEMOVE:
		if (Rect(0, 0, 495, 500).contains(Point(x, y))) {
			if (flags & EVENT_FLAG_LBUTTON) {
				line(src, pt0ld, Point(x, y), Scalar(0), 10);
				imshow("Windows", *(Mat*)userdata);
				pt0ld = Point(x, y);
	case EVENT_LBUTTONUP:
		pt0ld = Point(x, y);
		break;
	default:
		break;
			}
		}
	}
}
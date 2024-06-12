➨ 이번 프로젝트는 OpenCV 라이브러리를 사용하여 사용자가 그리는 숫자의 특징을 검출하는 프로그램입니다.

https://youtu.be/T_PJqr3y7Rg

실행 동영상 링크

# Contour 영역

● 이미지를 GRAYSCALE변환과 이진화 변환

● 모폴로지 변환 (닫힘 연산) 및 외곽선 검출

● 모든 외곽선 포인트를 contours 벡터에 저장

# CenterPoint 영역

● 초기 처리로 그레이스케일, 이진화, 모폴로지 닫힘 연산, 외곽선 검출 진행

● 객체의 전체 바운딩 박스, 내부 외곽선 바운딩 박스를 그리고 중심 좌표 계산

● 중심 좌표가 두 개 이상이면, 두 중심 좌표 간의 거리를 계산

● 두 중심좌표의 y축 차가 음수이면 6, 양수이면 9, 두 점의 거리 차가 10 이내이면 0으로 추측

![image](https://github.com/smHan22/finalProject-2/assets/90818408/01b2ff70-c511-4733-99d8-3926e919f201)

![image](https://github.com/smHan22/finalProject-2/assets/90818408/79a310fa-4fad-4bb4-bce3-59dca1171f4c)

![image](https://github.com/smHan22/finalProject-2/assets/90818408/f2f2904d-c558-43dc-86e4-f747ce07e028)


# PixelCount 영역

● 초기 처리로 그레이스케일, 이진화, 모폴로지 닫힘 연산, 외곽선 검출 진행

● 위쪽, 아래쪽, 왼쪽, 오른쪽에 있는 픽셀의 개수를 저장하기 위한 변수를 초기화.

● 중첩 루프를 사용하여 이미지의 각 픽셀을 반복. 각 픽셀의 밝기 값이 흰색인지 확인하고, 픽셀이 이미지의 수직 중심보다 위에 있는지 아래에 있는지, 수평 중심보다 왼쪽에 있는지 오른쪽에 있는지 확인하여 각 방향에 해당하는 카운터 증가

● 각 방향의 픽셀 비율을 계산. 수직 방향의 경우 위쪽 픽셀 수와 아래쪽 픽셀 수를 합쳐서 총 수직 픽셀 수를 구하고, 각 방향의 픽셀 수를 총 픽셀 수로 나눈 다음 100을 곱해서 백분율로 계산. (수평 방향의 경우도 같음)

● 바운딩 박스와 중심좌표 및 수직, 수평선을 시각화하여 이해 도움

![image](https://github.com/smHan22/finalProject-2/assets/90818408/c2f4b637-fcbe-49df-bafa-e8660658f5ff)

![image](https://github.com/smHan22/finalProject-2/assets/90818408/c6187f31-ecd9-437a-bf51-91515ca19cec)


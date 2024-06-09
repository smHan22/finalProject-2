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

● 이진화된 이미지의 각 픽셀을 순회하며 중심 좌표를 기준으로 네 영역 (위, 아래, 왼쪽, 오른쪽)의 흰색 객체 픽셀 수를 계산

● 각 영역의 픽셀 수를 전체 픽셀 수로 나누어서 백분율로 변환

● 바운딩 박스와 중심좌표 및 수직, 수평선을 시각화하여 이해 도움

![image](https://github.com/smHan22/finalProject-2/assets/90818408/c2f4b637-fcbe-49df-bafa-e8660658f5ff)

![image](https://github.com/smHan22/finalProject-2/assets/90818408/c6187f31-ecd9-437a-bf51-91515ca19cec)


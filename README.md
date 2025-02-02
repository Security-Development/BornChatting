# 🧮 BornCal    
> 사칙연산(+, -, ×, ÷)을 포함하는 연산식을 입력받아 처리하는 UDP 프로그램
## Team member
  학번 | 이름 | Branch | 역할 
  :-----: | :-----: | :-----: | -----
  H3107 | 김본수 | kbs | Client 구현, 소켓 통신 점검
  H3112 | 이승용 | lsy | Client socket 구현
  H3119 | 황성윤 | hsy | Readme 작성
  H3206 | 박현경 | phk | Readme 작성
  H3209 | 양승철 | ysc | Server 내 연산 구현
  H3219 | 홍제만 | hjm | Server socket 구현, 소켓 통신 점검

## Introduction

**Language/Development enviroments**
* C/C++
* Ubuntu 18.04  
  
**Program compile**  
* Server  
```
gcc -o server server.c -fno-stack-protector -no-pie -lm
./server 7904
```  
* Client  
```  
g++ -o client client.cpp -fno-stack-protector -no-pie -lm
./client
```  
## 프로그램 실행    
* ./server 7904 → ./client  

* 명령어   
  > **!calc**   
  피연산자와 연산자를 서버에 보낸다.    
  **!cls**  
  터미널창의 출력 결과를 새로고침한다.  
  **!exit**  
  프로그램을 종료시킨다.    
  **!srvoff**  
  서버를 종료시킨다.    
  
## 계산 명령 수행  
* **case 1**   
30 + 20  
  
  ![정수 정수 덧셈](https://user-images.githubusercontent.com/74813313/175808469-ba05c4f9-c540-411e-bbde-b7715ae75641.png)   
* **case 2**   
31 - 14.5  
  
  ![정수 실수 뺄셈](https://user-images.githubusercontent.com/74813313/175808514-fa1433f6-9174-4484-bde6-f86c735f5220.png)     
* **case 3**     
32.323 × 20  
  
  ![실수 정수 곱셈](https://user-images.githubusercontent.com/74813313/175808558-2a84b2ab-9d49-4fc2-a109-164789ee15ad.png)   
* **case 4**   
32.123 ÷ 12.4  
  
  ![실수 실수 나눗셈](https://user-images.githubusercontent.com/74813313/175808571-28a50c1e-0f3f-4753-9d37-094b2ae53dcd.png)  
* **case 5**  
33333333 × 22222222  
  
  ![오버플로우](https://user-images.githubusercontent.com/74813313/175809960-a4822ef0-27fb-4d0e-8bdb-71571285221f.png)    

## 오류 수정   
* 잘못된 값 입력  

  ![in error1](https://user-images.githubusercontent.com/74813313/175815453-dbeb5021-68fd-40fd-bf2f-f3b5fb26b68c.png)   
  
  ![in error2](https://user-images.githubusercontent.com/74813313/175815465-e89c9ecc-bfac-44a1-976f-7757a89423ed.png)   

## 프로그램 종료   
* **exit** 
  ![exit](https://user-images.githubusercontent.com/74813313/175810107-e77b37f7-3a8e-4918-baf6-2b90fecaae85.png)
* **srvoff** 
  ![srvoff](https://user-images.githubusercontent.com/74813313/175810065-24eeac5e-5233-4756-81e6-bec6faa2ff94.png)

## 프로그램 구조 분석
* **통신규약**  
  * Client가 Server에 접속하자마자 OPCode, Flag, 피연산자가 담긴 구조체를 전달한다.   
  * 구조체를 전부 전달한 뒤 Server는 구조체 속 OPCode를 읽어 연산자인지 종료 신호인지 판단한다.   
  * 연산자이면 Flag 값을 이용하여 피연산자들의 데이터형을 확인하고, 이를 연산한다.   
  * 연산 결과에 따라 Flag 값을 작성하고, 이에 맞는 데이터형의 결과를 구조체에 담아 전송한다.   
  * Client는 Flag 값을 파악해 결과 값을 읽는다.  
            
  **Flag**           
  Flag | 내용    
  ----- | :-----:    
  1 | 정수형 자료형    
  2 | 실수형 자료형     
  3 | 해당 없음   

  **Client→Server**    
  OP Code | 역할 | 데이터내용 
  ----- | :-----: | :-----:  
  1 | 실수 덧셈 + | 뎃셈 연산 요청  
  2 | 실수 뺄셈 - | 뺄셈 연산 요청  
  3 | 실수 곱셉 × | 곱셈 연산 요청
  4 | 실수 나눗셈 ÷ | 나눗셈 연산 요청
  
  **Server→Client**  
  OP Coode | 역할 | 데이터내용
  ----- | :-----: | :-----:
  5 | 연산 결과 전송 | 연산 결과 값    
  6 | 서버 종료 |     
  100 | 연산 에러 전송 | 오버플로우, 언더플로우 발생   
  
## Project check  
- [x] 통신규약  
- [x] GitHub  
- [x] 소켓 통신 모듈  
- [x] 메인 모듈  
- [x] 프로그램 테스트

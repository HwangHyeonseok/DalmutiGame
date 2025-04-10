<div align="center">
<h2>[2023] 보드게임 '달무티', 콘솔 게임 제작 🎮</h2>
인생은 불공평합니다!<br> 
왕부터 노예까지의 계급 사회<br>
보드게임 '달무티'를 콘솔로 만들었습니다. <br><br>
<img src="https://github.com/user-attachments/assets/97b82097-1de8-4b63-8185-5d5629cedb4f" alt="dalmuti_intro" />
</div>

## 시연 영상
https://github.com/user-attachments/assets/1bf59578-c2b6-4f7d-8dc6-fc04339e12b8

## 팀원 구성

<div align="center">

| **황현석** | **이승헌** | **이진석** | **김민석** |
| :------: |  :------: | :------: | :------: |
| [<img src="https://avatars.githubusercontent.com/HwangHyeonseok" height=150 width=150> <br/> @HwangHyeonseok](https://github.com/HwangHyeonseok) | [<img src="https://avatars.githubusercontent.com/lico0531" height=150 width=150> <br/> @lico0531](https://github.com/lico0531) | [<img src="https://avatars.githubusercontent.com/LeeJinSeok323" height=150 width=150> <br/> @LeeJinSeok323](https://github.com/LeeJinSeok323) | [<img src="https://avatars.githubusercontent.com/123qweminseok1" height=150 width=150> <br/> @123qweminseok1](https://github.com/123qweminseok1) |

</div>

<br>

## 목차
  - [개요](#개요) 
  - [게임 설명](#게임-설명)
  - [게임 플레이 방식](#게임-플레이-방식)

## 개발 개요
- 개발 기간 : 2023.04~2023.06
- 개발 언어 : C / C++

## 게임 설명
|<img src="https://github.com/user-attachments/assets/e6cbad2c-7185-4dfe-95df-61e6355fa41c" alt="dalmuti_intro" height="auto" width="600px" />|<img src="https://github.com/user-attachments/assets/ac847f7b-3549-485b-a07f-a74ee31ac3b1" alt="dalmuti_ingame" height="auto" width="600px" />|
|:---:|:---:|
|시작 화면|인게임 화면|

## 게임 플레이 방식
- 카드를 내지 않을 것인지 (1) 낼 것인지 (0) 입력
- 낼 카드를 모두 입력
- 카드를 입력하면 5초 후 다음 사람 턴으로 넘어간다.
- 좌측 상단에 낸 카드 이력이 나온다.
- 우측 상단에 각 플레이어의 남은 카드 수가 나온다.
- 카드를 모두 낼 때까지 게임이 진행된다.

|<img src="https://github.com/user-attachments/assets/c2a9cdff-03c7-4769-8e56-885fb8c0ae20" alt="dalmuti_game_logic" height="auto" width="500px"/>|<img src="https://github.com/user-attachments/assets/717a0f8e-58db-4ade-8bf1-1653b4278590" alt="dalmuti_game_logic" height="auto" width="500px"/>
|:---:|:---:|
|인게임 로직|결과 화면|

## 게임 로직 설계
|<img src="https://github.com/user-attachments/assets/ae383ff8-694e-4686-a376-963b599d845d" alt="dalmuti_intro_logic" height="auto" width="500px"/>|<img src="https://github.com/user-attachments/assets/ec475cc6-e60c-43d3-8b28-1cfac7104433" alt="dalmuti_intro_setting" height="auto" width="500px"/>
|:---:|:---:|
|인트로 화면|게임 환경 세팅 화면(제거)|

|<img src="https://github.com/user-attachments/assets/8ed28970-93f1-48c5-aad3-ce37b740359c" alt="dalmuti_game_main" height="auto" width="500px"/>|<img src="https://github.com/user-attachments/assets/796ab538-af5e-41da-a7f8-79282708103b" alt="dalmuti_game_logic" height="auto" width="500px"/>
|:---:|:---:|
|게임 메인 화면|결과 화면|


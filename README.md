# Sejong University Open Source Project : CHESS

## 프로젝트 안내

- 프로젝트 목적

> 3학년 1학기 오픈소스SW개론 수업에서 진행한 프로젝트로, 다른 사람들과 협업하여
>
> 소프트웨어의 기획, 디자인, 개발 등 전반적인 소프트웨어 제작을 경험하기 위한 프로젝트 입니다.

- 사용 언어, 툴

> C++, C, Visual Studio

- 만든 사람

> 이제희, 김예서, 양남욱, 마영창


## 프로젝트 설치 및 실행 방법

### 1. sfml 설치

> 아래 링크를 이용하여 OS별 bit별 라이브러리 파일을 다운로드 해줍니다.
<https://www.sfml-dev.org/download.php>
>
>압축을 풀어 적당한 위치에 라이브러리를 저장해 둡니다.
> 
![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/bea639a6-a3bc-4eaf-836f-16a0caa0b4b6)
>좌측 상단에 있는 구성을 클릭해서 모든 구성으로 바꿔줍니다.
>
![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/13ae99d9-824e-4467-8023-a08b4460055a)
> 구성 속성- C/C++ -일반 - 추가 포함 디렉터리에 SFML의 include위치를 입력합니다.
> 
![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/5018aae6-1cb1-4444-a3e9-3fb8e3c565ce)
> 구성 속성- 링커- 일반- 추가 라이브러리 디렉터리에 SFML의 lib폴더를 저장합니다.
> 
![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/4de9c845-e760-4183-9d15-214416106de4)
> 구성 속성- 링커 - 입력 - 추가 종속성을 클릭하면 아래와 같이 편집이 나타나는데 클릭해줍니다.
> 
![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/db0742ac-38f8-4c68-88b7-f3f7858718ce)
>나타나는 빈창에 아래를 복사해서 입력한 뒤 확인 버튼을 누르면 입력이 완료됩니다.
>
 ![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/9781ce24-a385-473a-bf7a-3b3824f1c3d2)
 ![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/920c8705-73de-49ee-b91d-8d502549c101)
>이후 SFML폴더 안 bin폴더안에 있는 파일들을 프로젝트가 위치한 폴더로 이동시켜줍니다.

![img1 daumcdn](https://github.com/bethebestKR/sejonguni.opensource/assets/150142937/1ac99da2-2e55-4fd5-bd03-78469e72345a)


출처: https://kali-live.tistory.com/33 [KALILIVE:티스토리]


### 2. Repository를 클론
```bash
git clone [https://github.com/IdeaBank/OpenSource_SW_Final.git](https://github.com/jehhuilee/sejonguni.opensource.git)
```

### 3. 클론한 파일을 프로젝트에 넣고 실행

### 4. 실행화면

![KakaoTalk_Photo_2024-06-10-19-15-16](https://github.com/ossys0920/MyProject/assets/168173742/1455b490-fd2b-43f8-a928-0e9c975a0c4d)




## 체스 규칙

### 1. 체스 기물들의 이동 방법

> 체스는 8x8 보드에서 두 명의 플레이어가 각각 16개의 기물로 진행하는 전략 게임입니다.
>
> 각 기물은 고유한 이동 방식을 가지고 있습니다.

- 폰 (Pawn)
    
    > 이동 : 처음 이동할 때는 한 칸 또는 두 칸 앞으로, 그 이후는 한칸 앞으로 움직일 수 있습니다.
    >
    > 공격: 대각선 방향으로 한 칸씩 움직여 상대 기물을 잡을 수 있습니다.
    
- 룩 (Rook)
    
    > 이동: 가로 또는 세로 방향으로 여러 칸을 이동할 수 있습니다.
    > 
    > 공격: 이동 경로에 있는 상대 기물을 잡을 수 있습니다.
    
- 나이트 (Knight)
    
    > 이동: 'L'자 형태로 이동합니다. (두 칸 이동 후 90도 방향으로 한 칸)
    > 
    > 공격: 이동한 칸에 있는 상대 기물을 잡을 수 있습니다.
    
- 비숍 (Bishop)
    
    > 이동: 대각선 방향으로 여러 칸을 이동할 수 있습니다.
    > 
    > 공격: 이동 경로에 있는 상대 기물을 잡을 수 있습니다.
    
- 퀸 (Queen)
    
    > 이동: 가로, 세로, 대각선 방향으로 여러 칸을 이동할 수 있습니다.
    > 
    > 공격: 이동 경로에 있는 상대 기물을 잡을 수 있습니다.
    
- 킹 (King)
    
    > 이동: 한 번에 한 칸씩 가로, 세로, 대각선 방향으로 이동합니다.
    > 
    > 공격: 이동한 칸에 있는 상대 기물을 잡을 수 있습니다.

### 2. 특수 규칙

-  캐슬링 (Castling)

    > 조건: 킹과 해당 룩이 움직인 적이 없어야 하고, 킹이 이동하는 경로에
    >
    > 다른 기물이 없어야 합니다. 또한, 킹이 체크 상태여서는 안 됩니다.
    >   
    > 방법: 킹은 두 칸 옆으로 이동하고, 룩은 킹을 넘어 옆 칸으로 이동합니다.

- 폰 승격 (Pawn Promotion)

    > 폰이 상대편의 첫 번째 줄(8번째 랭크)에 도달하면 퀸, 룩, 나이트, 비숍 중
    >
    > 하나로 승격할 수 있습니다. 일반적으로 퀸으로 승격합니다.

- 앙파상 (En Passant)

    > 조건: 상대의 폰이 처음 두 칸 전진하는 상황에서 발생하며, 바로 다음 턴에만 실행할 수 있습니다.
    >
    > 방법: 자신의 폰을 대각선으로 이동하여 상대의 폰이 있던 칸으로 이동하고 상대의 폰을 제거합니다.

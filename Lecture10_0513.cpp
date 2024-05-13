const canvas = document.getElementById('myCanvas');
const ctx = canvas.getContext('2d');

// Canvas의 크기를 2배로 설정하여 레티나 디스플레이를 고려
const width = canvas.clientWidth * 2;
const height = canvas.clientHeight * 2;
canvas.width = width;
canvas.height = height;

let playerHP = 3; // 플레이어의 HP
let isGameStarted = false; // 게임 시작 여부를 추적하는 변수
let heartX = 0; // 하트의 x 좌표
let heartY = 0; // 하트의 y 좌표

// 플레이어의 위치 및 반지름 설정
const playerX = width / 2; // 가로 중앙
const playerY = height / 2; // 세로 중앙
const playerRadius = 20; // 반지름 설정

// 플레이어의 각도 (라디안 단위)
let playerAngle = 0;

// 플레이어를 회전하는 함수
function rotatePlayer() {
    ctx.translate(playerX, playerY); // 플레이어의 중심을 기준으로 회전하기 위해 좌표를 이동
    ctx.rotate(playerAngle); // 플레이어를 각도에 맞게 회전
    ctx.translate(-playerX, -playerY); // 회전 후 다시 원래 위치로 이동
}

// 플레이어 회전 각도 업데이트 함수
function updatePlayerAngle() {
    // 각도를 2π(360도)를 넘어가지 않도록 설정
    if (playerAngle >= Math.PI * 2) {
        playerAngle -= Math.PI * 2;
    }
    else if (playerAngle < 0) {
        playerAngle += Math.PI * 2;
    }
}

// 키보드 입력에 대한 이벤트 리스너 추가
document.addEventListener('keydown', function(event) {
    switch (event.keyCode) {
    case 37: // 왼쪽 화살표 키
        playerAngle -= Math.PI / 20; // 플레이어 각도를 왼쪽으로 회전
        break;
    case 39: // 오른쪽 화살표 키
        playerAngle += Math.PI / 20; // 플레이어 각도를 오른쪽으로 회전
        break;
    case 38: // 위쪽 화살표 키
        // 플레이어를 현재 각도 방향으로 이동
        playerX += Math.cos(playerAngle) * playerSpeed;
        playerY += Math.sin(playerAngle) * playerSpeed;
        break;
    case 40: // 아래쪽 화살표 키
        // 플레이어를 현재 각도 반대 방향으로 이동
        playerX -= Math.cos(playerAngle) * playerSpeed;
        playerY -= Math.sin(playerAngle) * playerSpeed;
        break;
    }
});

// 게임 화면 그리기 함수
function drawGameScreen() {
    ctx.clearRect(0, 0, canvas.width, canvas.height); // Canvas를 clear
    rotatePlayer(); // 플레이어 회전
    playerCollider.drawBorder(); // 플레이어의 Circle Collider 테두리 그리기
}

// 게임 루프
function gameLoop() {
    if (isGameStarted) {
        ctx.clearRect(0, 0, canvas.width, canvas.height);
        drawGameScreen();
        updatePlayerAngle(); // 플레이어 회전 각도 업데이트
        updateEnemies();
        checkCollision(); // 충돌 검사 함수 호출
        requestAnimationFrame(gameLoop);
    }
}

// 시작 버튼 생성
const startButton = document.createElement('button');
startButton.textContent = '시작';
document.body.appendChild(startButton);
startButton.style.position = 'absolute';
startButton.style.top = 'calc(50% + 30px)'; // 타이틀 화면보다 아래에 위치
startButton.style.left = '50%';
startButton.style.transform = 'translate(-50%, -50%)';
startButton.style.color = 'black'; //  텍스트색 설정
startButton.style.fontSize = '24px'; // 텍스트 크기 설정
startButton.style.width = '180px'; // 버튼의 가로 크기를 180px로 설정
startButton.style.height = '60px'; // 버튼의 세로 크기를 60px로 설정

// 시작 버튼에 마우스 이벤트 리스너 추가
startButton.addEventListener('mouseover', function() {
    startButton.style.backgroundColor = 'orange'; // 마우스를 가져갔을 때 배경색 변경
});

// 시작 버튼 클릭 이벤트 핸들러
startButton.addEventListener('click', function() {
    // 클릭시 버튼 색상 변경
    startButton.style.backgroundColor = 'blue';

    // 1초 뒤에 게임 시작
    setTimeout(() = > {
        handleStartButtonClick();
    }, 1000);

    // 클릭 이벤트 제거
    startButton.removeEventListener('click', handleClick);
});

// 시작 버튼에 대

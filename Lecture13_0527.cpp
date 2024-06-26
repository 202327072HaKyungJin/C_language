﻿const canvas = document.getElementById('myCanvas');
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

// 삼각형 회전을 위한 변수
let triangleRotation = 0;

// 별 그리기 함수
function drawStar() {
    const starPoints = [
    { x: 25, y : 0 },
    { x: 30.5, y : 14 },
    { x: 49, y : 14 },
    { x: 34, y : 22.8 },
    { x: 39.5, y : 36.4 },
    { x: 25, y : 28 },
    { x: 10.5, y : 36.4 },
    { x: 16, y : 22.8 },
    { x: 1, y : 14 },
    { x: 19.5, y : 14 }
    ];

    // 별의 중심 좌표 계산
    const centerX = (width - 100) / 2;
    const centerY = (height - 80) / 2;

    ctx.beginPath();
    for (const point of starPoints) {
        ctx.lineTo(centerX + point.x * 2, centerY + point.y * 2);
    }
    ctx.closePath();
    ctx.fillStyle = 'rgb(250, 202, 15)'; // 색상을 RGB 값 (250, 202, 15)로 고정
    ctx.fill();

    // 테두리 그리기
    ctx.strokeStyle = 'black'; // 검은색 테두리
    ctx.lineWidth = 2; // 테두리 두께 설정
    ctx.stroke();
}

// 삼각형 그리기 함수
function drawRotatingTriangle() {
    const triangleSize = 50;
    const centerX = width / 2;
    const centerY = height / 2;

    ctx.save();
    ctx.translate(centerX, centerY);
    ctx.rotate(triangleRotation * Math.PI / 180);
    ctx.beginPath();
    ctx.moveTo(0, -triangleSize);
    ctx.lineTo(triangleSize, triangleSize);
    ctx.lineTo(-triangleSize, triangleSize);
    ctx.closePath();
    ctx.fillStyle = 'green';
    ctx.fill();
    ctx.restore();

    // 회전 각도 증가
    triangleRotation += 2; // 원하는 속도로 회전하도록 각도 증가
}

// Circle 클래스 정의
class Circle {
    constructor(x, y, radius) {
        this.x = x;
        this.y = y;
        this.radius = radius;
    }

    // 원과 원이 충돌하는지 확인하는 메서드
    collidesWith(otherCircle) {
        const dx = this.x - otherCircle.x;
        const dy = this.y - otherCircle.y;
        const distance = Math.sqrt(dx * dx + dy * dy);
        return distance < this.radius + otherCircle.radius;
    }

    // 원의 테두리 그리기 메서드
    drawBorder() {
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.radius, 0, Math.PI * 2);
        ctx.strokeStyle = 'black'; // 테두리 색상을 검은색으로 설정
        ctx.lineWidth = 2; // 테두리 두께 설정
        ctx.stroke();
    }
}

// 별의 중심 좌표와 반지름 설정
const starCenterX = (width - 100) / 2;
const starCenterY = (height - 80) / 2;
const starRadius = 40;

// 플레이어의 Circle Collider 설정
const playerCollider = new Circle(playerX, playerY, playerRadius);

// 별과 플레이어의 충돌 여부 확인
const isColliding = playerCollider.collidesWith(new Circle(starCenterX, starCenterY, playerRadius)); // 플레이어의 반지름과 동일하게 설정

// 게임 화면 그리기 함수
function drawGameScreen() {
    ctx.clearRect(0, 0, canvas.width, canvas.height); // Canvas를 clear
    drawStar(); // 별 그리기 함수 호출
    drawRotatingTriangle(); // 회전하는 삼각형 그리기
    drawHeart(heartX, heartY); // 하트 그리기 함수 호출
    drawEnemies(); // 적군 그리기 함수 호출
    playerCollider.drawBorder(); // 플레이어의 Circle Collider 테두리 그리기
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

// 시작 버튼에 대한 클릭 이벤트 핸들러 정의
function handleClick() {
    // 클릭시 버튼 색상 변경
    startButton.style.backgroundColor = 'blue';

    // 1초 뒤에 게임 시작
    setTimeout(() = > {
        handleStartButtonClick();
    }, 1000);

    // 클릭 이벤트 제거
    startButton.removeEventListener('click', handleClick);
}

// 시작 버튼에 클릭 이벤트 핸들러 등록
startButton.addEventListener('click', handleClick);

// 적(적군) 객체 생성 및 관리
class Enemy {
    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.speed = 2; // 적의 이동 속도
        this.size = 20; // 적의 크기
    }

    // 적 그리기 메서드
    draw() {
        ctx.fillStyle = 'red';
        ctx.beginPath();
        ctx.arc(this.x, this.y, this.size, 0, Math.PI * 2);
        ctx.fill();
    }

    // 적의 움직임 업데이트 메서드
    update() {
        const dx = canvas.width / 2 - this.x;
        const dy = canvas.height / 2 - this.y;
        const distance = Math.sqrt(dx * dx + dy * dy);
        const velocityX = (dx / distance) * this.speed;
        const velocityY = (dy / distance) * this.speed;
        this.x += velocityX;
        this.y += velocityY;
    }
}

// 적군 배열
let enemies = [];

// 적군 생성 함수
function createEnemies() {
    const margin = 20; // 화면 바깥 여백 설정
    const numberOfEnemies = Math.floor(Math.random() * 11) + 5; // 5에서 15 사이의 랜덤한 적의 개수 생성
    for (let i = 0; i < numberOfEnemies; i++) {
        let x, y;
        // x 좌표와 y 좌표를 화면 바깥으로 설정
        if (Math.random() < 0.5) {
            // x 좌표 설정
            x = Math.random() < 0.5 ? -margin : width + margin;
            // y 좌표 랜덤 설정
            y = Math.random() * (height + 2 * margin) - margin;
        }
        else {
            // y 좌표 설정
            y = Math.random() < 0.5 ? -margin : height + margin;
            // x 좌표 랜덤 설정


let starX = (canvas.width - 100) / 2; // 별의 초기 x 좌표
let starY = (canvas.height - 80) / 2; // 별의 초기 y 좌표
let starRotationAngle = 0; // 회전 각도 초기화

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

    ctx.save(); // 현재 캔버스 설정 저장

    ctx.translate(starX, starY); // 이동 중심 설정
    ctx.rotate(starRotationAngle); // 회전 각도 적용

    ctx.beginPath();
    for (const point of starPoints) {
        ctx.lineTo(point.x, point.y);
    }
    ctx.closePath();
    ctx.fillStyle = 'rgb(250, 202, 15)'; // 색상을 RGB 값 (250, 202, 15)로 고정
    ctx.fill();

    // 테두리 그리기
    ctx.strokeStyle = 'black'; // 검은색 테두리
    ctx.lineWidth = 2; // 테두리 두께 설정
    ctx.stroke();

    ctx.restore(); // 이전 캔버스 설정 복원
}

// 방향키 입력 처리
document.addEventListener('keydown', function(event) {
    switch (event.keyCode) {
    case 37: // 왼쪽 화살표
        starX -= 5;
        break;
    case 38: // 위쪽 화살표
        starY -= 5;
        break;
    case 39: // 오른쪽 화살표
        starX += 5;
        break;
    case 40: // 아래쪽 화살표
        starY += 5;
        break;
    }
});

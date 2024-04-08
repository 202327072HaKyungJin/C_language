//Canvas Element 불러오기
var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");


function draw()
{    
    ctx.beginPath();
    ctx.moveTo(0,0);
    ctx.lineTo(0,100);
    ctx.lineTo(100,100);
    ctx.lineTo(100,0);

    
    ctx.fillStyle="blue";
    ctx.fill();


    
    ctx.closePath();
    requestAnimationFrame(draw);
}

draw();
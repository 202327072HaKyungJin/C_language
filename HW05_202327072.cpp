//Canvas Element 불러오기
var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");

serInterval(draw, 1000.0 / 60.0)

draw();

var rotAngle = 0;

function draw()
{
    ctx.save();
    ctx.fillStyle = "Blue";
    ctx.translate(canvas.width / 2, canvas.height / 2);
    ctx.clearRect(-canvas.width / 2.0, -canvas.width / 2.0, canvas.width, canvas.height);
    ctx.rotate(Math.PI / 100);
    ctx.fillRect(0, 0, 100, 100);

    ctx.restore();
    ctx.fillStyle = "Red";
    ctx.translate(canvas.width / 2, canvas.height / 2);
    ctx.clearRect(-canvas.width / 2.0, -canvas.width / 2.0, canvas.width, canvas.height);
    ctx.rotate(Math.PI / 100);
    ctx.fillRect(0, 0, 100, 100);
    ctx.restore();

    requestAnimationFrame(draw);
}


// var rotaVar = 0.0;
// Var PI = 3.14;

// ctx.translate(canvas.width/2, canvas.height/2);

// function drawRect(angle)
// {
//       ctx.fillStyle = "blue";
//       ctx.save();
//       ctx.rotate(angle);
//       ctx.fillRect(-50,-50,50,50);
//       ctx.restore();
//}

// var rotAngle = 0;

//function draw()
// {

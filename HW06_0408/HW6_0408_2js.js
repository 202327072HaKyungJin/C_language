//Canvas Element 불러오기
var canvas = document.getElementById("GameScreenCanvas");
var ctx = canvas.getContext("2d");

var colors=["#C7C5FF","black","blue","magenta","pink","cyan","orange"]

class circle{
    constructor(col,radius,positionx,positionY){
        this.color=col;
        this.raius=radius;
        this.positionX=positionX;
        this.PositionY=positionY;
    }
    draw(){
        ctx.save();
        ctx.beginPath();

        for (var angle = 0; angle < Math.PI * 2; angle += 0.01){
            ctx.lineTo(Math.cos(Math.PI/180*i),Math.sin(Math.PI/180*i));
        }

        ctx.translate(this.positionX,this.positionY);
        ctx.scale(this.radius,this.radius);        
        
        ctx.fillStyle = "blue";
        ctx.fill();
        ctx.closePath();
        ctx.restore();        
    }

}



function draw(){    
    var Circle = new circle("blue", 100,300,300);
    Circle.draw();
    requestAnimationFrame(render);
}

render();
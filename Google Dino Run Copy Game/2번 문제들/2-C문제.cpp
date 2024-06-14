#include <iostream>
#include <vector>
using namespace std;

// 장애물 구조체 정의
struct Obstacle {
    int width;  // 가로 크기 (50cm로 고정)
    int height; // 세로 크기 (장애물 높이)

    // 생성자
    Obstacle(int h) : width(50), height(h) {}
};

// 화면에 장애물을 그리는 함수
void drawObstacles(const vector<Obstacle>& obstacles) {
    cout << "Drawing obstacles on the screen:" << endl;
    for (const auto& obstacle : obstacles) {
        cout << "Obstacle size: " << obstacle.width << "cm x " << obstacle.height << "cm" << endl;
        // 여기에 실제로 그리는 코드를 추가할 수 있습니다.
    }
}

int main() {
    // 장애물 생성
    vector<Obstacle> obstacles;
    obstacles.push_back(Obstacle(100)); // 높이 100cm
    obstacles.push_back(Obstacle(300)); // 높이 300cm

    // 장애물 색상 설정 (녹색)
    string obstacleColor = "green";

    // 장애물 화면에 그리기
    drawObstacles(obstacles);

    // 추가적인 로직이나 기능을 구현할 수 있습니다.

    return 0;
}

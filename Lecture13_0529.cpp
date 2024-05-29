#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int count = 0;

    chrono::steady_clock::time_point prev_end = chrono::steady_clock::now();
    chrono::steady_clock::time_point end = chrono::steady_clock::now();

    int delay_time_ms = 0;

    while (count < 10)
    {
        // 시작시간과 끝시간
        prev_end = end;
        end = chrono::steady_clock::now();

        // 시간차 구하기
        chrono::steady_clock::duration diff = end - prev_end;
        delay_time_ms = chrono::duration_cast<chrono::milliseconds>(diff).count();

        // 출력
        count++;
        cout << count << "   dur: " << delay_time_ms << " ms" << endl;

        // 슬립 (1초 - 측정된 시간만큼 대기)
        this_thread::sleep_for(chrono::milliseconds(1000) - chrono::milliseconds(delay_time_ms));
    }
    
    return 0;
}
// Lecture13_0529.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    int count = 0;

    // 루프 시작 시간
    auto start_time = chrono::steady_clock::now();
    int delay_time_ms = 0;

    while (count < 1000)
    {
        // 출력
        count++;
        cout << count << "   delay: " << delay_time_ms << " ms" << endl;

        // 다음 루프까지 대기 (1초)
        this_thread::sleep_until(start_time + chrono::milliseconds(1000 * count));

        // 현재 시간 계산 및 delay_time_ms 업데이트
        auto current_time = chrono::steady_clock::now();
        delay_time_ms = chrono::duration_cast<chrono::milliseconds>(current_time - (start_time + chrono::milliseconds(1000 * count))).count();
    }

    return 0;
}

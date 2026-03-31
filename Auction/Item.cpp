#include "Item.h"
#include <random>

void Item::SetEstimatedRange()
{
    // 1. 시드값을 위한 장치 (매번 다른 값이 나오게 함)
    std::random_device rd;
    // 2. 난수 생성 엔진 초기화 (Mersenne Twister 알고리즘)
    std::mt19937 gen(rd());

    // 3. 0.0f에서 1.0f 사이의 float 분포 설정
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    // 4. 값 생성
    float R = dis(gen);

	float W = RealValue * 0.8;
	
    MinValue = RealValue - (W * R);
    MaxValue = RealValue + (W * (1.0f - R));
}

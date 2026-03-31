#include "NPC.h"
#include "math.h"
#include <random>

void NPC::SetMaxValue(Item* TargetItem)
{
    // 1. 시드값을 위한 장치 (매번 다른 값이 나오게 함)
    std::random_device rd;
    // 2. 난수 생성 엔진 초기화 (Mersenne Twister 알고리즘)
    std::mt19937 gen(rd());

    // 3. 0.0f에서 1.0f 사이의 float 분포 설정
    std::uniform_real_distribution<float> dis(1.5f, 2.0f);

    // 4. 값 생성
    float randomValue = dis(gen);

	MaxValue = TargetItem->RealValue * randomValue;
}

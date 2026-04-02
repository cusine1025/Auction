#pragma once

enum STATE {
	READY,
	JOIN,
	DROP
};

class Participant
{
protected:

	float CurrentMoney = 0;
	float CallValue = 0;

	STATE State = READY;

	virtual ~Participant();

public:

	//돈 추가 함수
	void AddMoney(float Money) { CurrentMoney += Money; };

	//돈 차감 함수
	void SpendMoney(float Money) { CurrentMoney -= Money; };

	//경매 참가 상태 변경 함수
	void SetState(STATE NewState) { State = NewState; };

	//입찰가 설정 함수
	void SetCallValue(float Value) { CallValue = Value; };

	//현재 돈 반환 함수
	float GetCurrentMoney() const { return CurrentMoney; };

	//입찰가 반환 함수
	float GetCallValue() const { return CallValue; };

	//경매 참가 상태 반환 함수
	STATE GetState() const { return State; };
};


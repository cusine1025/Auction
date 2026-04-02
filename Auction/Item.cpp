#include "Item.h"
#include <random>

vector<ItemData> Items = {
	{
		"똥멍청이 동상",
		"띨빵한 게 귀엽습니다.",
		R"(
           ,-------,          
         ,'         '.        
        /             \       
       |   _________   |      
       |  /         \  |      
       | |   O   O   | |      
       | |     ~     | |      
       | |           | |      
       |  \_________/  |      
       |               |      
       '---._______ .---'      
           |       |          
           |       |          
           |       |          
           |_______|          
         ,'         '.        
       ,'             '.      
      /                 \     
     |_________ _________|    
     |        | |        |    
     |________| |________|    
     |___________________|    
        )",
		1500000
	},
	{
		"영혼의 목걸이",
		"누군가의 영혼이 깃들어 있다고 전해지는 목걸이입니다-!",
        R"(              
           _________          
        ,-'         '-,       
      ,'_______________',     
     /___________________\    
    |                     |   
    |   _______________   |   
    |  /               \  |   
    | |                 | |   
    | |       _____     | |   
    | |    ,-'     '-,  | |   
    | |  ,'     _     ',| |   
    | | /      (_)      \ |   
    | | |               | |   
    | | \      _       /  |   
    | |  ',   (_)     ,'  |   
    | |    '-._____.-'    | |   
    | |                 | |   
    |  \_______________/  |   
    |                     |   
     \___________________/    
                     
)",
		2000000
	},
	{
		"에디슨의 전화기",
		"에디슨이 직접 사용했었다는 전화기입니다!",
        R"(                
          ___________          
         /           \         
        /   ________  \        
       [---[________]--]       
       |   |   ||   |  |       
       |___|___||___|__|       
           |        |          
           |   __   |          
           |  /  \  |          
           | | () | |          
           |  \__/  |          
           |        |          
           |   __   |          
           |  /  \  |          
           | | () | |          
           |  \__/  |          
           |________|          
        ,-'          '-,       
      ,'________________',     
     /____________________\    
    |                      |   
    |______________________|   
                         
)",
		500000
	}
};

Item::Item()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, Items.size() - 1);
	int R = dis(gen);

	ItemData Data = Items[R];
	Name = Data.Name;
	Description = Data.Description;
	RealValue = Data.Value;
    AsciiArt = Data.AsciiArt;

	SetEstimatedRange();
}

void Item::SetEstimatedRange()
{
	if (RealValue == 0) return;

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<float> dis(0.0f, 1.0f);
	//랜덤 인수
	float R = dis(gen);

	//오차범위
	float W = RealValue * 0.8;
	
	//감정 최소값
	long long TempMin = RealValue - (W * R);
	MinValue = (float)((TempMin / 10000) * 10000);
	//감정 최대값
	long long TempMax = RealValue + (W * (1.0f - R));
	MaxValue = (float)((TempMax / 10000) * 10000);
}

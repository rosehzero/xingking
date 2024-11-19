#include<iostream>
using namespace std;


//플레이어 직업 
enum PlayerType
{
	PT_None= 0,
	PT_Knight,
	PT_Archer,
	PT_Mage,
};

//몬스터 종류
enum MonsterType
{
	MT_None = 0,
	MT_Slime =1,
	MT_Orc =2,
	MT_Skeleton =3,
};

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

//플레이어 능력치 
PlayerType playerType;
StatInfo playerStat;


struct monsterStatInfo
{
	int monsterHP;
	int monsterAttack;
	int monsterDefence;
};
//몬스터 능력치
MonsterType monsterType;
monsterStatInfo monsterStat;





//전방선언
void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();
void WaitForNextKey();






int main()
{
	srand((unsigned int)time(0)); //랜덤 시드값 설정 

	EnterLobby();

	return 0;

}

void EnterLobby()
{
	while (true)
	{

		cout << "---------------------------------" << endl;
		cout << "로비에 입장 했습니다!" << endl;
		cout << "---------------------------------" << endl;


		//플레이어 직업 선택 
		SelectPlayer();
		
		cout << "---------------------------------" << endl;
		cout << "(1)필드입장 (2)게임종료" << endl;
		cout << "---------------------------------" << endl;

		int input;
		cin >> input;

		if (input == 1)
		{
			EnterField();
			
			if (playerStat.hp == 0)
			{
				return;
			}
		}
		
		else
		{
			return;
		}

		

	}
}

void SelectPlayer()
{

	while (true)
	{
		cout << "---------------------------------" << endl;
		cout << "직업을 골라 주세요!" << endl;
		cout << "(1)기사 (2) 궁수 (3) 법사" << endl;

		cout << "> ";

		int choice;
		cin >> choice;

		if (choice == PT_Knight)
		{
			cout << "기사생성중....." << endl;
			playerStat.hp = 150;
			playerStat.attack = 10;
			playerStat.defence = 5;
			playerType = PT_Knight;

			break;
		}
		else if (choice == PT_Archer)
		{
			cout << "궁수 생성중....." << endl;
			playerStat.hp = 100;
			playerStat.attack = 15;
			playerStat.defence = 3;
			playerType = PT_Archer;

			break;
		}
		else if (choice == PT_Mage)
		{
			cout << "법사 생성중....." << endl;
			playerStat.hp = 80;
			playerStat.attack = 25;
			playerStat.defence = 0;
			playerType = PT_Mage;

			break;
		}
	
	}
	
}

void EnterField()
{
	while (true)
	{

		cout << "---------------------------------" << endl;
		cout << "필드에 입장 했습니다!" << endl;
		cout << "---------------------------------" << endl;

		cout << "[Player] HP : " << playerStat.hp << " // ATT : " << playerStat.attack << " / DEF : " << playerStat.defence << endl;

		//몬스터 스폰
		CreateRandomMonster();

		cout << "---------------------------------" << endl;
		cout << "(1)전투 (2) 도주" << endl;
		cout << ">";

		int input;
		cin >> input;
		if (input == 1)
		{
			EnterBattle();
			break;
		}

		else
		{
			return;
		}
	}
	

}

void CreateRandomMonster()
{
	int randomChoice = 1 + rand() % 3;

	switch(randomChoice)
	{ 
	case MT_Slime:
		cout << "슬라임 생성중 ...! (HP:30 / ATT :2 / DEF:0)" << endl;
		monsterStat.monsterHP = 30;
		monsterStat.monsterAttack = 2;
		monsterStat.monsterDefence = 0;
		monsterType = MT_Slime;
			break;
	case MT_Orc:
		cout << "오크 생성중 ...! (HP:60 / ATT :5 / DEF:3)" << endl;
		monsterStat.monsterHP = 60;
		monsterStat.monsterAttack = 5;
		monsterStat.monsterDefence = 3;
		monsterType = MT_Orc;
			break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중 ...!(HP : 80 / ATT : 15 / DEF : 5)" << endl;
		monsterStat.monsterHP = 80;
		monsterStat.monsterAttack = 15;
		monsterStat.monsterDefence = 5;
		monsterType = MT_Skeleton;
			break;

	}
}

void EnterBattle()
{
	while (true)
	{
		int damage = playerStat.attack - monsterStat.monsterDefence;
		if (damage < 0)
			damage = 0;


		//선빵
		monsterStat.monsterHP -= damage;
		if (monsterStat.monsterHP < 0)
			monsterStat.monsterHP = 0;

		cout << "몬스터 남은 체력 : " << monsterStat.monsterHP << endl;

		if (monsterStat.monsterHP == 0)
		{
			cout << " 몬스터를 처치했습니다 !" << endl;
			WaitForNextKey();
			return;


		}

		//반격
		damage = monsterStat.monsterAttack - playerStat.defence;
		if (damage < 0)
			damage = 0;

		playerStat.hp -= damage;
		if (playerStat.hp < 0)
			playerStat.hp = 0;
		cout << "플레이어 남은 체력 : " << playerStat.hp << endl;

		if (playerStat.hp == 0)
		{
			cout << " 플레이어가 사망했습니다 게임오바 !" << endl;
			WaitForNextKey();
			return;
		}

	}
}

void WaitForNextKey()
{
	cout << "계속하려면 1을 눌러주세요" << endl;
	cout << ">";

	int input;
	cin >> input;

	system("cls");


}


class Game_Snake
{
public:
	void Snake();
private:

	//Определяют направление двежения змеи
	enum eDirection {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN

	};
	eDirection dir;

	//Массив для хранения поля
	char** field;

	//Определяют размеры игрового поля
	static const int width = 20;
	static const int height = 20;
	static const int all_tail = width * height;

	bool gameOver;//Конец игры

	//Координаты всех частей тела змеи
	int nTail;
	int tailX[all_tail];
	int tailY[all_tail];

	//Координаты головы змеи
	int x;
	int y;

	//Координаты яблок
	int apple_x;
	int apple_y;

	//Щетчик очков
	int score;

	void doDrawing();
	void Setup();
	void Input();
	void Logic();
	void Menu();
};
class Game_Snake
{
public:
	void Snake();
private:

	//Determines the direction of movement of the snake
	enum eDirection {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN

	};
	eDirection dir;

	//Array for storing the field
	char** field;

	//Determines the size of the playing
	static const int width = 20;
	static const int height = 20;
	static const int all_tail = width * height;

	bool gameOver;//Game over

	//Coordinates of all parts of the snake`s body
	int nTail;
	int tailX[all_tail];
	int tailY[all_tail];

	//Snake head coordinates
	int x;
	int y;

	//Apple coordinates
	int apple_x;
	int apple_y;

	//Score counter
	int score;

	void doDrawing();
	void Setup();
	void Input();
	void Logic();
	void Menu();
};

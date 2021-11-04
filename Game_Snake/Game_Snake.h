class Game_Snake
{
public:
	void Snake();
private:

	//���������� ����������� �������� ����
	enum eDirection {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN

	};
	eDirection dir;

	//������ ��� �������� ����
	char** field;

	//���������� ������� �������� ����
	static const int width = 20;
	static const int height = 20;
	static const int all_tail = width * height;

	bool gameOver;//����� ����

	//���������� ���� ������ ���� ����
	int nTail;
	int tailX[all_tail];
	int tailY[all_tail];

	//���������� ������ ����
	int x;
	int y;

	//���������� �����
	int apple_x;
	int apple_y;

	//������ �����
	int score;

	void doDrawing();
	void Setup();
	void Input();
	void Logic();
	void Menu();
};
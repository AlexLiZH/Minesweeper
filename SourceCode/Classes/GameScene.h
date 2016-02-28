#ifndef __GAMESCENE_H__
#define __GAMESCENE_H__

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

const int GRID_WIDTH = 5;	//Easy�Ѷ���5x5����
const int GRID_HEIGHT = 5;
const int MAP_WIDTH = 20;	//��ͼ�����20x20����
const int MAP_HEIGHT = 20;
const int GRID_SIZE = 128;	//���������128x128����
const int MINES_NUMS[3] = { 4, 20, 45 };	//������Ϸ�Ѷȷ���ĵ�����
const int TIMES[3] = { 60, 300, 666 };		//ʣ��ʱ��

//����ʵ������
enum class GRID_REAL_TYPE		//0 ����, 1 ����
{
	NUM,
	MINE
};

//�����������
enum class GRID_FACE_TYPE		//0 �ڵ�ש�飬1 ����, 2 ����
{
	NOTHING,
	NUM,
	FLAG
};

//����ṹ
typedef struct 
{
	int number;				//��Χ������
	GRID_REAL_TYPE realType;//����ʵ������
	GRID_FACE_TYPE faceType;//�����������
	Sprite* sp;
}GRID;

typedef struct
{
	int x;
	int y;
}MyPoint;

class GameScene : public Layer
{
private:
	int minesNums;						//������
	int remainderTime;					//ʣ��ʱ��
	vector<MyPoint> minesPosition;		//����λ��
	vector<MyPoint> wrongFlag;			//��¼�Ŵ�ط�������
	GRID map[MAP_WIDTH + 2][MAP_HEIGHT + 2];	//��Ϸ��ͼ

	bool isClicked;						//�����жϵ�����˫��
	int m_x;							//�������
	int m_y;
	int m_type;							//������ͣ�0 �����1 �Ҽ�
	long startTime;						//��¼��Ϸ��ʼʱ��
	Size size;							//���ڴ�С
	Label * minesNumsLabel;				//��������ǩ
	Label * timeLabel;					//ʱ���ǩ
	EventListenerMouse * listener;		//������
	void onMouseDown(Event *event);		//����������¼�
	void singleClicked(float t);		//�������¼�
	void doubleClicked(int x, int y);	//����˫���¼�
	void updateTime(float t);			//����ʱ��

	void setMines();					//���õ���
	void setNumber();					//��������
	void showNumer(int x, int y, int n);//��ʾ����
	void showBlank(int x, int y);		//��ʾ�հ�����
	void showFlag(int x, int y);		//��ʾ����
	void showAround(int x, int y);		//˫����ʾ��Χ����
	void copewithAround(int x, int y);
	int calcFlagNumber(int x, int y);	//������Χ��������
	bool isWin();						//�ж��Ƿ�ʤ��
	void gameOver(string str);			//��Ϸ����
	void gameWin();						//��Ϸʤ��

public:
	static Scene * createScene(int type);
	virtual bool init();
	void menuCallBack(Ref* obj);
	CREATE_FUNC(GameScene);
};

#endif
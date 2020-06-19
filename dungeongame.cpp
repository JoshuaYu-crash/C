#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <stack>
using namespace std;
class Dungeon;
class Render;

// ����
class point {
public:
    int x;
    int y;
    point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// ���³ǵ����½�
class Dungeon {
private:
    int rSize;
    int cSize;
    stack<point> minSt;
    stack<point> tempSt;
    int sum;
    int minAns;
    void randMap() {
        srand((int)time(0));
        for(int i = 0; i < rSize; i++) {
            for(int j = 0; j < cSize; j++) {
                int sign = rand()%2;
                if(sign == 1) {
                    map[i][j] = rand() % 10 + 1;
                }
                else {
                    map[i][j] = -(rand() % 10 + 1);
                }
                
            }
        }
    }
    int max(int a, int b) {
        return a > b ? a : b;
    }
    int min(int a, int b) {
        return a < b ? a : b;
    }
public:
    int map[100][100];
    int signMap[100][100];
    Dungeon(int r, int c) {
        rSize = r;
        cSize = c;
        memset(map, sizeof(map), 0);
        randMap();
        sum = 1000000000;
    }
    void display1() {
        for(int i = 0; i < rSize; i++) {
            for(int j = 0; j < cSize; j++) {
                cout << map[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void display2() {
        for(int i = 0; i < rSize; i++) {
            for(int j = 0; j < cSize; j++) {
                cout << signMap[i][j] << ' ';
            }
            cout << endl;
        }
    }
    void calculateMap() {
        for (int i = 0; i < rSize; i++) {
            for (int j = 0; j < cSize; j++) {
                signMap[i][j] = 0;
            }
        }
        signMap[rSize - 1][cSize - 1] = max(1, 1 - map[rSize - 1][cSize - 1]);  // 1-Ŀ�ĵص�ֵ �� 1 �ȴ�С�� ��֤��1��
        for(int i = cSize - 2; i >= 0; i--) {
            signMap[rSize - 1][i] = max(1, signMap[rSize - 1][i + 1] - map[rSize - 1][i]);  // ���һ�б�֤��1��
        }
        for(int i = rSize - 2; i >= 0; i--) {
            signMap[i][cSize - 1] = max(1, signMap[i + 1][cSize - 1] - map[i][cSize - 1]); // ���һ�б�֤��1��
        }

        for(int i = rSize - 2; i >= 0; i--) {
            for(int j = cSize - 2; j >= 0; j--) {
                int dp_min = min(signMap[i + 1][j], signMap[i][j + 1]);//���ٵľ���
                signMap[i][j] = max(1, dp_min - signMap[i][j]);   //��֤�ܻ�
            }
        }
        minAns = signMap[0][0];
    }
    void dfsMinWay(int x, int y, int sum) {
        sum += signMap[x][y];
        tempSt.push(point(x, y));
        if(x == rSize - 1 && y == cSize - 1) {
            if(sum < this->sum) {
                this->sum = sum;
                minSt = tempSt;
                tempSt.pop();
                return;
            }
        }
        if(x + 1 < rSize) {
            dfsMinWay(x + 1, y, sum);
        }
        if(y + 1 < cSize) {
            dfsMinWay(x, y + 1, sum);
        }
        tempSt.pop();
    }
    void refreshMap() {
        while(!minSt.empty()) {
            signMap[minSt.top().x][minSt.top().y] = 0;
            minSt.pop();
        }
    }
    int getMinAns() {
        return minAns;
    }
};

// ��Ⱦ��
class Render {
private:
    HANDLE hOut;
    int rSize;
    int cSize;
public:
    Render() {
        hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    }
    int index() {
        int select;
        cout << "*********************************************************" << endl;
        cout << "*                     Dungeons                          *" << endl;
        cout << "*                                                       *" << endl;
        cout << "*                    1.������Ϸ                         *" << endl;
        cout << "*                    0.�˳���Ϸ                         *" << endl;
        cout << "*********************************************************" << endl;
        cout << "���������ѡ��:";
        cin >> select;
        return select;
    }
    void  selectRC() {
        int select;
        cout << "�������������õ��³ǵ�����������(1<=����<=100,1<=����<=100)"<<endl;
        cin >> rSize >> cSize;
    }
    void showRandMap(int map[100][100]) {
        for (int i = 0; i < rSize; i++) {	
		    for (int j = 0; j < cSize; j++) {
			    cout << "----";
		    }
            cout << endl;
            for (int j = 0; j < cSize; j++) {
                printf("|%3d", map[i][j]);
            }
		    cout << '|' << endl;
	    }
    }
    void showCalMap(int signMap[100][100], int map[100][100]) {
        for(int i = 0; i < rSize; i++) {
            for (int j = 0; j < cSize; j++) {
                SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
			    cout << "----";
		    }
            cout << endl;
            for(int j = 0; j < cSize; j++) {
                if(signMap[i][j] == 0) {
                    SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                    printf("| �� ", signMap[i][j]);
                }
                else {
                    SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
                    printf("|%3d", map[i][j]);
                }
            }
            cout << '|' << endl;
        }
        SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
    }
    int getRSize() {
        return rSize;
    }
    int getCSize() {
        return cSize;
    }
};

class Game {
private:
    Render *render;
    Dungeon *dungeon;
public:
    Game() {
        render = new Render;
    }
    void gameControl() {
        initial:
        int sign = render->index();
        if(sign == 1) {
            render->selectRC();
            dungeon = new Dungeon(render->getRSize(), render->getCSize());
            dungeon->calculateMap();
            dungeon->dfsMinWay(0, 0, 0);
            system("cls");
            cout << "����õ����³�ÿ���������ֵΪ��" << endl;
            render->showRandMap(dungeon->map);
            dungeon->refreshMap();
            system("pause");
            system("cls");
            cout << "�õ����·��Ϊ��" << endl;
            render->showCalMap(dungeon->signMap, dungeon->map);
            cout << "��Ҫ����������ֵΪ��" << dungeon->getMinAns() << endl;
            system("pause");
            system("cls");
            goto initial;
        }
        else if(sign == 0) {
            return;
        }
        else {
            cout << "���벻����Ҫ��" << endl;
            system("pause");
            system("cls");
            goto initial;
        }
    }
};

int main() {
    Game game;
    game.gameControl();
    return 0;
}


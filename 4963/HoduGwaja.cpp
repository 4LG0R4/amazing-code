#include<iostream>
#include<cstring>

using namespace std;

int w, h; // ����, ����
int map[50][50]; // ��ü ��
bool visited[50][50]; // �ʿ� �����ϱ�?

// �� ����ü
typedef struct { // ������ ���� ����ü
	int dx, dy; // x��, y��
}dir;
dir direction[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} }; //���ʺ��� �ð����

void VisitIsland(int y, int x) {
	if (!map[y][x] || visited[y][x]) return; // �湮 ������? ���̱� ��?(�ȵ� �� ���� �� ���ư�)
	visited[y][x] = true; //�湮��
	for (int i = 0; i < 8; i++) {
		int newY = y + direction[i].dy; // ������ �� ���� ���� y��ǥ
		int newX = x + direction[i].dx; // ������ �� ���� ���� x��ǥ
		if (newX >= 0 && newX < w && newY >= 0 && newY < h) { // �� ����?
			VisitIsland(newY, newX); // ���� �м��غ�
		}
	}
}

int main()
{
	while (true) { // �������� ���ٰ� 0 0�� �ԷµǸ� ������ ������ while �� ���
		int island = 0; // �� ����
		cin >> w >> h; // ���� ����
		if (w == 0 && h == 0) break;
		memset(visited, false, sizeof(visited)); // �����ϴ� �� ���� ��ǥ��, �ʱ�ȭ �� ��, ũ�� ��

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j]; // �Է�
			}
		}
		// �ѹ� ���� ������ ������ ��� �Ǳ� ������ �Է��� �ް� island ����
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) { // ���� �� ���ΰ�? && ���� �ű� �Ȱ���?
					VisitIsland(i, j); // �� ��ŭ���� �ѹ� ����
					island++; // �� ���� �Ϸ�
				}
			}
		}
		cout << island << endl; // ���
	}
	return 0;
}
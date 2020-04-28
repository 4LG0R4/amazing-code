#include<iostream>
#include<cstring>

using namespace std;

int w, h; // 가로, 세로
int map[50][50]; // 전체 맵
bool visited[50][50]; // 맵에 갔습니까?

// 그 구조체
typedef struct { // 방향을 위한 구조체
	int dx, dy; // x축, y축
}dir;
dir direction[8] = { {1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1} }; //동쪽부터 시계방향

void VisitIsland(int y, int x) {
	if (!map[y][x] || visited[y][x]) return; // 방문 안했음? 땅이긴 함?(안돼 안 봐도 돼 돌아가)
	visited[y][x] = true; //방문함
	for (int i = 0; i < 8; i++) {
		int newY = y + direction[i].dy; // 다음에 갈 지점 설정 y좌표
		int newX = x + direction[i].dx; // 다음에 갈 지점 설정 x좌표
		if (newX >= 0 && newX < w && newY >= 0 && newY < h) { // 맵 뚫음?
			VisitIsland(newY, newX); // 들어가서 분석해봐
		}
	}
}

int main()
{
	while (true) { // 무한으로 돌다가 0 0이 입력되면 끝나기 때문에 while 문 사용
		int island = 0; // 섬 개수
		cin >> w >> h; // 가로 세로
		if (w == 0 && h == 0) break;
		memset(visited, false, sizeof(visited)); // 리셋하는 것 각각 목표물, 초기화 할 값, 크기 순

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j]; // 입력
			}
		}
		// 한번 들어갔다 나오면 섬으로 취급 되기 때문에 입력을 받고 island 실행
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && map[i][j]) { // 느그 섬 아인가? && 느그 거기 안갔냐?
					VisitIsland(i, j); // 섬 얼만큼인지 한번 봐라
					island++; // 섬 측정 완료
				}
			}
		}
		cout << island << endl; // 출력
	}
	return 0;
}
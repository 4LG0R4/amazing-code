# https://www.acmicpc.net/problem/1034

n, m = map(int, input().split())

lst = ['0' for _ in range(n)]               # n만큼의 리스트 생성

for i in range(n):
    lst[i] = str(input())                   # 0부터 입력될 수가 있으므로 str형으로 받아옴

cnt = [0 for _ in range(n)]                 # n 개의 행에 각각 1이 몇개 올 수 있는가
print(cnt)
k = int(input())                            # k 번 스위치를 누름

if k % 2:                                   # 만약 k가 홀수라면
    for i in lst:
        z_cnt = str(i).count('0')           # zcnt에 i번째 행의 0의 갯수를 넣어주고
        if z_cnt % 2 and z_cnt <= k:        # 만약 i번째 행의 0 의 갯수가 홀수개이고
                                            # 0의 갯수가 스위치를 누를 수 있는 숫자보다 작다면
            for j in range(n):
                if i == lst[j]:             # 만약 리스트의 i번째 행과 j번째 행이 같다면
                    cnt[j] += 1             # cnt를 1 추가해 준다.

else:                                       # k 짝수
    for i in lst:
        z_cnt = str(i).count('0')
        if not z_cnt % 2 and z_cnt <= k:    # i번째 행의 0의 갯수가 짝수개
            for j in range(n):
                if i == lst[j]:
                    cnt[j] += 1

print(f"{lst}, {k}, answer : {max(cnt)}")

#include <stdio.h>                              //헤더파일 추가
int main() {                                    //main함수 선언
    int N, max, i;                              //int형 변수 N, max, i선언
    int num[100001] = { 0 };                    //num배열 100001크기로 선언
    int arr[100001] = { 0 };                    //arr배열 100001크기로 선언
    //입력
    scanf("%d", &N);                            //N입력받기
    for (i = 1; i <= N; i++) {                  //i가 N이 될때까지 i는 1씩증가
        scanf("%d", &num[i]);                   //num배열에 숫자 입력
    }                                           //for괄호닫기
    //연산
    for (i = 1; i <= N; i++) {                  //i = 1로 설정 N값과 같아질때까지 i 1씩증가
        if (arr[i - 1] + num[i] > num[i]) {     //arr배열의 i - 1번째에 있는 수에 자신를 더했을때 자신이 더 작다면 
            arr[i] = arr[i - 1] + num[i];       //arr배열의 i에 arr[i -1]번째와 자신을 더한값을 입력
        }                                       //이유 : 지난 저장 값 보다 크다면 최댓값이기 때문이다.
        else {                                  //조건을 충족하지 않는다면
            arr[i] = num[i];                    //만약 자신과 arr에 저장된 지난값을 더한것이 자신보다 작다면 자기만 arr배열에 저장
        }                                       //else괄호닫기
    }                                           //for괄호닫기
    max = arr[1];                               //최댓값 기준 설정
    for (i = 2; i <= N; i++) {                  //배열 1번째부터 시작 -> i = 2
        if (max < arr[i]) {                     //max값과 현재 배열값 비교
            max = arr[i];                       //max설정
        }                                       //if괄호닫기
    }                                           //for괄호닫기
    //출력
    printf("%d\n", max);                        //max값 출력
    return 0;                                   //끝!
}                                               //진짜 끝!!
/*
    1. 4개의 숫자 조합 찾기
    -> strike + ball이 0인 경우 해당 숫자들은 구성에서 제외
    2. 정답을 바로 찾은 경우 그대로 종료
    3. 숫자만 찾은 경우 backtracking으로 정답 찾기 
    -> 이미 한 번 query를 날린 적 있는 순열은 제외
*/

#define N 4

typedef struct {
    int strike;
    int ball;
} Result;

// API
extern Result query(int guess[]);

int used[10];
int member[10];
int flag, flag2;
int nums[N];

bool checkMember(int guess[]) {
    for (int i = 0; i < N; i++) {
        if (member[guess[i]]) return true;
    }
    return false;
}

bool checkExcept(int guess[]) {
    int sameFlag = 1;
    for (int i = 0; i < N; i++) {
        if (guess[i] != nums[i])sameFlag = 0;
    }
    return sameFlag;
}

void findNums(int level, int start, int guess[]) {
    if (level == N) {
        if (checkMember(guess)) return;
        Result result = query(guess);

        if (result.strike + result.ball == 0) {
            for (int i = 0; i < N; i++) member[guess[i]] = 1;
        }
        else if (result.strike + result.ball == N) {
            flag = 1;
            for (int i = 0; i < N; i++) nums[i] = guess[i];
            if (result.strike == N) flag2 = 1;
        }

        return;
    }

    for (int i = start; i < 10; i++) {
        if (flag) break;
        if (member[i]) continue;
        guess[level] = i;
        findNums(level + 1, i + 1, guess);
    }
}

void findAns(int level, int guess[]) {
    if (level == N) {
        if (checkExcept(guess)) return;

        Result result = query(guess);

        if (result.strike == N) flag = 1;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (flag) break;
        if (used[nums[i]]) continue;
        used[nums[i]] = 1;
        guess[level] = nums[i];
        findAns(level + 1, guess);
        used[nums[i]] = 0;
    }
}

void init() {
    for (int i = 0; i < 10; i++) {
        used[i] = 0;
        member[i] = 0;
    }
    flag = 0; flag2 = 0;
}

void doUserImplementation(int guess[]) {

    init();

    findNums(0, 0, guess);

    flag = 0;
    if(!flag2)
        findAns(0, guess);
    
}
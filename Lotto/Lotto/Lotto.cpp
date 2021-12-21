// Lotto.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    std::cout << "Hello World!\n";
    
}
int LottoRank(int n) {
    //6개면 1등
    if (n == 6) return 1;
    //5개면 2등
    else if (n == 5) return 2;
    else if (n == 4) return 3;
    else if (n == 3) return 4;    
    else if (n == 2) return 5;
    //1개거나 나머지는 6등
    else return 6;
}


vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;

    // count zero
    int cntzero = 0;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] == 0) cntzero++;
    }

    // same num count
    int samecnt= 0;
    int visited[6] = { 0, };
    for (int i = 0; i < lottos.size(); i++) {
        for (int j = 0; j < win_nums.size(); j++) {
            if (visited[i] == 0 && lottos[i] == win_nums[j]) {
                visited[i] = 1;
                samecnt++;
            }
        }
    }

    //lowest rank
    answer.push_back(LottoRank(cntzero + samecnt));
    //highest rank
    answer.push_back(LottoRank(samecnt));
    
    return answer;
}



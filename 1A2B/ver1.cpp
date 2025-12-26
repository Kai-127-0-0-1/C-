#include <iostream>
#include <string>
#include <vector> //動態陣列
#include <cstdlib> // 隨機數產生
#include <ctime> // 時間

using namespace std;
vector<int> answer;

// 數字可重複
void answer_rand_v1(int n=4){
    answer.clear(); //清除舊資料
    for(int i=0; i < n; i++){
        answer.push_back(rand()%10);
    }
}

// 數字不重複
void answer_rand_v2(int n=4){
    answer.clear(); //清除舊資料
    while(1){
        int randomnumber = rand() % 10;
        bool hasDuplicate = false;
        // 檢查
        for(int j=0; j < answer.size(); j++){
            if (answer[j] == randomnumber){
                hasDuplicate = true;
                break;
            }
        }
        if (!hasDuplicate){
            answer.push_back(randomnumber);
        }
        if (answer.size() == n){
            break;
        }
    }
}


void show_answer(){
    for (int i = 0; i < answer.size(); i++){
        cout << answer[i] << (i==answer.size() -1 ? "": ", ");
    }
}

void player(){
    for (int i=0; ; i++){
        int number;
        vector<int> digits(4, 0);
        cout << "\nGuess a four digits number(" << i << " thguess):\n";
        cin >> number;
        // 分割輸入4位數
        for (int j=answer.size()-1; j>=0; j--){
            digits[j] = number % 10;
            number /= 10;
        }
        // 對應數字
        int numA = 0;
        int numB = 0;
        for (int j=0; j < answer.size(); j++){
            for (int k=0; k<answer.size(); k++){
                if (digits[j] == answer[k] && j==k){
                    numA +=1;
                }
                else if(digits[j] == answer[k]){
                    numB+=1;
                }
            }
        }
        if (numA == 4){
            break;
        }
        cout << numA << " A " << numB << " B\n";
    }

    cout << "You Win!\n";
    //cin.get();
    //cin.get();
    system("pause");
}


int main(){    
    srand(time(0)); // 種子初始化隨機
    answer_rand_v2();
    show_answer();
    player();
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // 隨機數產生
#include <ctime> // 時間
#include <algorithm> // 為了使用 std::find
#include <windows.h>

using namespace std;


/*
1A2B
4位數答案
輸入4位數
檢查對應的數字
*/


class Answer {
    public:
        Answer(int n=4){
            srand(time(0));
            ans.clear();
            while(ans.size() < n){
                int x = rand() % 10;
                if (find(ans.begin(), ans.end(), x) == ans.end()){
                    ans.push_back(x);
                }
            }
        }
        
        void show_answer() const{
            for(int i=0; i<ans.size(); i++){
                cout << ans[i] << (i==ans.size()-1 ? "": ", ");
            }
            cout << endl;
        }
    protected:
        vector<int> ans;

    private:
        
};


class Enter : protected Answer{
    public:
        int n, numA=0, numB=0;
        vector<int> guess;


        Enter(){
            show_answer();
            count_guess();
        }

        void intput(){
            cout << "Input digits: ";
            while(!(cin >> n)){
                cout << "Error Not Digits " << endl;
                cin.clear(); //清除故障碼
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //清除緩衝
            }
            // cout << guess << endl;
        } 

        void split_digits(){
            guess.clear();
            for(int i=0; i<ans.size(); i++){
                guess.push_back(n % 10);
                n /= 10;
            }
            reverse(guess.begin(), guess.end());
            for (int i=0; i< guess.size(); i++){
                cout << guess[i] << (i == guess.size() ? "": ", ");
            }

        }
    
        void comparison(){
            numA=0, numB=0;
            for(int i=0; i<ans.size(); i++){
                for (int j=0; j<guess.size(); j++){
                    if (ans[i] == guess[j] && i == j){
                        numA += 1;
                    }
                    else if (ans[i] == guess[j]){
                        numB += 1;
                    }
                }
            }
        }

        void count_guess(){
            for(int i=0;;i++){
                intput();
                split_digits();
                comparison();
                cout << "run (" << i+1 << "): " << numA << " A " << numB << " B\n";
                if (numA == ans.size()) break;
            }
            cout << "You Win!\n";
            system("pause");
        }

};
    


int main(){
    Sleep(500);
    Enter player;
    return 0;
}
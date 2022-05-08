/******************************************************************************************
<백준 1717> 집합의 표현


문제
초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다. 
여기에 합집합 연산과, 두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산을 수행하려고 한다.

집합을 표현하는 프로그램을 작성하시오.

입력
첫째 줄에 n(1 ≤ n ≤ 1,000,000), m(1 ≤ m ≤ 100,000)이 주어진다. 
m은 입력으로 주어지는 연산의 개수이다. 다음 m개의 줄에는 각각의 연산이 주어진다. 
합집합은 0 a b의 형태로 입력이 주어진다. 
이는 a가 포함되어 있는 집합과, b가 포함되어 있는 집합을 합친다는 의미이다. 
두 원소가 같은 집합에 포함되어 있는지를 확인하는 연산은 1 a b의 형태로 입력이 주어진다. 
이는 a와 b가 같은 집합에 포함되어 있는지를 확인하는 연산이다. 
a와 b는 n 이하의 자연수 또는 0이며 같을 수도 있다.

출력
1로 시작하는 입력에 대해서 한 줄에 하나씩 YES/NO로 결과를 출력한다. (yes/no 를 출력해도 된다)

예제 입력 1 
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1
예제 출력 1 
NO
NO
YES
******************************************************************************************/
#include<iostream>
#include<vector>
using namespace std;

void init(vector<int>& parent){
    for(int i = 0; i < parent.size(); i++){
        parent[i] = i;
    }
}
int getParent(vector<int> parent, int x){
    if(parent[x] == x)  return x;
    return parent[x] = getParent(parent, parent[x]);
}
void parentUnion(vector<int>& parent, int a, int b){
    a = getParent(parent, parent[a]);
    b = getParent(parent, parent[b]);
    if( a < b )     parent[b] = a;
    else            parent[a] = b;
}
int parentFind(vector<int> parent, int a, int b){
    a = getParent(parent, parent[a]);
    b = getParent(parent, parent[b]);
    if(a==b)    return 1;
    else        return 0;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1, -1);
    init(parent);
    bool check;
    for(int i = 0; i < m; i++){
        bool inputType = 0;
        int a, b;
        cin >> inputType >> a >> b;
        if(inputType==0){
            parentUnion(parent, a, b);
        }
        else if(inputType == 1){
            check = parentFind(parent, a, b);
            if(check==true){
                cout << "YES\n";
            }
            else if(check == 0){
                cout << "NO\n";
            }
        }

    }
    return 0;
}
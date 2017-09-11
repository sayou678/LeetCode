
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <queue>
#include <sstream>

using namespace std;

#include "cpp94.cpp"


int main() {
    string line = "[1,2,4,8,null,null,null,5,null,9,3,6,null,10,7,null]";
    //string line = "[1,null,2,3]";


    TreeNode* root = stringToTreeNode(line);

    vector<int> ret = Solution().inorderTraversal(root);
    string out = integerVectorToString(ret);
    cout << out << endl;    

    ret = Solution().preorderTraversal(root);
    out = integerVectorToString(ret);
    cout << out << endl;    

    ret = Solution().postorderTraversal(root);
    out = integerVectorToString(ret);
    cout << out << endl;    
    
    return 0;
}


#include "cpp94.cpp"


int main() {
    //string line = "[1,2,4,8,null,null,null,5,null,9,3,6,null,10,7,null]";
    string line = "[1,null,2,3]";

	
	TreeNode* root = stringToTreeNode(line);

	vector<int> ret = Solution().inorderTraversal(root);

	string out = integerVectorToString(ret);
	cout << out << endl;
	
	return 0;
}
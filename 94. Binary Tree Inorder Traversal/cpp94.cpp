


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) 
	{
		stack<TreeNode *> s;
		TreeNode *node = root;

		vector<int> ret;

		while(!s.empty() || node != NULL)
		{
			if(node != NULL)
			{
				s.push(node);
				node = node->left;
			}
			else
			{
				if(!s.empty())
				{
					node = s.top();
					s.pop();
					ret.push_back(node->val);					
					node = node->right;
				}                
			}
		}

		return ret;

	}

};

void trimLeftTrailingSpaces(string &input) {
}

TreeNode* stringToTreeNode(string input) {
	input = input.substr(1, input.length() - 2);
	if (!input.size()) {
		return NULL;
	}

	string item;
	stringstream ss;
	ss.str(input);

	getline(ss, item, ',');
	TreeNode* root = new TreeNode(atoi(item.c_str()));
	queue<TreeNode*> nodeQueue;
	nodeQueue.push(root);

	while (true) {
		TreeNode* node = nodeQueue.front();
		nodeQueue.pop();

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int leftNumber = atoi(item.c_str());
			node->left = new TreeNode(leftNumber);
			nodeQueue.push(node->left);
		}

		if (!getline(ss, item, ',')) {
			break;
		}

		trimLeftTrailingSpaces(item);
		if (item != "null") {
			int rightNumber = atoi(item.c_str());
			node->right = new TreeNode(rightNumber);
			nodeQueue.push(node->right);
		}
	}
	return root;
}

string integerVectorToString(vector<int> list, int length = -1) {
	if (length == -1) {
		length = list.size();
	}

	string result;
	for(int index = 0; index < length; index++) {
		int number = list[index];
		stringstream ss;
		ss << number;
		string str = ss.str();
		result += str + ", ";
	}
	return result.substr(0, result.length() - 2);
}



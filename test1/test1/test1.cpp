// test1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// C++ program to find maximum rectangular area in linear time
#include<iostream>
#include<stack>

#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <locale>
#include <queue>
#include <sstream>
using namespace std;
 

#include <94. Binary Tree Inorder Traversal\cpp94.cpp>

void test94()
{
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

	
}

int _tmain(int argc, _TCHAR* argv[])
{
	
   test94();

	return 0;
}


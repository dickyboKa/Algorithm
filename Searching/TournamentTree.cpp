#include "TournamentTree.h"
int TourNamentTree::getFirstRankedValue()
{
	m_root->idx;
	return m_arr[m_root->idx];
}

int TourNamentTree::getSecondRankedValue()
{
	int result = std::numeric_limits<int>::max();
	Node *root = m_root;
	traverseHeight(result, root);
	return result;
}

void TourNamentTree::traverseHeight(int &second, TourNamentTree::Node* root)
{
	if (root == nullptr || (root->left == nullptr && root->right == nullptr))
		return; // base case

	if (second > m_arr[root->left->idx] && root->left->idx != root->idx)
	{
		second = m_arr[root->left->idx];
		traverseHeight(second, root->right);
	}

	else if (second > m_arr[root->right->idx] && root->right->idx != root->idx)
	{
		second = m_arr[root->right->idx];
		traverseHeight(second, root->left);
	}
}

void TourNamentTree::createTournamentTree()
{
	std::list<Node*> n_list;
	// first round, compare adjacent value to each other
	for (int i = 0; i < m_arr.size(); ++i)
	{
		Node *t1 = createNode(i);
		Node *t2 = nullptr;

		if (i + 1 < m_arr.size())
		{
			t2 = createNode(i + 1);

			if (m_smallest)
				m_root = (m_arr[i] < m_arr[i + 1]) ? createNode(i) : createNode(i + 1);
			else
				m_root = (m_arr[i] > m_arr[i + 1]) ? createNode(i) : createNode(i + 1);

			m_root->left = t1;
			m_root->right = t2;
			n_list.push_back(m_root);
		}
		else
			n_list.push_back(t1);
	}

	// next round or final round, compare until it became tree
	while (n_list.size() != 1)
	{
		// if even then there is an even amount of tree to compare,
		int last = (n_list.size() & 1) ? n_list.size() - 2 : n_list.size() - 1;

		for (int i = 0; i < last; ++i)
		{
			// extract two node, compare, and the smaller is became root
			Node *f1 = n_list.front(); n_list.pop_front();
			Node *f2 = n_list.front(); n_list.pop_front();

			if (m_smallest)
				m_root = (m_arr[f1->idx] < m_arr[f2->idx]) ? createNode(f1->idx) : createNode(f2->idx);
			else
				m_root = (m_arr[f1->idx] < m_arr[f2->idx]) ? createNode(f1->idx) : createNode(f2->idx);

			m_root->left = f1; m_root->right = f2;

			n_list.push_back(m_root);
		}

		if (n_list.size() & 1)
		{
			n_list.push_back(n_list.front());
			n_list.pop_front();
		}
	}
}

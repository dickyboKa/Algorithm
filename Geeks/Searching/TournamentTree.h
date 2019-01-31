#include <list>
#include <vector>



class TourNamentTree 
{
	struct Node
	{
		int idx;
		Node *left, *right;
	};

	Node* createNode(int i)
	{
		Node *node = new Node;
		node->left = nullptr;
		node->right = nullptr;
		node->idx = i;
		return node;
	}
public:
	// default for the tree root would be the smallest value
	TourNamentTree(std::vector<int> arr) : m_arr(arr), m_smallest(true), m_root(nullptr)
	{
		createTournamentTree();
	}
	// control the root to be the smallest or the biggest value
	TourNamentTree(std::vector<int> arr, bool big) : m_arr(arr), m_smallest(big), m_root(nullptr)
	{
		createTournamentTree();
	}

	int getFirstRankedValue();
	int getSecondRankedValue();
private:
	void createTournamentTree();
	void traverseHeight(int &second, Node *root);
	std::vector<int> m_arr;
	bool m_smallest;
	Node *m_root;
};

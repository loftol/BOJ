#include<iostream>
#include<vector>
#include<utility>

using namespace std;

typedef pair<int, int> vert;

class node
{
public:
	vert v;
	vector<node*> children;
	int diameter, height;
	node() : v({ 0,0 }), children(vector<node*>()), diameter(0), height(0) {}
	node(vert V) : v(V), children(vector<node*>()), diameter(0), height(0) {}
	node(const node& N) : v(N.v), children(N.children), diameter(N.diameter), height(N.height) {}
};

vector<vector<vert>> G;
vector<int> visited;

node* get_tree(vert v)
{
	int n = v.first, w = v.second;
	visited[n] = 1;
	node* root = new node({n,w});
	for (vert next : G[n])
	{
		if (!visited[next.first])
		{
			node* child = get_tree(next);
			root->children.push_back(child);
		}
	}
	if (root->children.size() == 0)
	{
		return root;
	}
	int max_height = 0, second_height = 0, max_diameter = 0;
	for (node* child : root->children)
	{
		if (child->diameter > max_diameter) max_diameter = child->diameter;
		if (child->height + child->v.second > max_height)
		{
			second_height = max_height;
			max_height = child->height + child->v.second;
		}
		else if (child->height + child->v.second > second_height) second_height = child->height + child->v.second;
	}
	if (max_height + second_height > max_diameter) max_diameter = max_height + second_height;
	root->height = max_height;
	root->diameter = max_diameter;
	return root;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n;
	cin >> n;
	G = vector<vector<vert>>(n+1);
	for (int i = 0; i < n-1; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		G[a].push_back({ b,w });
		G[b].push_back({ a,w });
	}
	visited = vector<int>(n+1, 0);
	node* root = get_tree({ 1,0 });
	cout << root->diameter;
}
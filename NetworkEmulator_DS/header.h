



// Number of vertices 
// in the graph
#define V 20

string bestrt;
// A utility function to find the 
// vertex with minimum distance
// value, from the set of vertices
// not yet included in shortest
// path tree
int minDistance(int dist[], bool sptSet[])
{

	// Initialize min value
	int min = 100000, min_index;

	for (int v = 0; v < V; v++)
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v];
			min_index = v;
		}

	return min_index;
}
string convertToString(int i) //function to convert the indices of the network to their respective names in routers and machines
{
	string a = "";//initializing a string 
	switch (i)
	{
	case 0:
		a = "M1";//machine 1 will be considered as the start machine followed by all the other machines and then routers
		break;
	case 1:
		a = "M2";
		break;
	case 2:
		a = "M3";
		break;
	case 3:
		a = "M4";
		break;
	case 4:
		a = "M5";
		break;
	case 5:
		a = "M6";
		break;
	case 6:
		a = "M7";
		break;
	case 7:
		a = "M8";
		break;
	case 8:
		a = "M9";
		break;
	case 9:
		a = "M10";
		break;
	case 10:
		a = "M11";
		break;
	case 11:
		a = "M12";
		break;
	case 12:
		a = "M13";
		break;
	case 13:
		a = "M14";
		break;
	case 14:
		a = "M15";
		break;
	case 15:
		a = "R1";
		break;
	case 16:
		a = "R2";
		break;
	case 17:
		a = "R3";
		break;
	case 18:
		a = "R4";
		break;
	case 19:
		a = "R5";
		break;
	}
	return a;
}





// Function to print shortest
// path from source to j
// using parent array
void printPath(int parent[], int j)
{
	// Base Case : If j is source
	if (parent[j] == -1)
		return;

	printPath(parent, parent[j]);
	string c = "";
	c = convertToString(j);
	 cout << c << endl;
	 bestrt += c;
	//printf("%d ", j);
}

// A utility function to print 
// the constructed distance
// array
void printSolution(int dist[], int n,
	int parent[], int src, int destin)
{

	cout << "Vertex\t    Distance\t       Path" << endl;
	cout << endl;
	for (int i = 0; i < V; i++)
	{
		string a = "";
		string b = "";
		string c = "";
		a = convertToString(src);
		b = convertToString(i);
		c = convertToString(destin);
		if (b == c)
		{
			cout << a << "-->" << b << "\t\t" << dist[i] << "\t\t"  << endl;
			//printf("\n%d -> %d \t\t %d\t\t%d ",	src, i, dist[i], src);
			printPath(parent, i);
			cout << endl;
		}
		else
		{
			continue;
		}
		

	}
	cout << endl << endl;
}
// Function that implements Dijkstra's
// single source shortest path
// algorithm for a graph represented
// using adjacency matrix representation
void dijkstra(int graph[V][V], int src, int destin)
{

	// The output array. dist[i]
	// will hold the shortest
	// distance from src to i
	int dist[V];

	// sptSet[i] will true if vertex
	// i is included / in shortest
	// path tree or shortest distance 
	// from src to i is finalized
	bool sptSet[V];

	// Parent array to store
	// shortest path tree
	int parent[V];

	// Initialize all distances as 
	// INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
	{
		parent[src] = -1;
		dist[i] = 100000;
		sptSet[i] = false;
	}

	// Distance of source vertex 
	// from itself is always 0
	dist[src] = 0;

	// Find shortest path
	// for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance
		// vertex from the set of
		// vertices not yet processed. 
		// u is always equal to src
		// in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex 
		// as processed
		sptSet[u] = true;

		// Update dist value of the 
		// adjacent vertices of the
		// picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is
			// not in sptSet, there is
			// an edge from u to v, and 
			// total weight of path from
			// src to v through u is smaller
			// than current value of
			// dist[v]
			if (!sptSet[v] && graph[u][v] &&
				dist[u] + graph[u][v] < dist[v])
			{
				parent[v] = u;
				dist[v] = dist[u] + graph[u][v];
			}
	}

	// print the constructed
	// distance array
	printSolution(dist, V, parent, src, destin);
}










class ListNode
{
	int data;
	ListNode* next;

public:

	ListNode()
	{
		data = 0;
		next = NULL;
	}

	ListNode(int d)
	{
		data = d;
		next = NULL;
	}

	int getData() { return data; }
	ListNode* getNext() { return next; }
	void setData(int d) { data = d; }
	void setNext(ListNode* ptr) { next = ptr; }

	~ListNode() {}

};


class LinkedList
{
	ListNode* head;
public:

	LinkedList()
	{
		head = NULL;
	}
	~LinkedList()
	{

	}

	ListNode* getHead()
	{
		return head;
	}

	void insert(int v)
	{
		ListNode* currNode = getHead();
		ListNode* newNode = new ListNode;
		newNode->setData(v);
		if (head == NULL)
		{
			newNode->setNext(getHead());
			head = newNode;
		}
		else
		{
			while (currNode->getNext() != NULL)
			{
				currNode = currNode->getNext();
			}
			newNode->setNext(NULL);
			currNode->setNext(newNode);
		}
	}
	void insertAtHead(int a)
	{
		ListNode* newNode = new ListNode;
		newNode->setData(a);
		newNode->setNext(getHead());
		head = newNode;
	}

	bool isEmpty()
	{
		if (getHead() != NULL)
			return true;
	}

	int search(int val)
	{
		ListNode* currNode = head;
		while (currNode && currNode->getData() != val)
		{
			currNode = currNode->getNext();
		}
		if (currNode)
			return currNode->getData();
	}

	void update(int val, int rep)
	{
		ListNode* currNode = head;
		while (currNode && currNode->getData() != val)
		{
			currNode = currNode->getNext();
		}
		currNode->setData(rep);
	}

	ListNode* insertAtIndex(int val, int a)
	{
		if (a < 0)
			return NULL;

		int currIndex = 1;
		ListNode* currNode = head;
		while (currNode && a > currIndex)
		{
			currNode = currNode->getNext();
			currIndex++;

		}

		if (a > 0 && currNode == NULL)
			return NULL;

		ListNode* newNode = new ListNode;

		newNode->setData(val);

		if (a == 0)
		{

			newNode->setNext(head);

			head = newNode;
		}

		else
		{
			newNode->setNext(currNode->getNext());

			currNode->setNext(newNode);

		}

		return newNode;
	}

	int remove(int val)
	{
		ListNode* prevNode = NULL;
		ListNode* currNode = head;
		int currIndex = 1;
		while (currNode && currNode->getData() != val)
		{
			prevNode = currNode;
			currNode = currNode->getNext();
			currIndex++;
		}
		if (currNode)
		{
			if (prevNode)
			{
				prevNode->setNext(currNode->getNext());
				delete currNode;
			}
			else
			{
				head = currNode->getNext();
				delete currNode;
			}
			return currIndex;
		}
	}

	void print()
	{
		int num = 0;
		ListNode* currNode = head;
		while (currNode != NULL)
		{
			cout << currNode->getData() << endl;
			currNode = currNode->getNext();
			num++;
		}
		cout << "Number of nodes in the list: " << num << endl;
	}
};









template<typename T>
class SplayNode    // splay tree node
{
public:
	T data; // data
	SplayNode* left;
	SplayNode* right;
	SplayNode* parent; // parent of each node

	SplayNode() // default constructor
	{
		data = 0;
		left = NULL;
		right = NULL;
		parent = NULL;

	}



	SplayNode(T d)  // parametarised contrctor
	{
		data = d;
		left = NULL;
		right = NULL;
		parent = NULL;
	}
};



template<class T>
class SplayTree   // splay tree class
{
	SplayNode<T>* root;




	SplayNode<T>* temp_right_rotation(SplayNode<T>*& node)
	{

		SplayNode<T>* tmp = node->left;
		node->left = tmp->right;

		if (node->left != NULL)
		{
			node->left->parent = node;
		}
		else
		{
			node->left = NULL;
		}

		if (node->parent == NULL)
		{
			tmp->right = node;
			node->parent = tmp;
			tmp->parent = NULL;

		}
		else
		{
			tmp->right = node;
			tmp->parent = node->parent;
			node->parent = tmp;
		}
		return tmp;
	}




	SplayNode<T>* right_rotation(SplayNode<T>*& node)  // to rotate right if parent is root
	{
		SplayNode<T>* temp = node->parent;   // assign the parent to temp
		SplayNode<T>* leftof = node->left;   // assign the left subtree to leftof
		SplayNode<T>* rightof = node->right;  // assign the right subtree to rightof


		node->parent = NULL;   // assign null to node since it will become root
		node->right = temp;     // assign its right its parent
		temp->parent = node;      // assign the parent -node
		temp->left = rightof;     // assign its left the previous right side of node

		if (rightof != NULL)
		{
			rightof->parent = temp;   // if the right side wasnt null, assign its parent temp
		}



		return temp;
	}




	SplayNode<T>* left_rotation(SplayNode<T>*& node)  // left rotation if parent of node is root node
	{
		SplayNode<T>* temp = node->parent;   // the opposite of right rotation is being done here
		SplayNode<T>* leftof = temp->left;  // assigning the left of parent of node
		SplayNode<T>* rightof = node->left;   // assigning the left subtree of node

		node->parent = NULL; // set the parent null because it wont have any parent since it wil become root
		node->left = temp;  // assign its left the parent of node
		temp->parent = node;   // assing the previous parent of node -node
		temp->right = rightof;   // set its right subtree the left of node subtree

		if (rightof != NULL)  // if it isnt null
		{
			rightof->parent = temp;  // make temp the parent of rightoff
		}



		return temp;

	}



	SplayNode<T>* right_right_rotation(SplayNode<T>*& gp, SplayNode<T>*& p, SplayNode<T>*& node)  // if zig zig situation
	{
		SplayNode<T>* leftof = node->left;     // assigning the left of node
		SplayNode<T>* rightof = node->right;   // assigning the right of node
		SplayNode<T>* rightofp = p->right;    // assigning the right of parent

		node->parent = gp->parent;  // parent of node and gp will be the same
		node->right = p;    // the right of node will be parent

		p->parent = node;   // parent of p will be nd\ode
		p->left = rightof;   // right of p will be right of node
		p->right = gp;   // the right of p will be the right of gp

		gp->parent = p;     // parent of gp will be parent(p)
		gp->left = rightofp;   // the left of gp will be the right of parent

		if (node->parent != NULL)   // if parent of node isnt null
		{
			if (node->parent->left == gp)   // if left side was equal to gp, assign it node, else,assign the right side node
			{
				node->parent->left = node;
			}
			else
			{
				node->parent->right = node;
			}
		}
		if (rightof != NULL)  // if the right side of node isnt null, assign the parent p
		{
			rightof->parent = p;
		}

		if (rightofp != NULL)   // if the right side of parnet isnt null, assign its parent -gp
		{
			rightofp->parent = gp;
		}

		return node;
	}



	SplayNode<T>* left_left_rotation(SplayNode<T>*& gp, SplayNode<T>*& p, SplayNode<T>*& node)   // if zag zag situation
	{
		SplayNode<T>* leftofgp = gp->left;   // assigning left of gp
		SplayNode<T>* leftofp = p->left;   // assigning left of p
		SplayNode<T>* leftofnode = node->left;   // assignging left of node
		 
		node->parent = gp->parent;   // parent of node is parent of gp
		node->left = p;  // the left side of node is equal to p

		p->parent = node;   // assing parent of p-node
		p->left = gp;   // assign its left-gp
		p->right = leftofnode;   // assign its right the left side of node

		gp->parent = p;   // paren of gp is p now
		gp->right = leftofp;   // its right side is equal to left side of p now



		if (node->parent != NULL)   //these are the same conditions as above
		{ 
			if (node->parent->left == gp)
			{
				node->parent->left = node;
			}
			else
			{
				node->parent->right = node;
			}
		}
		if (leftofp != NULL)   // same conditions as for other cases
		{
			leftofp->parent = gp;
		}

		if (leftofnode != NULL)
		{
			leftofnode->parent = p;
		}

		return node;
	}


	SplayNode<T>* right_left(SplayNode<T>*& gp, SplayNode<T>*& p, SplayNode<T>*& node)   // zigzag situation
	{
		SplayNode<T>* leftofp = p->left;   // assiging left side of p
		SplayNode<T>* leftofnode = node->left;   // assigning left side of node
		SplayNode<T>* rightofnode = node->right;   // assigning right side of node

		node->parent = gp->parent;  // parent of gp and node are same
		node->left = p;   // the left side of node is -  p
		node->right = gp;  // right side of node is now gp

		p->parent = node;   // parent of p is node now
		p->right = leftofnode;   // right side of p is left side of node her

		gp->parent = node;  // parent of gp is node noow
		gp->left = rightofnode;  // its left side is equal to right of node

		if (node->parent != NULL)  // same conditions as above
		{
			if (node->parent->left == gp)
			{
				node->parent->left = node;
			}
			else
			{
				node->parent->right = node;
			}
		}
		if (leftofnode != NULL)
		{
			leftofnode->parent = p;
		}
		if (rightofnode != NULL)
		{
			rightofnode->parent = gp;
		}
		return node;
	}




	SplayNode<T>* left_right(SplayNode<T>*& gp, SplayNode<T>*& p, SplayNode<T>*& node)   // zagzig situation
	{
		SplayNode<T>* leftofgp = gp->left;  // assigning left side of grandparent
		SplayNode<T>* leftofnode = node->left;  // assigning left side of node
		SplayNode<T>* rightofnode = node->right;  // assign right side of node

		node->parent = gp->parent;  // parent of node and gp same
		node->left = gp;  // left of node = gp
		node->right = p;  // right side = p

		p->parent = node;  // parent of p i snode now
		p->left = rightofnode;  // its left side is equal to right side of node

		gp->parent = node;   // parent of gp is node now
		gp->right = leftofnode;  // right side is equal to left side of node

		if (node->parent != NULL) // same conditons as above
		{
			if (node->parent->left == gp)
			{
				node->parent->left = node;
			}
			else
			{
				node->parent->right = node;
			}
		}
		if (leftofnode != NULL)
		{
			leftofnode->parent = gp;
		}
		if (rightofnode != NULL)
		{
			rightofnode->parent = p;
		}
		return node;
	}




	void Splay(SplayNode<T>*& node)     // function called to splay
	{

		while (node->parent != NULL)    // as long as the paramter node does not become the root node
		{
			SplayNode<T>* par = node->parent;       // parent of node
			SplayNode<T>* grandparent = par->parent;      // grand parent of node

			if (node->parent == root)   // if the node is a child of root
			{

				if (node == node->parent->left)   // if it is left child, call right rotation
				{

					/////////////////call right rotation here
					right_rotation(node);


				}
				else if (node == node->parent->right)       // else if right child, call right rotation
				{

					///////////////////////call left rotation
					left_rotation(node);

				}

			}

			else
			{


				if (node == node->parent->left && par == par->parent->left)  // if all are in left side of grandparent
				{

					//////////////call zig-zig rotation
					right_right_rotation(grandparent, par, node);
				}
				else if (node == node->parent->right && par == par->parent->right)  // if all are on right side of gradparent
				{
					left_left_rotation(grandparent, par, node);
				}
				else if (node == node->parent->left && par == par->parent->right)   // if in a left right situation
				{
					////////////calling zagzig function	
					left_right(grandparent, par, node);
				}
				else if (node == node->parent->right && par == par->parent->left)   // if in a right left situation
				{

					/////////////calling zig_zag function
					right_left(grandparent, par, node);
				}


			}

		}
		root = node; // at the end, assigning the node to root node
	}

	SplayNode<T>* createnode(SplayNode <T> n)  // function to convert a node to pointer node of splay node
	{

		SplayNode <T>* temp = new SplayNode<T>;
		temp->data = n.data;
		return temp;

	}


	void insertnode(SplayNode<T>*& rt, T n)          // function to insert a node
	{

		if (rt == NULL)   // if root is null
		{
			rt = new SplayNode<T>(n);  // assign a newnode to root node
		}

		else
		{
			SplayNode<T>* currnode = rt;  // node to traverse the tree
			while (currnode != NULL)
			{

				if (currnode->data > n)  // if data of current node > current data
				{

					if (currnode->left == NULL)  // if the left side is null
					{

						SplayNode<T>* temp = new SplayNode<T>(n);
						currnode->left = new SplayNode<T>;
						currnode->left = temp;
						temp->parent = currnode;  // assign the new node to it
						Splay(temp);  // call splay function on it
						return;

					}
					else
					{

						currnode = currnode->left;  // else traverse further left
					}
				}
				else if (currnode->data < n)  // if data of current node is less than n
				{
					if (currnode->right == NULL)  // if right side is null
					{
						SplayNode<T>* temp = new SplayNode<T>(n);
						currnode->right = new SplayNode<T>; // create a new node and assign it
						currnode->right = temp;
						temp->parent = currnode;
						Splay(temp);  // splay the tree
						return;
					}
					else
					{
						currnode = currnode->right;   // else traverse further
					}
				}
				else
				{

					Splay(currnode);   // splay node if it is equal to currnode data
					return;
				}
			}
		}

	}


	void displayInOrderPriv(SplayNode<T>* rt)  // private ftn to display in order
	{
		if (rt != NULL)
		{
			displayInOrderPriv(rt->left);

			cout << rt->data << endl;
			displayInOrderPriv(rt->right);
		}

	}





public:

	SplayTree()   // default contructor
	{
		root = NULL;
	}

	SplayTree(SplayNode<T>* rt) // parmetrised contructor
	{
		root = rt;
	}


	SplayNode<T>* findmin(SplayNode<T>*& rt)
	{
		SplayNode<T>* currnode = rt;
		while (currnode->left != NULL)
		{
			currnode = currnode->left;  // traversing to find maximum
		}
		return currnode;  // traversing it

	}


	SplayNode<T>* Search(T n)
	{
		bool flag = false;  // flag to see if found
		SplayNode<T>* currnode = root;   // node to traverse
		SplayNode<T>* found = NULL;   // if found, return this node

		while (currnode != NULL)  // while node doesnt end
		{
			if (currnode->data < n)  // if data is greater than currnode data, travser right side
			{
				currnode = currnode->right;
			}
			else if (currnode->data > n) // if data is less than currnode data, traverse left side
			{
				currnode = currnode->left;
			}
			else if (currnode->data == n)  // if data is found, assign found the node and break the loop
			{
				found = currnode;
				flag = true;
				break;
			}

		}
		if (found != NULL)  // if found, splay the found node
		{
			Splay(found);
		}

		
			return found; // return it


	}




	void insert(T n)      // function called from main
	{
		insertnode(root, n);
	}





	void displayInOrder()  // to display tree in order
	{
		displayInOrderPriv(root);
	}

	T getrootvalue()   // function to get the root value
	{
		return root->data;
	}


	SplayNode<T>* findmax(SplayNode<T>* subroot)   // function to find the maximum
	{
		SplayNode<T>* currnode = subroot;   // assigning currnode to traverse
		while (currnode->right != NULL)
		{
			currnode = currnode->right;  // traversing to find maximum
		}
		return currnode;  // traversing it
	}


	void deletion(T x)
	{
		bool flag = false;
		SplayNode<T>* finaltree = NULL;
		SplayNode<T>* nodetodelete = Search(x); // to find the node
		if (nodetodelete == NULL)  // there is no node in tree
		{
			cout << "Node doesnt exist \n";
			return;
		}
		SplayNode<T>* left = nodetodelete->left;   // left subtree
		SplayNode<T>* right = nodetodelete->right;  // right subtree
		if (left == NULL && right == NULL)   // if there is no subtrees
		{
			root = NULL;
		}
		else if (right == NULL)   // meaning no right subtree exists
		{
			finaltree = findmax(left);  // finding max of left subtree
			Splay(finaltree);   // splaying it
			
		}
		else if (left == NULL)  // if no left subtree
		{
			finaltree = findmin(right);     // find minimum of right subtree
			Splay(finaltree);   // splay it
			finaltree->parent = NULL;   // make its parent null
			finaltree->left = NULL;   //make its left null
			flag = true;
		}
		else if (left != NULL && right != NULL)  // if both arent null
		{
			finaltree = findmax(left);   // find max of left subtree
			Splay(finaltree);   // splay it
			finaltree->right = right;  // assign right child to its right
			right->parent = finaltree;   // assign the parent of child finaltree
		}

		delete nodetodelete;// delete the node to delete
		
		if (flag)// if there was no  left tree subtree
		{
			root = finaltree;   // right subtree was the tree
		}
		else
		{
			finaltree->parent = NULL;
			root = finaltree;  // else, the final tree is the new root tree
		}

	}


};




void Menu()       // user promt
{
	int ch;
	cout << "**********WELCOME**********\n\n\n" << endl;
	cout << "Enter 1 for LinkedList \nEnter 2 for SplayTree \nYour choice: ";
	cin >> ch;
	while (ch != 1 && ch != 2)
	{
		cout << "Please enter valid Input: ";
		cin >> ch;
	}
	system("cls");
}













class NodeGraph //GraphNode
{
public:
	string name;
	NodeGraph* next;
	int weight;
	NodeGraph()
	{
		name = "";
		weight = 0;
		next = NULL;
	}

	NodeGraph(string nm, int w)
	{
		name = nm;
		next = NULL;
		weight = w;
	}
};

class AdjList //Adjascency list
{

public:
	NodeGraph* head;
	AdjList()
	{
		head = NULL;
	}

	void insertNode(string nm, int w)
	{
		NodeGraph* currNode = head;
		NodeGraph* newNode = new NodeGraph;
		newNode->name = nm;
		newNode->weight = w;

		if (currNode == NULL)
		{
			newNode->next = NULL;
			head = newNode;
		}

		else
		{
			while (currNode->next != NULL)
			{
				currNode = currNode->next;
			}
			newNode->next = NULL;
			currNode->next = newNode;
		}
	}

	void displayList()
	{
		int num = 1;
		NodeGraph* currNode = head->next;
		cout << " Edges" << endl;

		while (currNode != NULL)
		{
			cout << num << ": " << currNode->name << endl;
			currNode = currNode->next;
			num++;
		}
	}
};




class Message
{
public:

	int msgID;
	int priority;
	string src;
	string dest;
	string payLoad;
	string trace;
	AdjList edgeList;


	Message()
	{
		msgID = 0;
		priority = 0;
		src = "";
		dest = "";
		payLoad = "";
		trace = src;
	}

	Message(int id, int pr, string s, string d, string pay, string tr)
	{
		msgID = id;
		priority = pr;
		src = s;
		dest = d;
		payLoad = pay;
		trace = tr;
	}

	void setMsgID(int id) { msgID = id; }
	void setPriority(int pr) { priority = pr; }
	void setSrc(string s) { src = s; }
	void setDest(string d) { dest = d; }
	void setPayLoad(string pay) { payLoad = pay; }
	void setTrace(string tr) { trace = tr; }
	int getMsgId() { return msgID; }
	int getPriority() { return priority; }
	string getSrc() { return src; }
	string getDest() { return dest; }
	string getPayLoad() { return payLoad; }
	string getTrace() { return trace; }

	~Message() {}




	void printPath()
	{

	}
};






class QNode
{
	QNode* next;
	Message data;

public:

	QNode()
	{
		next = NULL;
	}
	QNode(int d)
	{
		next = NULL;
	}


	Message getData() { return data; }
	QNode* getNext() { return next; }
	void setData(Message d) { data = d; }
	void setNext(QNode* ptr) { next = ptr; }

	~QNode() {}
};


class Queue
{
	QNode* front;
	QNode* rear;
	int numItems;

public:
	Queue()
	{
		front = NULL;
		rear = NULL;
	}

	QNode* getFront() { return front; }
	QNode* getRear() { return rear; }
	void setFront(QNode* ptr) { front = ptr; }
	void setRear(QNode* ptr) { rear = ptr; }

	~Queue() {}

	bool isEmpty()
	{
		if (front != NULL && rear != NULL)
			return false;

		return true;
	}

	Message Front() { return front->getData(); }



	void enqueue(Message n)
	{
		QNode* newNode = new QNode;
		newNode->setData(n);
		newNode->setNext(NULL);

		if (isEmpty() == true)
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->setNext(newNode);
			rear = newNode;
		}
	}

	void dequeue()
	{
		QNode* tempNode;
		if (isEmpty() == true)
			cout << "The queue is empty!" << endl;
		else
		{
			tempNode = front->getNext();
			delete front;
			front = tempNode;
		}
	}
};



class PriorityQueue
{
public:

	Message PQdata[100];
	int size;

	PriorityQueue()
	{
		size = -1;
	}

	int parent(int ind) { return ((ind - 1) / 2); } //returns ind of parent
	int LChild(int ind) { return ((2 * ind) + 1); } //returns ind of left child
	int RChild(int ind) { return ((2 * ind) + 2); } //returns ind of right child

	void perculateUp(int ind) //Perculate up function
	{
		while (ind > 0 && PQdata[parent(ind)].getPriority() < PQdata[ind].getPriority())
		{
			//Swapping
			Message tempObj;
			tempObj = PQdata[parent(ind)];
			PQdata[parent(ind)] = PQdata[ind];
			PQdata[ind] = tempObj;

			ind = parent(ind); //updating ind
		}
	}

	void perculateDown(int ind) //Perculate down function
	{
		int maxInd;
		maxInd = ind;

		//For left child
		int lc = LChild(ind);
		if (lc <= size && PQdata[lc].getPriority() > PQdata[maxInd].getPriority())
			maxInd = lc;

		//For right child
		int rc = RChild(ind);
		if (rc <= size && PQdata[rc].getPriority() > PQdata[maxInd].getPriority())
			maxInd = rc;

		if (maxInd != ind)
		{
			//Swapping
			Message tempObj;
			tempObj = PQdata[ind];
			PQdata[ind] = PQdata[maxInd];
			PQdata[maxInd] = tempObj;

			perculateDown(maxInd);
		}
	}

	void insert(Message obj)
	{
		size = size + 1;
		PQdata[size] = obj;

		perculateUp(size); //To mantain max-heap property
	}

	Message extractMax() //Function to extract the message with highest priority
	{
		Message tempObj;
		tempObj = PQdata[0];

		PQdata[0] = PQdata[size]; //Make the last input Message as the root
		size--;

		perculateDown(0); //Now perculate down to mantain the max heap property
		return tempObj;
	}

	Message getMax() //Function to get the max Message
	{
		return PQdata[0];
	}
};


class graph
{
public:
	int size;
	int Maxsize;
	AdjList* Head;

	graph(int maxVer) //default constructor
	{
		size = 0;
		Maxsize = maxVer;
		Head = new AdjList[maxVer];
	}

	void createVertex(string ver) //Create vertex function
	{
		Head[size].insertNode(ver, 0);
		cout << "Making vertex " << Head[size].head->name << endl;
		size++;
	}

	//Create edge function using src, dest and their indexes along with edge weight
	void createEdge(string source, string destination, int srcInd, int destInd, int w)
	{
		cout << "EDGE: " << source << "-" << destination << "-" << srcInd << "-" << destInd << "-" << w << endl;
		Head[srcInd].insertNode(destination, w);
		Head[destInd].insertNode(source, w);
	}

	void showGraphStructure()
	{
		for (int i = 0; i < Maxsize; i++)
		{
			cout << "Vertex " << Head[i].head->name;
			Head[i].displayList();
			cout << endl;
		}
	}
	/*
	void BFS(int startNode)
	{
		bool* visited = new bool[Maxsize + 1];
		for (int i = 0; i < Maxsize + 1; i++)
		{
			visited[i] = false;
		}
		Queue<int> q;

		for (int i = 0; i < Maxsize; i++)
		{
			int vertex = Head[i].head->name;

			if (visited[vertex] == false)
			{
				q.enqueue(vertex);
				visited[vertex] = true;
			}

			Node* currNode = Head[i].head->next;

			while (currNode != NULL)
			{
				int currVertex = currNode->data;
				if (visited[currVertex] == false)
				{
					q.enqueue(currVertex);
					visited[currVertex] = true;
				}

				currNode = currNode->next;
			}
		}

		while (!q.isEmpty())
		{
			cout << q.Front() << " ";
			q.dequeue();
		}
	}*/

	~graph()
	{
		delete[] Head;
	}

};




void readCSVfile(string fileName, graph &gobj)
{
	string text = "";
	ifstream in(fileName);
	string destArr[20];
	int arrCount = 0;

	int lineCount = 0; //Also indicates the source index by sub 1

	while (getline(in, text)) //While loop runs till end of line of the file
	{
		if (lineCount == 0) //For verteces
		{
			string tempStr = "";
			int count = 0;
			while (text[count] != '\0')
			{
				if (text[count] == ',') //When comma comes
				{
					if (tempStr != "")
						gobj.createVertex(tempStr); //creteVetrex
					tempStr = "";
				}
				else
					tempStr += text[count]; //If not comma, then concatenate tempStr

				count++;
			}
		}
		else //For edges
		{
			string tempSrc = "";
			string tempStr = "";
			int commaCount = 0;
			int count = 0;
			while (text[count] != '\0')
			{
				if (commaCount != 0) //for weights
				{
					if (text[count] == ',') //When comma comes
					{
						if (tempStr != "" && tempStr != "?") //If not empty and not '?'
						{
							gobj.createEdge(tempSrc, gobj.Head[arrCount].head->name, lineCount - 1, arrCount, stoi(tempStr));
						}

						tempStr = "";
						arrCount++; //Inc arrCount which indicates the destination index
					}
					else
						tempStr += text[count];
				}
				else //For source
				{
					if (text[count] != ',')
						tempSrc += text[count];
				}

				if (text[count] == ',')
					commaCount++;

				count++;
			}

		}
		arrCount = 0;
		lineCount++;
	}

	cout << "---------------------------" << endl;
}

void readCSVfileAs2D(string fileName, int arr2D[20][20])
{
	
	string text = "";
	ifstream in(fileName);
	int count1 = 0;
	int count2 = 0;

	int lineCount = 0;

	while (getline(in, text))
	{
		string tempStr = "";
		if (lineCount != 0) //For verteces
		{
			int commaCount = 0;
			int count = 0;
			while (text[count] != '\0')
			{
				if (commaCount != 0) //for weights
				{
					if (text[count] == ',') //When comma comes
					{
						if (tempStr == "?")
						{
							tempStr = "";
							tempStr += '0';
						}
						arr2D[count1][count2] = stoi(tempStr);
						tempStr = "";
						count2++;
					}
					else
						tempStr += text[count];
				}

				if (text[count] == ',')
					commaCount++;

				count++;
			}
		}

		if (tempStr == "?")
		{
			tempStr = "";
			tempStr += '0';
			arr2D[count1][count2] = stoi(tempStr);
		}
		else if (tempStr >= "0" && tempStr <= "9")
			arr2D[count1][count2] = stoi(tempStr);



		if (lineCount != 0)
		{
			count1++;
			count2 = 0;
		}
		lineCount++;
	}

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << arr2D[i][j] << " ";
		}
		cout << endl;
	}
	//dijkstra(arr2D, 7);

}











class Router
{
public:
	string rname; // router name
	PriorityQueue incomingQ;   // incoming queue
	Queue outgoingQ;  // outgoing queue

	Router()
	{
		rname = "";
		
	}
	

};



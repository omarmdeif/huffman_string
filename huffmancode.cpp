#include<iostream>
using namespace std;
class snode
{
public:
	int f;
	char s[10000], code[10000];
	snode* left = NULL, * right = NULL;
};
class node
{
public:
	int f;
	char s[10000];
	snode* ro = NULL;
	node* next = NULL;
};
class nodes
{
public:
	char s, code[10000];
	nodes* next = NULL;
};
class list
{
public:
	node* head;
	node* tail;
	list()
	{
		head = NULL;
		tail = NULL;
	}
	~list()
	{
		node* pt;
		while (head != NULL)
		{
			pt = head;
			head = head[0].next;

		}

	}
	void attach(node* pnn)
	{
		if (head == NULL)
		{
			head = pnn;
			tail = pnn;
		}
		else
		{
			tail[0].next = pnn;
			tail = pnn;
		}
	}
	void insert(node* pnn)
	{
		if (head == NULL)
		{
			head = pnn;
			tail = pnn;
		}
		else
		{
			int fa = 0;
			node* pb = NULL, * pt = head;
			while (pt != NULL)
			{
				if (pt->f > pnn->f)
				{
					if (head == pt)
					{
						head = pnn;
						pnn->next = pt;
					}
					else
					{
						pb->next = pnn;
						pnn->next = pt;
					}


					fa = 1;
					break;


				}
				pb = pt;
				pt = pt->next;
			}
			if (!fa)
			{
				tail->next = pnn;
				tail = pnn;
			}
		}
	}
};
class lists
{
public:
	nodes* head;
	nodes* tail;
	lists()
	{
		head = NULL;
		tail = NULL;
	}
	~lists()
	{
		nodes* pt;
		while (head != NULL)
		{
			pt = head;
			head = head[0].next;

		}

	}
	void attach(nodes* pnn)
	{
		if (head == NULL)
		{
			head = pnn;
			tail = pnn;
		}
		else
		{
			tail[0].next = pnn;
			tail = pnn;
		}
	}
};

void daks(snode* pt, snode* pb, char f)
{
	if (pt == NULL)
		return;

	int i = 0, k = 0;
	if (f != NULL)
	{
		i = 0;
		while (pb->code[i] != NULL)
		{
			pt->code[i] = pb->code[i];
			i++;
		}
		pt->code[i] = f;
		pt->code[i + 1] = NULL;
	}
	else
	{
		pt->code[i] = f;
	}
	daks(pt->left, pt, '0');
	if (pt->right == NULL && pt->left == NULL)
	{
		cout << pt->s[0] << endl;
		k = 0;
		while (pt->code[k] != NULL)
		{
			cout << pt->code[k];
			k++;
		}
		cout << endl;
	}
	daks(pt->right, pt, '1');

}
void drighti(snode* pt, snode* pb, lists& l)
{
	nodes* pnn;
	int i;
	if (pt == NULL)
		return;

	drighti(pt->left, pt, l);
	if (pt->left == NULL && pt->right == NULL)
	{
		pnn = new nodes;
		pnn->s = pt->s[0];
		i = 0;
		while (pt->code[i] != NULL)
		{
			pnn->code[i] = pt->code[i];
			i++;
		}
		pnn->code[i] = NULL;
		pnn->next = NULL;
		l.attach(pnn);
	}
	drighti(pt->right, pt, l);
}
void temptoarr(unsigned char arr[], unsigned char temp)
{
	unsigned char m = 1;
	unsigned char r;
	int b = 7;
	for (int i = 0; i < 8; i++) {
		r = (m << b) & temp;
		if (r != 0)
			arr[i] = 1;
		else
			arr[i] = 0;
		b--;
	}
}
void main()
{
	char x[10000];
	node* pnn;
	list l;
	int s[10000];
	node* p;
	int j = 0, i = 0, n = 0, k = 0, ct = 0;
	cout << "please enter how many letters are here" << endl;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x[i] >> noskipws;
	}
	p = l.head;
	i = 0, j = 0, k = 0, ct = 0;
	while (k != n)
	{
		for (i = 0; i < n; i++)
		{
			if (x[k] == x[i])
			{
				s[k]++;
			}
		}

		p = l.head;
		if (l.head != NULL)
		{
			while (p != NULL)
			{
				if (x[k] == p->s[0])
				{
					ct = 1;
					break;
				}
				p = p->next;

			}
		}
		if (ct == 0)
		{
			pnn = new node;
			pnn->f = s[k];
			pnn->s[0] = x[k];
			pnn->s[1] = NULL;
			pnn->next = NULL;
			pnn->ro = NULL;
			l.insert(pnn);
			k++;
		}
		else
		{
			k++;
			ct = 0;
		}

	}
	p = l.head;
	snode* p1 = NULL;
	snode* p2 = NULL;
	snode* p3 = NULL;
	node* p4 = NULL;
	ct = 0, i = 0, j = 0;
	while (p->next != NULL)
	{
		i = 0;
		if (p->ro == NULL)
		{
			if (p->next->ro == NULL)
			{
				p1 = new snode;
				p1->f = p->f;
				while (p->s[i] != NULL)
				{
					p1->s[i] = p->s[i];
					i++;
				}
				p1->s[i] = NULL;
				p1->left = NULL;
				p1->right = NULL;
				i = 0;
				p2 = new snode;
				p2->f = p->next->f;
				while (p->next->s[i] != NULL)
				{
					p2->s[i] = p->next->s[i];
					i++;
				}
				p2->s[i] = NULL;
				p2->left = NULL;
				p2->right = NULL;
				p3 = new snode;
				p3->f = p1->f + p2->f;
				i = 0;
				while (p1->s[i] != NULL)
				{
					p3->s[i] = p1->s[i];
					i++;
				}
				j = 0;
				while (p2->s[j] != NULL)
				{
					p3->s[i] = p2->s[j];
					j++;
					i++;
				}
				p3->s[i] = NULL;
				p3->left = p1;
				p3->right = p2;
			}
			else if (p->next->ro != NULL)
			{
				i = 0;
				p1 = new snode;
				p1->f = p->f;
				while (p->s[i] != NULL)
				{
					p1->s[i] = p->s[i];
					i++;
				}
				p1->s[i] = NULL;
				p1->left = NULL;
				p1->right = NULL;
				p2 = new snode;
				p2 = p->next->ro;
				p3 = new snode;
				p3->f = p1->f + p2->f;
				i = 0;
				while (p1->s[i] != NULL)
				{
					p3->s[i] = p1->s[i];
					i++;
				}
				j = 0;
				while (p2->s[j] != NULL)
				{
					p3->s[i] = p2->s[j];
					j++;
					i++;
				}
				p3->s[i] = NULL;
				p3->left = p1;
				p3->right = p2;
			}

		}
		else if (p->ro != NULL)
		{
			if (p->next->ro == NULL)
			{
				p1 = new snode;
				p1 = p->ro;
				i = 0;
				p2 = new snode;
				p2->f = p->next->f;
				while (p->next->s[i] != NULL)
				{
					p2->s[i] = p->next->s[i];
					i++;
				}
				p2->s[i] = NULL;
				p2->left = NULL;
				p2->right = NULL;
				p3 = new snode;
				p3->f = p1->f + p2->f;
				i = 0;
				while (p1->s[i] != NULL)
				{
					p3->s[i] = p1->s[i];
					i++;
				}
				j = 0;
				while (p2->s[j] != NULL)
				{
					p3->s[i] = p2->s[j];
					j++;
					i++;
				}
				p3->s[i] = NULL;
				p3->left = p1;
				p3->right = p2;
			}
			else if (p->next->ro != NULL)
			{
				p1 = new snode;
				p1 = p->ro;
				p2 = new snode;
				p2 = p->next->ro;
				p3 = new snode;
				p3->f = p1->f + p2->f;
				i = 0;
				while (p1->s[i] != NULL)
				{
					p3->s[i] = p1->s[i];
					i++;
				}
				j = 0;
				while (p2->s[j] != NULL)
				{
					p3->s[i] = p2->s[j];
					j++;
					i++;
				}
				p3->s[i] = NULL;
				p3->left = p1;
				p3->right = p2;
			}
		}
		p4 = new node;
		p4->f = p3->f;
		i = 0;
		while (p3->s[i] != NULL)
		{
			p4->s[i] = p3->s[i];
			i++;
		}
		p4->s[i] = NULL;
		p4->next = NULL;
		p4->ro = p3;
		ct = 0;
		while (p != NULL)
		{
			ct++;
			p = p->next;
		}
		if (ct > 2)
		{
			l.head = l.head->next->next;
		}
		else if (ct == 2)
		{
			l.head = NULL;
		}
		l.insert(p4);
		p = l.head;
	}
	daks(p->ro, NULL, NULL);
	//PHASE TWO STARTS HERE
	lists g;
	drighti(p->ro, NULL, g);
	nodes* pg = g.head;
	unsigned char temp = 0, m = 1;
	unsigned char decomp[10000], comp[10000];
	int bit = 7, h = 0;
	k = 0;
	comp[0] = NULL;
	while (k != n)
	{
		pg = g.head;
		while (pg != NULL)
		{
			if (pg->s == x[k])
			{
				i = 0;
				while (pg->code[i] != NULL)
				{
					if (pg->code[i] == '1')
					{
						temp = temp | (m << bit);
						bit--;
						if (bit == -1)
						{
							bit = 7;
							comp[h] = temp;
							h++;
							temp = 0;
							comp[h] = NULL;
						}
					}
					else if (pg->code[i] == '0')
					{
						bit--;
						if (bit == -1)
						{
							bit = 7;
							comp[h] = temp;
							h++;
							temp = 0;
							comp[h] = NULL;
						}
					}
					i++;
				}
			}
			pg = pg->next;
		}
		k++;
	}
	int z, o;
	if (bit != 7)
	{
		z = bit;
		comp[h] = temp;
		o = h;
		h++;
		bit = 7;
		temp = 0;
		comp[h] = NULL;
	}
	h = 0;
	int ch = 0, w = 0, q = 0, u = 0;
	unsigned char e = 1, r;
	int v;
	while (h < (o + 1))
	{
		pg = g.head;
		while (pg != NULL)
		{
			i = 0;
			q = bit;
			u = h;
			while (pg->code[i] != NULL)
			{
				r = (e << bit) & comp[h];
				if (r != 0)
				{
					if (pg->code[i] != '1')
					{
						ch = 1;
						break;
					}
				}
				else
				{
					if (pg->code[i] != '0')
					{
						ch = 1;
						break;
					}
				}
				bit--;
				if (h == o && bit == z)
				{
					break;
				}
				if (bit == -1)
				{
					bit = 7;
					h++;
				}
				i++;
			}
			if (ch == 0)
			{
				decomp[w] = pg->s;
				w++;
				v = w;
				decomp[w] = NULL;
				break;
			}
			else if (ch == 1)
			{
				bit = q;
				if (u != h)
				{
					h = u;
				}
				ch = 0;
			}
			pg = pg->next;
			if (h == o && bit == z)
			{
				break;
			}
		}
		if (h == o && bit == z)
		{
			break;
		}
	}
	w = 0;
	while (comp[w] != NULL)
	{
		cout << comp[w] << " ";
		w++;
	}
	cout << endl << (w - 1) << endl;

	w = 0;
	while (w < v)
	{
		cout << decomp[w];
		w++;
	}
	cout << endl;
}
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

//tjiao
using namespace std;

//dp  huanqian
class Exchange
{
public:
	int countways(vector<int> penny, int n, int aim)
	{
		if (aim == 0){
			return 0;
		}
		vector<vector<int>> dp(n, vector<int>(aim + 1, 0));
		for (int i = 0; i < n; i++){
			dp[i][0] = 1;
		}
		for (int i = 1; i < aim + 1; i++)
		{
			if (i%penny[0] == 0){
				dp[0][i] = 1;
			}
			else{
				dp[0][i] = 0;
			}
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < aim + 1; j++)
			{
				if ((j - penny[i]) >= 0){
					dp[i][j] = dp[i - 1][j] + dp[i][j - penny[i]];
				}
				else{
					dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[n - 1][aim];
	}
};

//dp  taijie
class countstair
{
public:
	int upstair(int count)
	{
		vector<int> dp(2, 0);
		dp[0] = 1;
		dp[1] = 2;
		int tmp;
		for (int i = 3; i <= count; i++){
			tmp = dp[0];
			dp[0] = dp[1];
			dp[1] = tmp + dp[1];
		}
		return dp[1];
	}
};

//kuai pai
void fastsort(vector<int>& array, int left, int right)
{
	if (left >= right){
		return;
	}
	vector<int> leftvec;
	vector<int> rightvec;
	int tmp;
	int zhidian = (left + right) / 2;
	for (int i = left; i<right; i++)
	{
		if (i == zhidian){
			tmp = array[i];
		}
		else if (array[i]<array[zhidian]){
			leftvec.push_back(array[i]);
		}
		else{
			rightvec.push_back(array[i]);
		}
	}
	for (int i = left; i < right; i++)
	{
		if (i < left + leftvec.size())
			array[i] = leftvec[leftvec.size() - i - 1 + left];
		else if (i == left + leftvec.size())
			array[i] = tmp, zhidian = i;
		else
			array[i] = rightvec[rightvec.size() - i + leftvec.size() + left];
	}
	fastsort(array, left, zhidian);
	fastsort(array, zhidian + 1, right);
}

class TwoSum {
public:
	vector<int> twosum(vector<int>& numbers, int target) {
		unordered_map<int, int> hash;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];
			if (hash.find(numberToFind) != hash.end()) {
				result.push_back(hash[numberToFind]);
				result.push_back(i);
				return result;
			}
			hash[numbers[i]] = i;
		}
		return result;
	}
};

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {}
};
class AddTwoNumber {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode res(0), *p = &res;
		int jinwei = 0;
		while (l1 || l2 || jinwei>0)
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + jinwei;
			jinwei = sum / 10;
			int tmp = sum % 10;
			p->next = new ListNode(tmp);
			p = p->next;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return res.next;
	}
};

class longestnorepeat {
public:
	int lengthOfLongestSubstring(string s)
	{
		vector<int> res(256, -1);
		int left = -1;
		int maxlen = 0;
		for (int i = 0; i<s.length(); i++){
			if (res[s[i]]>left){
				left = res[s[i]];
			}
			res[s[i]] = i;
			maxlen = max(maxlen, i - left);
		}
		return maxlen;
	}
};


struct node
{
	int data;
	node* next;
};
node* reverse(node* head)
{
	node* p, *q, *r;
	if (head->next=NULL){
		return head;
	}
	p = head->next;
	q = p->next;
	p->next = NULL;
	while (q!=NULL){
		r = q->next;
		q->next=p;
		p = q;
		q = r;
	}
	head->next = p;
	return head;
}

class HeapSort
{
public:
	int heapsize=0;
	void maxheapify(int array[],int idx)
	{
		int largest = 0;
		int left = 2 * idx + 1;
		int right = 2 * idx + 2;
		if ((left<=heapsize)&&(array[left]>array[idx])){
			largest = left;
		}
		else{
			largest = idx;
		}
		if (right <= heapsize&&array[right]>array[largest]) {
			largest = right;
		}
		if (largest!=idx){
			int tmp = array[idx];
			array[idx] = array[largest];
			array[largest] = tmp;
			maxheapify(array, largest);
		}
	}
	void bulidmaxheap(int array[],int length)
	{
		heapsize = length;
		for (int i = (heapsize>>1); i>=0 ; i--){
			maxheapify(array,i);
		}
	}
	void heapsort(int array[],int length)
	{
		bulidmaxheap(array, (length - 1));
		for (int i = (length-1); i>=1; i--){
			int tmp = array[0];
			array[0] = array[i];
			array[i] = tmp;
			heapsize--;
			maxheapify(array,0);
		}
	}
};

void string_op()
{
	//gou zao 
	string str1 = "yesterday once more";
	string str2("my heart go on");
	string str3(str1, 6); // = day once more
	string str4(str1, 6, 3); // = day
	//han shu
	str3.assign(str2, 3, 6);  // = heart
	str4.assign(str2, 3, string::npos); // = heart go on (��2��ʼ����β����str4)
	str4.assign("gaint"); // =gaint
	str4.assign("nico", 5); // = nico���������Ȼᷢ��ʲô������
	str4.assign(5, 'x'); // = xxxxx
	str2.swap(str1);
	str1 += "sss";//�Ӹ�C�ַ��� 
	//.insert();erase();clear();replace();length();empty();[ ], at() //��ȡ��һ�ַ� 
	//>>,<<,getline();substr(2,3);find() 
}

int maxsub(int array[],int length)
{
	int maxsub = -1;
	int sum = -1;
	for (int i = 0; i < length; i++){
		sum = max(array[i],sum+array[i]);
		maxsub = max(sum,maxsub);
	}
	return maxsub;
}

int missnum(vector<int> nums)
{
	int left = 0;
	int tmpsum = nums.size();
	while (left < tmpsum){
		if (nums[left]==left+1){
			left++;
		}
		else if (nums[left]> tmpsum || nums[left] < left+1||nums[nums[left]-1]==nums[left]){	
			tmpsum--;
			nums[left] = nums[tmpsum];
		}
		else{
			swap(nums[left], nums[nums[left]-1]);
		}
	}
	return left+1;
}



struct btree
{
	int data;
	btree* left;
	btree* right;
};
void create_tree(btree* &root)
{
	char ch;
	cin >> ch;
	if (ch == '#'){
		root = NULL;
	}
	else{
		root = new btree;
		root->data = ch;
		create_tree(root->left);
		create_tree(root->right);
	}
}
int count_k(btree* head,int k)
{
	if (head==NULL||k<=0){
		return 0;
	}
	if (head!= NULL&&k==1){
		return 1;
	}
	return(count_k(head->left, k - 1) + (head->right, k - 1));
}




int miss_num(vector<int> tar)
{
	int tmpsum = tar.size();
	int left = 0;
	while (left<tmpsum)
	{
		if (tar[left] == left + 1)
		{
			left++;
		}
		else if (tar[left] <= left || tar[left]>tmpsum || tar[tar[left] - 1] == tar[left])
		{
			tmpsum--;
			tar[left] = tar[tmpsum];
		}
		else
		{
			swap(tar[left], tar[tar[left] - 1]);
		}
	}
	
	return left + 1;
}














void main()
{
	/*int k,kum;
	btree* root;
	root = NULL;
	create_tree(root);
	cout << "���������k:" << endl;
	cin >> k;
	cout << "�ݹ���������" << endl;
	kum = count_k(root, k);
	cout << "��" << k << "��Ľڵ����Ϊ��" << kum<< endl;*/


	for (int i = 11; i > 0; --i)
	{
		int a = i + 10;
		cout << a<< endl;
	}

	vector<int> test = { 4,-1,3,1 };
	int tt=miss_num(test);
	int a[8] = { 45,68,20,39,88,97,46,59 };
	HeapSort sort;
	sort.heapsort(a, 8);
	for (int i = 0; i < 8; i++){
		cout << a[i] << endl;
	}
	int b[6] = {-2,11,-4,13,-5,-2};
	int submax = maxsub(b,6);
	cout << submax << endl;
	int bb = 0;
}
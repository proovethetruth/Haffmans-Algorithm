
/*!
	\file
	\brief ������������ ���� � ��������� ������� � ��������

	������ ���� �������� � ���� ����������� ��������� Node, � ����������� �������, ������������ � ���������.
*/

#ifndef HAFFMAN_ALGORITHM_H
#define HAFFMAN_ALGORITHM_H

#include <string>
#include <unordered_map>

/*!
	\brief ��������� ���� ������ ��������

	���� ������ �������� �������� ������, ������� ��� ���������, � ����� ��������� �� ���������� �����.
*/
struct Node {
	char ch = 0;
	int freq = 0;
	Node* left = nullptr, * right = nullptr;

	Node() {}
	Node(char val) {
		ch = val;
	}

	Node(char character, Node* left, Node* right) {
		Node* node = new Node();

		ch = character;
		freq = 0;
		left = left;
		right = right;
	}
};

//! \brief ���������, ����������� �������� ��������� ��������� ��� ������������ �������
struct comp {
	bool operator()(Node* l, Node* r) {
		return l->freq > r->freq;
	}
};

// main.cpp
/*!
		\brief ������� ��� ����������� ������ (������ / ������������)
		\param[in] argv[] ���������� � ��������� ������ ���������
		\return ��� ����� -en | -encode ���������� 1. ��� -de | -decode ���������� -1
*/
int check_task(char* argv[]);

// fstream.cpp
/*!
		\brief ������� ��� ��������� ����� ������� �����
		\param[in] original �������� ��������� �����
		\return ������ � ��������� ��� ������ ������
*/
std::string gen_en_filename(std::string original);

/*!
		\brief ������� ��� ��������� ����� ������������������ �����
		\param[in] original �������� ��������� �����
		\return ������ � ��������� ��� ��������������� ������
*/
std::string gen_de_filename(std::string original);

/*!
		\brief ������� ��� ������ ���-�� �������������� ����� � �������� ����
		\param[in] outfile ����, �������� � �������� ������
		\param[in] bits ���-�� �������������� ����� (0 <= bits < 8)
*/
void insert_zeros_counter(std::ofstream& outfile, int bits);

/*!
		\brief ������� ��� ������ ������� ������ � �������� ����
		\param[in] outfile ����, �������� � �������� ������ 
		\param[in] str ������� ������
*/
void writeBinaryString(std::ofstream& outfile, std::string& str);
/*!
		\brief ������� ��� ������ ����� � �������� ����
		\details ��� ������� ����������� ������ ����� � ����, 
		����� ���������� ��� � �������� ����. ��������� ����
		����� ��������� �������������, ����� ���� �������������
		���� ������� ������� ������������ ������ ������� FlushBits()
		��� ������� �������������� �����
		\param[in] bit ��� (0 ��� 1)
		\param[in] outfile ����, �������� � �������� ������
*/
void WriteBit(int bit, std::ostream& outfile);
/*!
		\brief ������� ��� ������� �������������� �����
		\details ������� writeBinaryString() ����� �� �������� ����,
		� ������ ���� �������� ������������������ �� ������� ��� 
		������� �� ����. ��� ����, ����� �������� ��� ������ ���������
		���� ����������� ������������ ������
		\param[in] outfile ����, �������� � �������� ������
*/
void Flush_Bits(std::ostream& outfile);

/*!
		\brief ������� ��� ��������� ��������� ������������� ��������� ������ ��������
		\details ��� ��������� ��������� ������������� ������ ������������
		������ ����� (NLR). ���� ������� ���� �������� ������ (�� ����� ��������)
		, �� � ������ ����������� ������� � ������ ����� ����. ���� ������� ����
		�� �������� ������, � ������ ������������ ���� � ���������� ����������� ����� �������
		\param[in] node ��������� �� ������ ������
		\param[in] result ������ �� ������, � ������� ����� �������� ���������
*/
void writeBinaryTree(Node* node, std::string& result);

/*!
		\brief ������� ��� ��������� ��������� ������ �������� �� ������ ��� ��������� �������������
		\details ���� ������� ������ ����� �������, ��� ������, ��� ��������� �� ��� ������ �������� ������
		\param[in] str ������ �� ������, � ������� ���������� ��������� ������������� ������ ��������
		\param[in] index ������ �� ������
		\return ��������� �� ������ ������
*/
Node* readBinaryTree(std::string& str, int& index);

/*!
		\brief ������� ��� ���������� ��������� ������
		\param[in] name ������ �� ��� �����
		\param[in] text ������ �� ������, � ������� ����� �������� ���������
		\return ��� �������� ���������� - 1, ����� - 0
*/
int parse_file(std::string& name, std::string& text);

/*!
		\brief ������� ��� ���������� ��������� ������������� ������ �� ��������� �����
		\param[in] infile ������ �� ����, �������� � �������� ������
		\param[in] text ������ �� ������, � ������� ����� �������� ���������
		\return ����� ��������� ������������� ������
*/
int parse_tree(std::ifstream& infile, std::string& text);

/*!
		\brief ������� ��� ���������� ������ ������ �� ��������� �����
		\details � ���������������� ����� ������ ������ �������� ���-��
		�������������� ����� ����������� �������� Flush_Bits(). ��������� �� ���
		����� - ����� ��������� ������������� ������. ����� ������� ��������������
		������, ��������������� ��������� ������������� ������, � ������ �����.
		\param[in] infile ������ �� ����, �������� � �������� ������
		\param[in] text ������ �� ������, � ������� ����� �������� ���������
		\param[in] tree_size ����� ��������� ������������� ������
		\param[in] zeros ���-�� �������������� �����
*/
void parse_binary_text(std::ifstream& infile, std::string& text, int tree_size, int zeros);

// encode.cpp
/*!
		\brief ������� ��� �������� ����
		\param[in] ch ������ ����
		\param[in] freq ������� ������������ ������� � �������� ������
		\param[in] left ��������� �� ����� �����
		\param[in] right ��������� �� ������ �����
*/
Node* addNode(char ch, int freq, Node* left, Node* right);

/*!
		\brief ������� ��� ��������� ������
		\details �������� �������� �������� �������� ����� ����������� �������
		��������� ������ ������� �����, � ����� ����������� ������� ��������� 
		������ ������� �����. ����� �������, ������� ������� �� �� ���������������
		����, ���������� � ���� ������ ������ �������� ����� ����� ����
		\param[in] name ��� �����
		\return ��� �������� ���������� - 1, ����� - 0
*/
int pack(std::string& name);

/*!
		\brief ������� ��� ����������� ����� ��������
		\details ����������� ������ ����� ������ (NLR). ��� �������� � ����� �����,
		�� ��������� ������� �������� ���������� ������ � ����������� � ��� ����,
		� ������ - � ��������. ���� ������� ���� �������� ������ (�� ����� ��������)
		- ����������� ������� ����� ���� ���������� � ���� �������� ������.
		\param[in] root ��������� �� ������ ������
		\param[in] str ������, ����������� ��� ������ ��������
		\param[in] huffmanCode ������ ������ ��� ������-������ ��� ������ �����
*/
void encode(Node* root, std::string str, std::unordered_map<char, std::string>& huffmanCode);

/*!
		\brief ������� ��� ����������� ������� ������������ �������� � �������� ������
		\param[in] text ������ �� �����
		\return ������ ��� ������-�������
*/
std::unordered_map<char, int> find_frequency(std::string& text);

/*!
		\brief ������� ��� ��������� ������ ��������
		\details �������� ������������ �������, ������� � ����������� �����������
		 ������ (������-�������). ����� �������� ����� ���� ��������� ������, 
		 ������� �������� �����	����� ������ ���� �������� � ��������� ��������, 
		 ������� ����� ���������� ��� �������� � ��������� �� ������������ �������.
		 ������� ����������� ��	��� ���, ���� ��� ������� �� ������ �������� ������
		\param[in] freq ������ ��� ������-�������
		\return ��������� �� ������ ��������� ������ ��������
*/
Node* build_tree(std::unordered_map<char, int> freq);

// decode.cpp
/*!
		\brief ������� ��� ������������ ������
		\details ����������� ���-�� �������������� �����, �� ��������� ���������
		������������� ������������ �������� ������ ��������, ����� ���� ���������
		�������������� ����� ������������ � ������� ������ ������ ��������
		\param[in] name ��� �����
		\return ��� �������� ���������� - 1, ����� - 0 
*/
int unpack(std::string& name);

/*!
		\brief ������� ��� ������������� ������� ������������������
		\details 
		\param[in] root ��������� �� ������ ������ ��������
		\param[in] index ������ �� ������� ������ ��������� ������� ��������
		\param[in] str ������������������ ����� (�������������� �����)
		\param[in] outfile ������ �� ���� ��� ���������� ����������
*/
void decode(Node* root, int& index, std::string str, std::ofstream& outfile);

#endif

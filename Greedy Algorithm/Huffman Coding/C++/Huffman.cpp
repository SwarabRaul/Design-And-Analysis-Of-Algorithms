#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node
{
public:
    char c;
    int freq;
    Node *left, *right;

    Node(char c, int freq)
    {
        this->c = c;
        this->freq = freq;
        this->left = nullptr;
        this->right = nullptr;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

class Compare
{
public:
    bool operator()(Node *n1, Node *n2)
    {
        return n1->freq > n2->freq;
    }
};

Node *buildHuffmanTree(string text)
{
    unordered_map<char, int> freq_map;

    for (char c : text)
    {
        freq_map[c]++;
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (auto it = freq_map.begin(); it != freq_map.end(); it++)
    {
        pq.push(new Node(it->first, it->second));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

void buildHuffmanCodes(Node *root, string code, unordered_map<char, string> &codes)
{
    if (root == nullptr)
    {
        return;
    }

    if (root->c != '\0')
    {
        codes[root->c] = code;
    }

    buildHuffmanCodes(root->left, code + "0", codes);
    buildHuffmanCodes(root->right, code + "1", codes);
}

string encode(string text, unordered_map<char, string> &codes)
{
    string encoded_text = "";

    for (char c : text)
    {
        encoded_text += codes[c];
    }

    return encoded_text;
}

string decode(string encoded_text, Node *root)
{
    string decoded_text = "";
    Node *current = root;

    for (char c : encoded_text)
    {
        if (c == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (current->c != '\0')
        {
            decoded_text += current->c;
            current = root;
        }
    }

    return decoded_text;
}

int main()
{
    string text = "ABBCDBCCDAABBEEEBEAB";
    Node *root = buildHuffmanTree(text);
    unordered_map<char, string> codes;
    buildHuffmanCodes(root, "", codes);
    string encoded_text = encode(text, codes);
    string decoded_text = decode(encoded_text, root);
    cout << "Original text: " << text << endl;
    cout << "Encoded text: " << encoded_text << endl;
    cout << "Decoded text: " << decoded_text << endl;
    cout << "Huffman codes: " << endl;
    for (auto it = codes.begin(); it != codes.end(); it++)
    {
        cout << it->first << " : " << it->second << endl;
    }
    delete root;
    return 0;
}
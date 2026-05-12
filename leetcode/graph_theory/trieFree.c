// Trie（发音类似 "try"）或者说 前缀树 是一种树形数据结构，
// 用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

// 请你实现 Trie 类：

// Trie() 初始化前缀树对象。
// void insert(String word) 向前缀树中插入字符串 word 。
// boolean search(String word) 如果字符串 word 在前缀树中，返回 true（即，在检索之前已经插入）；否则，返回 false 。
// boolean startsWith(String prefix) 如果之前已经插入的字符串 word 的前缀之一为 prefix ，返回 true ；否则，返回 false 。

#include <stdbool.h>
#include <stdlib.h>

// 前缀树节点结构
typedef struct TrieNode
{
    // 每个节点有 26 个字母子节点
    struct TrieNode *children[26];
    // 标记：是否是一个单词的结尾
    bool isEnd;
} TrieNode;

typedef struct
{
    TrieNode *root;
} Trie;

struct TrieNode *createTrieNode()
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEnd = false;

    for (int i = 0; i < 26; i++)
    {
        node->children[i] = NULL;
    }

    return node;
}

Trie *trieCreate()
{
    Trie *trie = (Trie *)malloc(sizeof(Trie));
    trie->root = createTrieNode();
    return trie;
}

void trieInsert(Trie *obj, char *word)
{
    TrieNode *root = obj->root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int idx = word[i] - 'a';
        if (root->children[idx] == NULL)
        {
            root->children[idx] = createTrieNode();
        }

        root = root->children[idx];
    }

    root->isEnd = true;
}

bool trieSearch(Trie *obj, char *word)
{
    TrieNode *root = obj->root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int idx = word[i] - 'a';
        if (root->children[idx] == NULL)
        {
            return false;
        }

        root = root->children[idx];
    }

    return root->isEnd;
}

bool trieStartsWith(Trie *obj, char *prefix)
{
    TrieNode *root = obj->root;

    for (int i = 0; prefix[i] != '\0'; i++)
    {
        int idx = prefix[i] - 'a';
        if (root->children[idx] == NULL)
        {
            return false;
        }

        root = root->children[idx];
    }

    return true;
}

// 递归释放内存
static void freeNode(TrieNode *node)
{
    if (!node)
        return;
    for (int i = 0; i < 26; i++)
    {
        freeNode(node->children[i]);
    }
    free(node);
}

// 释放整棵前缀树
void trieFree(Trie *obj)
{
    freeNode(obj->root);
    free(obj);
}

/**
 * Your Trie struct will be instantiated and called as such:
 * Trie* obj = trieCreate();
 * trieInsert(obj, word);

 * bool param_2 = trieSearch(obj, word);

 * bool param_3 = trieStartsWith(obj, prefix);

 * trieFree(obj);
*/
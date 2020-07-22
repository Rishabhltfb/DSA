#include <iostream>
#include <bits/stdc++.h>
#define fo(i, n) for (long int i = 1; i < n; i++)

using namespace std;

struct node
{
    long int key, points;
    struct node *left, *right;
};

struct node *newNode(long int item, long int points)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->points = points;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *node, long int key, long int points, vector<struct node *> &addresses)
{
    /* If the tree is empty, return a new node */
    if (node == NULL)
    {
        struct node *ptr = newNode(key, points);
        addresses.push_back(ptr);
        return ptr;
    }

    /* Otherwise, recur down the tree */
    if (key <= node->key)
        node->left = insert(node->left, key, points, addresses);
    else if (key > node->key)
        node->right = insert(node->right, key, points, addresses);

    /* return the (unchanged) node pointer */
    return node;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        // printf("%d \n", root->key);
        cout << "height: " << root->key << "   taste: " << root->points << endl;
        inorder(root->right);
    }
}
// void PrintArr(long int *Arr, long int N)
// {
//     cout << "Printing:" << endl;
//     fo(j, N)
//     {
//         cout << *(Arr + j) << " ";
//     }
//     cout << endl;
// }

// bool checkPossibility(long int start, long int end, long int *heights)
// {
//     if (start > end)
//     {
//         for (int j = start - 2; j >= end - 1; j--)
//         {
//             if (*(heights + j) >= *(heights + start - 1))
//             {
//                 return false;
//             }
//         }
//     }
//     else if (start < end)
//     {
//         for (int j = start; j < end; j++)
//         {
//             if (*(heights + j) >= *(heights + start - 1))
//             {
//                 return false;
//             }
//         }
//     }

//     return true;
// }

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int Q, N, q, b, k, maxT = 0;
    long int minHeight, maxHeight;
    struct node *root = NULL;
    struct node *startNode = NULL;
    struct node *endNode = NULL;
    bool isPossible = true;
    cin >> N;
    cin >> Q;
    long int heights[N + 1];
    long int tastes[N + 1];
    vector<struct node *> addresses;
    vector<node *>::iterator itr;
    fo(i, N + 1)
    {
        cin >> heights[i];
    }
    cin >> tastes[1];
    root = insert(root, heights[1], tastes[1], addresses);
    fo(i, N)
    {
        cin >> tastes[i + 1];
        insert(root, heights[i + 1], tastes[i + 1], addresses);
    }
    inorder(root);
    // cout << "ab mera tareeka" << endl;
    // for (itr = addresses.begin(); itr != addresses.end(); ++itr)
    // {
    //     cout << "height: " << (*itr)->key << "  tastes: " << (*itr)->points << " address: " << *(itr) << endl;
    // }
    fo(i, Q + 1)
    {
        maxT = 0;
        cin >> q;
        cin >> b;
        cin >> k;
        if (q == 1)
        {
            tastes[b] = k;
        }
        else
        {
            if (heights[b] <= heights[k])
            {
                maxT = -1;
            }
            else
            {
                if (b > k)
                {
                    endNode = addresses[b - 1];
                    startNode = addresses[0];
                    inorder(startNode);
                    cout << "!!!!!!!!!" << endl;
                    startNode = addresses[1];
                    inorder(startNode);
                    cout << "!!!!!!!!!" << endl;
                    startNode = addresses[2];
                    inorder(startNode);
                    cout << "!!!!!!!!!" << endl;
                    startNode = addresses[3];
                    inorder(startNode);
                    cout << "!!!!!!!!!" << endl;
                    startNode = addresses[4];
                    inorder(startNode);
                }
                else if (b < k)
                {
                }
                else
                {
                    maxT = tastes[b];
                }
            }

            cout << maxT << endl;
        }
    }

    return 0;
}

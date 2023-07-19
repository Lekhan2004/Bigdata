#include<stdio.h>
#include<stdlib.h>
struct node
{
    int x,h;
    struct node* l;
    struct node* r;
};
struct node* root = NULL;
// function prototypes
struct node* create(int);
struct node* insert(struct node*, int);
struct node* del(struct node*, int);
struct node* search(struct node*, int);
struct node* rotateleft(struct node*);
struct node* rotateright(struct node*);
int balancefactor(struct node*);
int height(struct node*);
void inorder(struct node*);
void preorder(struct node*);
void postorder(struct node*);
int main()
{
    int ch, x,cont=1;
    struct node* result = NULL;
    printf("    AVL TREE   \n");
    while (cont ==1)
    {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Search");
        printf("\n4. Inorder");
        printf("\n5. Preorder");
        printf("\n6. Postorder");
        printf("\n7. EXIT");
        printf("\nEnter Your Choice: ");
        scanf("%d", &ch);
 
        switch(ch)
        {
            case 1:
                printf("\nEnter data: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;
            case 2:
                printf("\nEnter data: ");
                scanf("%d", &x);
                root = del(root, x);
                break;
            case 3:
                printf("\nEnter data: ");
                scanf("%d", &x);
                result = search(root, x);
                if (result == NULL)
                    printf("\nNot found");
                else
                    printf("\nfound");
                break;
            case 4:
                inorder(root);
                break;
            case 5:
                preorder(root);
                break;
            case 6:
                postorder(root);
                break;
            case 7:
                printf("\nProgram End\n");
                return 1;
            default:
                printf("\nInvalid Choice\n");
        }
        printf("\nDo you want to continue? ");
        scanf("%d", &cont);
    }
    return 0;
}
// creates a new node
struct node* create(int x)
{
    struct node* nn = (struct node*) malloc (sizeof(struct node));
    nn->x = x;
    nn->l = NULL;
    nn->r = NULL;
    return nn;
}
// rotates to the left
struct node* rotateleft(struct node* root)
{
    struct node* rc = root->r;
    root->r = rc->l;
    rc->l = root;
    // update the heights 
    root->h = height(root);
    rc->h = height(rc);
    // return the new node address
    return rc;
}
// rotates to the right
struct node* rotateright(struct node* root)
{
    struct node* lc= root->l;
    root->l = lc->r;
    lc->r = root;
    // update the heights 
    root->h = height(root);
    lc->h = height(lc);
    // return the new node address
    return lc;
}
// calculates the balance factor 
int balancefactor(struct node* root)
{
    int lh, rh;
    if (root == NULL)
        return 0;
    if (root->l == NULL)
        lh = 0;
    else
        lh = 1 + root->l->h;
    if (root->r == NULL)
        rh = 0;
    else
        rh = 1 + root->r->h;
    return lh - rh;
}
// calculate the height of the node
int height(struct node* root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    if (root->l == NULL)
        lh = 0;
    else
        lh = 1 + root->l->h;
    if (root->r== NULL)
        rh = 0;
    else
        rh = 1 + root->r->h;
 
    if (lh > rh)
        return (lh);
    return (rh);
}

struct node* insert(struct node* root, int x)
{
    if (root == NULL)
    {
        struct node* nn = create(x);
        if (nn == NULL)
            return NULL;
        root = nn;
    }
    else if (x > root->x)
    {
        // insert the new node to the right
        root->r = insert(root->r, x);
        // tree is unbalanced, then rotate it
        if (balancefactor(root) == -2)
        {
            if (x > root->r->x)
                root = rotateleft(root);
            else
            {
                root->r = rotateright(root->r);
                root = rotateleft(root);
            }
        }
    }
    else
    {
        // insert the new node to the left
        root->l = insert(root->l, x);
        // tree is unbalanced, then rotate it
        if (balancefactor(root) == 2)
        {
            if (x < root->l->x)
                root = rotateright(root);
            else
            {
                root->l= rotateleft(root->l);
                root = rotateright(root);
            }
        }
    }
    // update the heights
    root->h= height(root);
    return root;
}
// deletes a node from the tree
struct node * del(struct node *root, int x)
{
    struct node * temp = NULL;
    if (root == NULL)
        return NULL;
    if (x > root->x)
    {
        root->r = del(root->r, x);
        if (balancefactor(root) == 2)
        {
            if (balancefactor(root->l) >= 0)
                root = rotateright(root);
            else
            {
                root->l = rotateleft(root->l);
                root = rotateright(root);
            }
        }
    }
    else if (x < root->x)
    {
        root->l = del(root->l, x);
        if (balancefactor(root) == -2)
        {
            if (balancefactor(root->r) <= 0)
                root = rotateleft(root);
            else
            {
                root->r= rotateright(root->r);
                root = rotateleft(root);
            }
        }
    }
    else
    {
        if (root->r != NULL)
        { 
            temp = root->r;
            while (temp->l != NULL)
                temp = temp->l;
            root->x = temp->x;
            root->r = del(root->r, temp->x);
            if (balancefactor(root) == 2)
            {
                if (balancefactor(root->l) >= 0)
                    root = rotateright(root);
                else
                {
                    root->l = rotateleft(root->l);
                    root = rotateright(root);
                }
            }
        }
        else
            return (root->l);
    }
    root->h = height(root);
    return (root);
}
// search a node in the tree
struct node* search(struct node* root, int key)
{
    if (root == NULL)
        return NULL;
    if(root->x == key)
        return root;
    if(key > root->x)
        search(root->r, key);
    else
        search(root->l, key);
}
// inorder traversal 
void inorder(struct node* root)
{
    if (root == NULL)
        return;
    inorder(root->l);
    printf("%d ", root->x);
    inorder(root->r);
}
// preorder traversal 
void preorder(struct node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->x);
    preorder(root->l);
    preorder(root->r);
}
// postorder traversal 
void postorder(struct node* root)
{
    if (root == NULL)
        return;
    postorder(root->l);
    postorder(root->r);
    printf("%d ", root->x);
}

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct
{
     int *array;
     int front, rear;
     unsigned int capacity;
} Queue;

Queue *createQueue(unsigned int capacity)
{
     Queue *queue = (Queue *)malloc(sizeof(Queue));
     if (!queue)
     {
          fprintf(stderr, "Memory allocation error\n");
          exit(EXIT_FAILURE);
     }
     queue->capacity = capacity;
     queue->front = queue->rear = -1;
     queue->array = (int *)malloc(queue->capacity * sizeof(int));
     if (!queue->array)
     {
          fprintf(stderr, "Memory allocation error\n");
          exit(EXIT_FAILURE);
     }
     return queue;
}

int isFull(Queue *queue)
{
     return ((queue->rear + 1) % queue->capacity == queue->front);
}

int isEmpty(Queue *queue)
{
     return (queue->front == -1);
}

void enqueue(Queue *queue, int item)
{
     if (isFull(queue))
     {
          printf("Queue is full\n");
          return;
     }
     queue->rear = (queue->rear + 1) % queue->capacity;
     queue->array[queue->rear] = item;
     if (queue->front == -1)
     {
          queue->front = queue->rear;
     }
}

int dequeue(Queue *queue)
{
     int item;
     if (isEmpty(queue))
     {
          printf("Queue is empty\n");
          return -1;
     }
     item = queue->array[queue->front];
     if (queue->front == queue->rear)
     {
          queue->front = queue->rear = -1;
     }
     else
     {
          queue->front = (queue->front + 1) % queue->capacity;
     }
     return item;
}

void display(Queue *queue)
{
     if (isEmpty(queue))
     {
          printf("Queue is empty\n");
          return;
     }
     printf("Queue elements are:\n");
     int i;
     for (i = queue->front; i != queue->rear; i = (i + 1) % queue->capacity)
     {
          printf("%d ", queue->array[i]);
     }
     printf("%d\n", queue->array[i]);
}

struct node
{
     int data;
     struct node *left;
     struct node *right;
};

struct node *createBT(struct node *root)
{
     int data;
     printf("Enter The Data: ");
     scanf("%d", &data);
     if (data == -1)
     {
          root = NULL;
     }
     else
     {
          struct node *new = (struct node *)malloc(sizeof(struct node));
          new->data = data;
          new->left = NULL;
          new->right = NULL;
          root = new;
          printf("For %d's Left Node ", data);
          root->left = createBT(root->left);
          printf("For %d's Right Node ", data);
          root->right = createBT(root->right);
     }
     return root;
}

int arr[11];
int i = 0;

void inorder_traversal(struct node *root)
{
     if (root != NULL)
     {
          inorder_traversal(root->left);
          printf("%d ", root->data);
          inorder_traversal(root->right);
     }
}

void serialize(struct node *root)
{
     if (root != NULL)
     {
          arr[i] = root->data;
          i++;
          serialize(root->left);
          serialize(root->right);
     }
     else
     {
          arr[i] = 0;
          i++;
     }
}

static int j = 0;
int n = 11;

struct node* create_node(int data){
     struct node* new = (struct node*)malloc(sizeof(struct node));
     new->data=data;
     new->left = NULL;
     new->right = NULL;
     return new;
}


struct node *deserialize(Queue *queue)
{
     if (isEmpty(queue))
     {
          return NULL;
     }
     struct node* new_root = NULL;
     int d = dequeue(queue);
     if (d != 0)
     {
          new_root = create_node(d);
          printf("now new node is %d\n",new_root->data);
          new_root->left = deserialize(queue);
          new_root->right = deserialize(queue);
     }
     else{
          return NULL;
     }
     return new_root;
}

int main()
{
     struct node *root = NULL;
     root = createBT(root);
     // inorder_traversal(root);
     serialize(root);
     Queue *queue = createQueue(n);
     for (int i = 0; i < n; i++)
     {
          enqueue(queue, arr[i]);
     }
     struct node * new_root = NULL;
     new_root = deserialize(queue);
     inorder_traversal(new_root);
     return 0;
}
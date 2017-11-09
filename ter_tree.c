#include<stdio.h>
#include<stdlib.h>



tree *initree(Point val)
{
  tree *Tree = malloc(sizeof(tree));
  Tree->left = NULL;
  Tree->right= NULL;
  Tree->top=NULL;
  Tree->bot=NULL;
  Tree->dad=NULL;
  Tree->value=val;
  return Tree;
}

void add_left(Point val,tree *Tree)
{
  if(Tree->left!=NULL)
    return;
  Tree->left=initree(val);
  Tree->left->dad=Tree;
}

void add_right(Point val,tree *Tree)
{
  if(Tree->right!=NULL)
    return;
  Tree->right=initree(val);
  Tree->right->dad=Tree;
}

void add_top(Point val,tree *Tree)
{
  if(Tree->top!=NULL)
    return;
  Tree->top=initree(val);
  Tree->top->dad=Tree;
}

void add_bot(Point val,tree *Tree)
{
  if(Tree->bot!=NULL)
    return;
  Tree->bot=initree(val);
  Tree->bot->dad=Tree;
}


//parcours pofondeur main gauche en infix
void printleft_hand(tree *Tree)
{
  if (Tree==NULL)
  {	
    printf("\n");
    return ;
  }
  printleft_hand(Tree->left);
  printf("- %d,%d",Tree->value.x,Tree->value.y);
  printleft_hand(Tree->right);
  printleft_hand(Tree->top);
  printleft_hand(Tree->bot);
}
int height_tree(tree *node)
{
  int i=0;
  tree *tmp = node;
  while(tmp->dad!=NULL)
  {
    i+=1;
    tmp=tmp->dad;
  }
  return i;
}

void printwidth(tree *tree)
{

  Queue *queue=init_queue();
  enqueue(queue,tree);
  struct TREE *leaf[W_Map*(H_Map/2)][W_Map]={{NULL}}; //liste des feuille de chaque hauteur
  while (!is_empty(queue))
  {
    struct TREE *node=dequeue(queue);
    if(node!=NULL)
    {
      printf("%d,%d\n",node->value.x, node->value.y);

      if(node->left!=NULL)
	enqueue(queue,node->left);
      if(node->right!=NULL)
	enqueue(queue,node->right);
      if(node->top!=NULL)
	enqueue(queue,node->top);
      if(node->bot!=NULL)
	enqueue(queue,node->bot);
      if(node->bot==NULL && node->top==NULL && node->left==NULL && node->right==NULL) //verifie si le noeud actuel est une feuille
	leaf[height_tree(node)][0/*??*/]=node;
    }
  }
}
void leaf_equidistant(Point pos[],tree *leaf[][W_Map],Case map[][H_Map])
{
  int i=0, j=0;
  while(i<W_Map*(H_Map/2))
  {
    for(j=0;j<5;j++)
    {
      if(leaf[i][j]!=NULL)
      {
	Point p={leaf[i][j]->value.x,leaf[i][j]->value.y};
	tree *tmp=initree(p);
	build_tree(map,p,tmp);
      }
    }
  }
}


//Queue
Queue *init_queue()
{
  Queue *queue = malloc(sizeof(Queue));
  queue->next=NULL;
  return queue;
}
int is_empty(Queue *queue)
{
  return queue->next==NULL;
}
void enqueue(Queue *queue,tree *val)
{

  Queue *temp=init_queue();
  temp->value=val;
  if(!is_empty(queue))
    temp->next=queue->next;
  queue->next=temp;
}

tree *dequeue(Queue *queue)
{
  tree *tree;
  Queue *temp=queue;
  while(temp->next->next!=NULL)
    temp=temp->next;		    
  tree=temp->next->value;
  free(temp->next);
  temp->next=NULL;
  return tree;

}


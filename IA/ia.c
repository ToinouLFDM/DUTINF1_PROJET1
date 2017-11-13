Point bigest_path(Point p,Case map[][H_Map])
{
  tree*tree=initree(p);
  build_tree(map,p,tree);

}

//retroune les coordonée du point a choisir pour l'IA
Point path_IA(Player *player,Case map[][H_Map])
{
  tree *Tree=initree(player->position);
  printf("yolo1\n");
  build_tree(map,player->position,Tree);
  printf("yolo2\n");
  tree *node_exit;
  if(!player->own.key1)
    node_exit=find_exit(Tree,map,3);
  else if(!player->own.key2)
    node_exit=find_exit(Tree,map,2);
  else if(!player->own.key3)
    node_exit=find_exit(Tree,map,1);
  else
    node_exit=find_exit(Tree,map,0);
  if(node_exit==NULL)
    node_exit=initree(player->position);
  printf("sortie de find_exit-> %d,%d\n",node_exit->value.x,node_exit->value.y);
  Point p=find_path(node_exit);
  printf("sortie de find_path-> %d,%d\n",p.x,p.y);
  return p;

}
//parcours l'arbre pour trouver le chemin vers la sortie retourne le noeud contenant les coordonnées de la sortie
tree *find_exit(tree *Tree,Case map[][H_Map],int search)
{
  switch(search)
  {
    case 0:
      if(map[Tree->value.x][Tree->value.y].exit)
      {
	printf("sortie trouvé-> %d,%d search-> %d\n",Tree->value.x,Tree->value.y,search);
	return Tree;
      }
      break;

    case 1:
      if(map[Tree->value.x][Tree->value.y].own.key3)
	return Tree;
      break;

    case 2:
      if(map[Tree->value.x][Tree->value.y].own.key2)
	return Tree;
      break;

    case 3:
      if(map[Tree->value.x][Tree->value.y].own.key1)
	return Tree;
      break;

  }
  if(Tree->left!=NULL)
  {
    tree *a= find_exit(Tree->left,map,search);
    if(a!=NULL)
      return a;
  }
  if(Tree->right!=NULL)
  {
    tree *a=find_exit(Tree->right,map,search);
    if(a!=NULL)
      return a;
  }
  if(Tree->top!=NULL)
  {
     tree *a=find_exit(Tree->top,map,search);
     if(a!=NULL)
       return a;
  }
  if(Tree->bot!=NULL)
  {
    tree *a= find_exit(Tree->bot,map,search);
    if(a!=NULL)
      return a;
  }
  return NULL;
}
//remonte les pere retourne l'avant dernier noueud on se trouvent les coorodonée a prendre pour l'IA
Point find_path(tree *node)
{
  tree *tmpt=node;
  Point p={node->value.x,node->value.y};
  Point tmp={p.x,p.y};
  if(node->dad==NULL)
  {
    printf("ERROR\n");
    return tmpt->value;
  }
  while(tmpt->dad!=NULL)
  {
    tmpt=tmpt->dad;
    p.x=tmp.x;
    p.y=tmp.y;
    tmp.y=tmpt->value.y;
    tmp.x=tmpt->value.x;
    printf("valeur de tmp(find_path)->%d,%d\n",tmpt->value.x,tmpt->value.y);
  }
  return p;
}


void build_tree(Case map[][H_Map],Point p,tree *node)
{

  if(!map[p.x+1][p.y].wall)
  {
    Point tmp={p.x+1,p.y};
    add_right(tmp,node);
    build_tree_rec(map,tmp,node->right);
  }
  if(!map[p.x-1][p.y].wall)
  {
    Point tmp={p.x-1,p.y};
    add_left(tmp,node);
    build_tree_rec(map,tmp,node->left);
  }
  if(!map[p.x][p.y+1].wall)
  {
    Point tmp={p.x,p.y+1};
    add_bot(tmp,node);
    build_tree_rec(map,tmp,node->bot);
  }
  if(!map[p.x][p.y-1].wall)
  {
    Point tmp={p.x,p.y-1};
    add_top(tmp,node);
    build_tree_rec(map,tmp,node->top);
  }

}

void build_tree_rec(Case map[][H_Map], Point p,tree *node)
{
  if(node->dad==NULL)
    return;
  if( !map[p.x+1][p.y].wall && p.x+1!=node->dad->value.x)
  {
    Point tmp={node->value.x+1,node->value.y};
    add_right(tmp,node);
    build_tree_rec(map, tmp,node->right);
  }
  if( !map[p.x-1][p.y].wall && p.x-1!=node->dad->value.x)
  {
    Point tmp={node->value.x-1,node->value.y};
    add_left(tmp,node);
    build_tree_rec(map, tmp,node->left);
  }
  if( !map[p.x][p.y+1].wall && p.y+1!=node->dad->value.y)
  {
    Point tmp={node->value.x,node->value.y+1};
    add_bot(tmp,node);
    build_tree_rec(map, tmp,node->bot);
  }
  if( !map[p.x][p.y-1].wall && p.y-1!=node->dad->value.y)
  {
    Point tmp={node->value.x,node->value.y-1};
    add_top(tmp,node);
    build_tree_rec(map, tmp,node->top);
  }
  return;
}





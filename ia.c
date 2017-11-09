Point bigest_path(Point p,Case map[][H_Map])
{
  tree*tree=initree(p);
  build_tree(map,p,tree);

}

//retroune les coordonée du point a choisir pour l'IA
Point path_IA(Point player,Case map[][H_Map])
{
  tree *Tree=initree(player);
  printf("yolo1\n");
  build_tree(map,player,Tree);
  printf("yolo2\n");
  tree *node_exit=find_exit(Tree,map);
  printf("yolo3\n");
  return find_path(node_exit);

}
//parcours l'arbre pour trouver le chemin vers la sortie retourne le noeud de la sortie
tree *find_exit(tree *Tree,Case map[][H_Map])
{
  if(Tree==NULL)
    return ;
  if(map[Tree->value.x][Tree->value.y].exit)
    return Tree;
  find_exit(Tree->left,map);
  find_exit(Tree->right,map);
  find_exit(Tree->top,map);
  find_exit(Tree->bot,map);

}
//remonte les pere retourne l'avant dernier noueud in se trouvent les coorodonée a prendre pour l'IA
Point find_path(tree *node)
{
  tree *tmp=node;
  if(tmp->dad==NULL)
    return tmp->value;
  while(tmp->dad->dad!=NULL)
    tmp=tmp->dad;
  return tmp->value;
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
  printf("%d,%d \n",node->value.x,node->value.y);
  if(node->dad==NULL)
    return;
  printf("yolo1\n");
  if( !map[p.x+1][p.y].wall && p.x+1!=node->dad->value.x)
  {
    Point tmp={node->value.x+1,node->value.y};
    add_right(tmp,node);
    build_tree_rec(map, tmp,node->right);
  }
  printf("yoloy2\n");
  if( !map[p.x-1][p.y].wall==0 && p.x-1!=node->dad->value.x)
  {
    Point tmp={node->value.x-1,node->value.y};
    add_left(tmp,node);
    build_tree_rec(map, tmp,node->left);
  }
  if( !map[p.x][p.y+1].wall==0 && p.y+1!=node->dad->value.y)
  {
    Point tmp={node->value.x,node->value.y+1};
    add_bot(tmp,node);
    build_tree_rec(map, tmp,node->bot);
  }
  if( !map[p.x][p.y-1].wall==0 && p.y-1!=node->dad->value.y)
  {
    Point tmp={node->value.x,node->value.y-1};
    add_top(tmp,node);
    build_tree_rec(map, tmp,node->top);
  }
  return;
}





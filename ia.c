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


void build_tree(Case map[][H_Map],Point p,tree *tree)
{

  if(!map[p.x+1][p.y].wall)
  {
    Point tmp={p.x+1,p.y};
    add_right(tmp,tree);
    build_tree_rec(map,tmp,tree->right);
  }
  if(!map[p.x-1][p.y].wall)
  {
    Point tmp={p.x-1,p.y};
    add_left(tmp,tree);
    build_tree_rec(map,tmp,tree->left);
  }
  if(!map[p.x][p.y+1].wall)
  {
    Point tmp={p.x,p.y+1};
    add_bot(tmp,tree);
    build_tree_rec(map,tmp,tree->bot);
  }
  if(!map[p.x][p.y-1].wall)
  {
    Point tmp={p.x,p.y-1};
    add_top(tmp,tree);
    build_tree_rec(map,tmp,tree->top);
  }

}

void build_tree_rec(Case map[][H_Map], Point p,tree *tree)
{

  if(tree->dad==NULL)
    return;
  if( !map[p.x+1][p.y].wall && p.x+1!=tree->dad->value.x)
  {
    Point tmp={tree->value.x+1,tree->value.y};
    add_right(tmp,tree);
    build_tree_rec(map, tmp,tree->right);
  }
  if( !map[p.x-1][p.y].wall==0 && p.x-1!=tree->dad->value.x)
  {
    Point tmp={tree->value.x-1,tree->value.y};
    add_left(tmp,tree);
    build_tree_rec(map, tmp,tree->left);
  }
  if( !map[p.x][p.y+1].wall==0 && p.y+1!=tree->dad->value.y)
  {
    Point tmp={tree->value.x,tree->value.y+1};
    add_bot(tmp,tree);
    build_tree_rec(map, tmp,tree->bot);
  }
  if( !map[p.x][p.y-1].wall==0 && p.y-1!=tree->dad->value.y)
  {
    Point tmp={tree->value.x,tree->value.y-1};
    add_top(tmp,tree);
    build_tree_rec(map, tmp,tree->top);
  }
  return;
}





# PROJECT MAZE RUNNER BY ANTOINE AND SIMON

## Niveau intermerdiare terminé (pas édition graphiquement)

## Niveau avancé : 

* ajout d'une fonction sdl perment d'achicher l'image en la redimenssionant

* deplacement progressif du joueur pixel par pixel

* Memorisation des scores via un fichier texte

* Génération aleatoire d'un labyrinthe parfait +page de chargement 

il fonctionne en fusionnant progressivement des chemins depuis une simple cellule jusqu'à l'obtention d'un chemin unique, il suit donc 			une approche 

ascendante.

### mode IA 

ajout d'une IA trouvant le chemin jusqu'aux clés et à la sortie a l'aide d'un arbre à 4 branches 

elle n'est pas sirect car elle peut de facon aleatoire se dirige vers un leure

### mode multijoueur a ne pas tester pour la rendu du code source(probleme d'initilisation via adresse IP)

uniquement montrée lors de la soutenance
	
### non ajouté mais recherche commencé pour les implémenter

* volonté d'ajouter des items(boost,et un item ajoutant un brouillard de guerre)

* fonction pick item et structure deja crée

* ajout du menu option 

* permettant de choisir la difficulté( a l'aide du define dificulté)

* permenttant d'afficher progressivement le labyrinthe au lieu de la page de chargement(simple fonction graphique a appelé)

* permettant la generation labyrinthe parfait ou imparfait aux choix (simple condition if a changer dans break_wall() mais ia ne marcherait plus)
	

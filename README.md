_This project has been created as part of the 42 curriculum by mbuchet._

# Description

ft_printf est une fonction extremement importante pour print des résultats avec des arguments custom facilement, il se base sur la fonction [printf du language C](https://man7.org/linux/man-pages/man3/printf.3.html)

# Instructions

Pour compiler le projet il suffit d'éxecuter `make` dans la console dans le dossier root et le fichier attendu nommé `libftprintf.a` sera créée.
Avant chaque nouvelle compilation, n'oubliez pas d'exécuter `make fclean` pour supprimer les fichiers indésirables de l'ancienne compilation.
Tester et compiler sur un environnement Ubuntu.

# Resources

ft_printf: La fonction permettant de pouvoir print dans la console un texte contenant des arguments (par exemple %s pour les strings, %d pour les int).
print_digits: des fonctions utilitaires pour gérer tout ce qui touche aux nombres (nombre signé, nombre unsigné et hexadecimal).
print_pointer: une fonction utilitaire pour print un pointeur d'une variable.
print_str: des fonctions utilitaires pour gérer tout ce qui touche aux strings (un caractère et une chaine de caractères).

## Structure du projet
Une reproduction simpliste du printf de C, le fichier principale comprend 2 fonctions simples dans le projet, `ft_printf` et `handle_specifier`, printf accepte les paramètres et je boucle sur le string et je regarde ensuite si le caractère à l'index actuelle est un pourcentage et ensuite si le prochain caractère existe, si c'est le cas je rentre dans la nouvelle fonction nommée handle_specifier qui trie les différents flag et permet de traiter chaque flag différemment, chacune des fonctions call dans la fonction handle_specifier sont séparées sur plusieurs fichiers pour mieux organiser le projet si besoin plus tard de faire des ajouts de flag, les fonctions sont inspirées de la Libft mais refais pour le projet pour s'adapter au besoin, toutes les fonctions externes du fichier principale comprennent un pointeur `size_t` de `str_length` c'est la variable qui doit etre modifier à chaque écrite dans la console pour comptabiliser le nombre de caractères au total à la toute fin de la fonction.

## Références
- Sujet du PDF, version 12.1, ft_printf de 42 Bruxelles.
- 2/3 anciennes bases de code de ma Libft.
- Explication de l'utilisation de [uintptr_t](https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type)

## Utulisation de l'IA
Usage de l'IA vers la toute fin comme "professeur" pour régler quelques problèmes connes de ma part pour l'hexadecimal, en demandant toujours de ne jamais donner de code et de résolution mais avec des explications/indices pour m'y guider, les prompts sont généralement sur les modèles free de GPT Copilot Pro.

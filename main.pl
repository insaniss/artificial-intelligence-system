spouse("Alberto Mayes", "Doris Diaz").
spouse("Richard Mayes", "Helen Davis").
spouse("Aaron Mayes", "Louise Carr").
spouse("John Mayes", "Ethel Hurt").
spouse("Jose Hawkins", "Karen Mayes").

parent("Alberto Mayes", "Richard Mayes").
parent("Alberto Mayes", "Donna Mayes").
parent("Alberto Mayes", "Aaron Mayes").
parent("Doris Diaz", "Richard Mayes").
parent("Doris Diaz", "Donna Mayes").
parent("Doris Diaz", "Aaron Mayes").
parent("Richard Mayes", "John Mayes").
parent("Richard Mayes", "Scott Mayes").
parent("Richard Mayes", "Amber Meyes").
parent("Helen Davis", "John Mayes").
parent("Helen Davis", "Scott Mayes").
parent("Helen Davis", "Amber Meyes").
parent("Aaron Mayes", "Karen Mayes").
parent("Louise Carr", "Karen Mayes").
parent("John Mayes", "Ruth Mayes").
parent("Ethel Hurt", "Ruth Mayes").
parent("Jose Hawkins", "Emily Hawkins").
parent("Karen Mayes", "Emily Hawkins").

male("Alberto Mayes").
male("Richard Mayes").
male("Aaron Mayes").
male("John Mayes").
male("Scott Mayes").
male("Jose Hawkins").

female("Doris Diaz").
female("Helen Davis").
female("Donna Mayes").
female("Louise Carr").
female("Ethel Hurt").
female("Amber Meyes").
female("Karen Mayes").
female("Ruth Mayes").
female("Emily Hawkins").

son(X, Y) 				:- parent(Y, X), male(X).
daughter(X, Y) 			:- parent(Y, X), female(X).

father(X, Y) 			:- parent(X, Y), male(X).
mother(X, Y) 			:- parent(X, Y), female(X).

grandfather(X, Z)		:- father(X, Y), father(Y, Z); father(X, Y), mother(Y, Z).
grandmother(X, Z)		:- mother(X, Y), father(Y, Z); mother(X, Y), mother(Y, Z).

greatgrandfather(X, Z)	:- grandfather(X, Y), father(Y, Z); grandfather(X, Y), mother(Y, Z).
greatgrandmother(X, Z) 	:- grandmother(X, Y), father(Y, Z); grandmother(X, Y), mother(Y, Z).

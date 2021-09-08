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

son(A, B)               :- parent(B, A), male(A).
daughter(A, B)          :- parent(B, A), female(A).

father(A, B)            :- parent(A, B), male(A).
mother(A, B)            :- parent(A, B), female(A).

grandfather(A, C)       :- father(A, B), father(B, C); father(A, B), mother(B, C).
grandmother(A, C)       :- mother(A, B), father(B, C); mother(A, B), mother(B, C).

greatgrandfather(A, C)  :- grandfather(A, B), father(B, C); grandfather(A, B), mother(B, C).
greatgrandmother(A, C)  :- grandmother(A, B), father(B, C); grandmother(A, B), mother(B, C).

sibling(A, B)           :- parent(C, A), parent(C, B), A \= B.

brother(A, B)           :- sibling(A, B), male(A).
sister(A, B)            :- sibling(A, B), female(A).

uncle(A, C)             :- brother(A, B), parent(B, C).
aunt(A, C)              :- sister(A, B), parent(B, C).

cousin(A, B)            :- parent(C, A), uncle(C, B); parent(C, A), aunt(C, B).
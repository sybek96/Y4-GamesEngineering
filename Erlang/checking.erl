-module(checking).
-export([main/0]).

main() ->
    P1 = {person,{height,10},{gender, male}, {name, "John"}, {achievements, {quest1, {a1, "1"}}}},
    P2 = {person,{height,10},{gender, male}, {name, "Jane"}, {achievements, {quest1, {a1, "1"}}}},
    element(5, P1) == element(5, P2).
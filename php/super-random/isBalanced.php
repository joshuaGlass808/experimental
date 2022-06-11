<?php

function isBalanced(array $balance, string $isBalStr): bool
{
    if (empty($balance)) return true;

    $balArr = [];
    foreach (str_split($isBalStr) as $i => $c) {
        if (isset($balance[$c]) || in_array($c, $balance)) {
           foreach ($balance as $k => $b) {
               if ($k === $c) {
                   $balArr[] = $c;
               }

               if ($b === $c && $balArr[count($balArr) - 1] === $k) {
                   array_pop($balArr);
               }
           }
        }
    }

    return empty($balArr);
}

echo (isBalanced(['{' => '}'], 'hell{world}kdkd') ? 'True' : 'False') . "\n";
echo (isBalanced(['{' =>'}', '[' => ']'], 'hello{world[{}]}dkdk') ? 'True' : 'False') . "\n";
echo (isBalanced(['{' =>'}', '[' => ']'], 'hello[{world[{}]}dkdk') ? 'True' : 'False') . "\n";

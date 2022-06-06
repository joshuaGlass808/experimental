<?php

binToInt('1011');
binToInt('0011');
binToInt('0001');
binToInt('1001');
binToInt('0000');

/**
 * Turns a cleaned binary string ie (1001) and returns and int value.
 * 
 * @param string $bin - cleaned binary string (1101)
 * 
 * @return int - total value
 */
function binToInt(string $bin): int {
    $total = 0;
    foreach (str_split($bin) as $idx => $val) {
        $total += ($val) ? pow(2, strlen($bin) - ($idx+1)) : 0;
    }

    return $total;
}

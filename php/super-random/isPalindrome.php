<?php

function isPalindrome(string $str): bool
{
    return ($str === strrev($str));
}

echo isPalindrome('a') . "\n";
echo isPalindrome('ab') . "\n";
echo isPalindrome('aba') . "\n";
echo isPalindrome('abab') . "\n";
echo isPalindrome('aaaaabaaaaa') . "\n";

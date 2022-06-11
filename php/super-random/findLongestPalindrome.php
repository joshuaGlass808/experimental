<?php

function findLargestPalindrome(string $str): string
{
    if (strlen($str) === 1) {
        return $str;
    }

    $pal = '';
    $pLen = 0;
    $strArr = str_split($str);
    foreach ($strArr as $i => $char) {
        $tempStr = $char;

        foreach ($strArr as $k => $sChar) {
           if ($i === $k) {
               if ($pLen === 0) {
                   $pLen = 1;
                   $pal = $char;
               }
               continue;
           }
           $tempStr .= $sChar;
           if (strlen($tempStr) <= $pLen) {
               continue;
           }
  
           if ($tempStr === strrev($tempStr)) {
               $pLen = strlen($tempStr);
               $pal = $tempStr;
           }
        }
        unset($strArr[$i]);
    }

    return $pal;
}

echo findLargestPalindrome('aab') . "\n";
echo findLargestPalindrome('aabaabaaaaa') . "\n";
